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
        BlobPtr(const BlobPtr&) = delete;
    private:
        std::weak_ptr<std::vector<T>> wptr;
        std::size_t curr = 0;
};
