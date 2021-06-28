#pragma once

#include <condition_variable>
#include <mutex>

#include "interfaces/IScenarioQueue.hpp"

namespace cpnrt
{
class ScenarioQueue final : public IScenarioQueue
{
public:
    using ScenarioSet = scenario::ScenarioSet;
    explicit ScenarioQueue(uint32_t queueSize);
    void pushScenario(scenario::ScenarioPtr scenario) override;
    void pushScenarioToFront(scenario::ScenarioPtr scenario) override;
    void pushScenarios(ScenarioSet& scenarios) override;
    ScenarioSet popScenarios(const std::chrono::milliseconds& waitTime) override;

private:
    const size_t queueSize{10000};
    ScenarioSet scenarioSet;
    std::mutex mutex;
    std::condition_variable pusher;
    std::condition_variable puller;
};

} // namespace cpnrt
