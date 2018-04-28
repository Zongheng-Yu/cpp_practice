/*
 * BlobPtr.hpp
 *
 *  Created on: 2018?4?22?
 *      Author: zonyu
 */

#pragma once
#include <memory>
#include <vector>

template <typename> class Blob;

template <typename T> class BlobPtr
{
    public:
        BlobPtr(): curr(0){}
        BlobPtr(Blob<T>& a, size_t sz = 0): wptr(a.data), curr(sz){}
        T& operator*() const
        {
            auto p = check(curr, "dereference past end");
            return (*p)[curr];
        }
        BlobPtr& operator++();
        BlobPtr& operator--();
        BlobPtr& operator++(int);
    private:
        std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
        std::weak_ptr<std::vector<T>> wptr;
        std::size_t curr = 0;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++()
{
    ++*this;
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}
