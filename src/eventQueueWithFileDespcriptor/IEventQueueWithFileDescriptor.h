#pragma once
#include <cstddef>

namespace event
{
    template <typename Event>
    class IEventQueueWithFileDescriptor
    {
    public:
        IEventQueueWithFileDescriptor() = default;
        virtual ~IEventQueueWithFileDescriptor() = default;

        virtual void push(Event) = 0;
        virtual Event pull() = 0;
        virtual std::size_t size() const = 0;
        virtual bool empty() const = 0;
        virtual int getFileDescriptor() const = 0;
    };
} // namespace event
