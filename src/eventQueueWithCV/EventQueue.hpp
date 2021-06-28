#pragma once
#include <boost/variant.hpp>
#include <condition_variable>
#include <mutex>
#include <queue>
// CPD-OFF
/*perfect class copied from 5G cplane*/
template <typename Event>
class EventQueue
{
public:
    using ClientEventType = Event;
    struct StopQueueEvent
    {
    };
    using QueueEventType = boost::variant<StopQueueEvent, ClientEventType>;

    virtual void push(Event event) { pushImpl(event); }

    virtual void stop() { pushImpl(StopQueueEvent{}); }

    virtual QueueEventType retrieve()
    {
        std::unique_lock<std::mutex> guard(mutex);
        cv.wait(guard, [this] { return not queue.empty(); });
        auto event = std::move(queue.front());
        queue.pop();
        return event;
    }

    virtual std::size_t size() const
    {
        std::lock_guard<std::mutex> guard(mutex);
        return queue.size();
    }

    virtual bool empty() const { return size() == 0; }

    virtual ~EventQueue() = default;

private:
    virtual void pushImpl(QueueEventType event)
    {
        {
            std::lock_guard<std::mutex> guard(mutex);
            queue.push(std::move(event));
        }
        cv.notify_one();
    }

    std::queue<QueueEventType> queue;
    mutable std::mutex mutex;
    std::condition_variable cv;
};
// CPD-ON