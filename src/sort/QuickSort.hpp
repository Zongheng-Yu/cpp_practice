#pragma once
#include <vector>
#include <iostream>
#include <utility>

namespace quickSort
{

namespace
{

template <typename T>
int partition2(std::vector<T>& input, int begin, int end)
{
    auto key = begin;
    auto left = begin, right = end - 1;
    while (left < right)
    {
        while(left < right && input[right] >= input[key])
        {
            --right;
        }
        while(left < right&& input[left] <= input[key])
        {
            ++left;
        }
        std::swap(input[left], input[right]);
    }
    std::swap(input[key], input[right]);
    return right;
}

template <typename T>
int partition(std::vector<T>& input, int begin, int end)
{
    auto key = end - 1;//key must be end
    auto mid = begin - 1;
    for (auto i = begin; i < end; ++i)
    {
        if (input[i] <= input[key])
        {
            ++mid;
            std::swap(input[mid], input[i]);
        }
    }
    return mid;
}
}

//quick sort for [begin, end+1)
template <typename T>
void quickSort(std::vector<T>& input, int begin, int end)
{
    if (begin + 1 >= end)
    {
        return;
    }
    auto mid = partition(input, begin, end);
    quickSort(input, begin, mid);
    quickSort(input, mid + 1, end);
}

template <typename T>
void quickSort(std::vector<T>& input)
{
    quickSort(input, 0, input.size());
}

}

