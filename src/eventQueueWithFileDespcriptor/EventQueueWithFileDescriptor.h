#pragma once
#include <sys/eventfd.h>
#include <boost/throw_exception.hpp>
#include <gsl/gsl_assert>
#include <mutex>
#include <queue>
#include <stdexcept>
#include "event/IEventQueueWithFileDescriptor.hpp"

namespace event
{
    template <typename Event>
    class EventQueueWithFileDescriptor : public IEventQueueWithFileDescriptor<Event>
    {
    public:
        EventQueueWithFileDescriptor() { Ensures(fileDescriptor >= 0); }

        EventQueueWithFileDescriptor(const EventQueueWithFileDescriptor&) = delete;
        void operator=(const EventQueueWithFileDescriptor&) = delete;
        EventQueueWithFileDescriptor(EventQueueWithFileDescriptor&&) = delete;
        void operator=(EventQueueWithFileDescriptor&&) = delete;

        ~EventQueueWithFileDescriptor() override { close(fileDescriptor); }

        void push(Event event) override
        {
            std::lock_guard<std::mutex> guard(mutex);
            queue.push(std::move(event));
            Ensures(write(fileDescriptor, &numberOfNewEvents, sizeof(numberOfNewEvents)) == sizeof(numberOfNewEvents));
        }

        Event pull() override
        {
            std::unique_lock<std::mutex> guard(mutex);

            std::uint64_t eventCounter = 0;
            const auto readBytes = read(fileDescriptor, &eventCounter, sizeof(eventCounter));
            if (eventCounter != 1 or readBytes == 0)
            {
                BOOST_THROW_EXCEPTION(std::runtime_error("Trying to read from empty event queue"));
            }

            auto event = std::move(queue.front());
            queue.pop();
            return event;
        }

        std::size_t size() const override
        {
            std::lock_guard<std::mutex> guard(mutex);
            return queue.size();
        }

        bool empty() const override { return size() == 0; }

        int getFileDescriptor() const override { return fileDescriptor; }

    private:
        const int fileDescriptor{eventfd(0, EFD_SEMAPHORE | EFD_NONBLOCK)};
        std::queue<Event> queue;
        mutable std::mutex mutex;
        const std::uint64_t numberOfNewEvents{1};
    };
} // namespace event
