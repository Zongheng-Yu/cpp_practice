//
// Created by zonyu on 2019/11/8.
//

#pragma once

#include <vector>

namespace merge_sort
{
template <typename T> void merge(std::vector<T>& arr, const std::size_t start, const std::size_t middle, const std::size_t end)
{
    auto left = start;
    auto right = middle;
    std::vector<T> result;
    while (left < middle && right < end)
    {
        if (arr[left] > arr[right])
        {
            result.emplace_back(std::move(arr[right]));
            right++;
        } else
        {
            result.emplace_back(std::move(arr[left]));
            left++;
        }
    }
    while (left < middle)
    {
        result.emplace_back(std::move(arr[left]));
        left++;
    }
    while (right < middle)
    {
        result.emplace_back(std::move(arr[right]));
        right++;
    }
    left = start;
    for (auto item: result)
    {
        arr[left++] = std::move(item);
    }
}

template <typename T> void sort(std::vector<T>& arr, const std::size_t start, const std::size_t end)
{
    if (start + 1 == end)
    {
        if (arr[start] > arr[end])
        {
            std::swap(arr[start], arr[end]);
        }
        return;
    }
    sort(arr, start, (start + end)/2);
    sort(arr, (start + end)/2, end);
    merge(arr, start, (start + end)/2, end);
}

template <typename T> void sort(std::vector<T>& arr)
{
    sort(arr, 0, arr.size());
}
}