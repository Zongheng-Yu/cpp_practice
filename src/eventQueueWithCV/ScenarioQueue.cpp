#include "scenarioQueue/ScenarioQueue.hpp"
#include <queue>

namespace cpnrt
{
ScenarioQueue::ScenarioQueue(uint32_t queueSize) : queueSize(queueSize)
{
    scenarioSet.reserve(queueSize);
}

void ScenarioQueue::pushScenario(scenario::ScenarioPtr scenario)
{
    {
        std::unique_lock<std::mutex> lock(mutex);
        pusher.wait(lock, [&] { return scenarioSet.size() < queueSize; });
        scenarioSet.emplace_back(std::move(scenario));
    }
    puller.notify_one();
}

void ScenarioQueue::pushScenarioToFront(scenario::ScenarioPtr scenario)
{
    {
        std::unique_lock<std::mutex> lock(mutex);
        pusher.wait(lock, [&] { return scenarioSet.size() < queueSize; });
        scenarioSet.emplace(scenarioSet.begin(), std::move(scenario));
    }
    puller.notify_one();
}

void ScenarioQueue::pushScenarios(ScenarioSet& scenarios)
{
    {
        std::unique_lock<std::mutex> lock(mutex);
        pusher.wait(lock, [&] { return scenarioSet.size() + scenarios.size() <= queueSize; });
        scenarioSet.insert(
            scenarioSet.end(), std::make_move_iterator(scenarios.begin()), std::make_move_iterator(scenarios.end()));
    }
    puller.notify_one();
}

ScenarioQueue::ScenarioSet ScenarioQueue::popScenarios(const std::chrono::milliseconds& waitTime)
{
    ScenarioSet tmpQueue;
    {
        std::unique_lock<std::mutex> lock(mutex);
        puller.wait_for(lock, waitTime, [&] { return not scenarioSet.empty(); });
        std::swap(scenarioSet, tmpQueue);
    }
    pusher.notify_one();
    return tmpQueue;
}

} // namespace cpnrt
