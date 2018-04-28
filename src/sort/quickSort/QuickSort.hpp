#pragma once
#include <vector>
#include <iostream>
#include <utility>

namespace quickSort
{

namespace
{

template <typename T>
int partition4(std::vector<T>& input, int begin, int end)
{
    auto key = begin;
    auto left = begin, right = end;
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
int partition3(std::vector<T>& input, int begin, int end)
{
    auto key = begin;
    auto mid = begin;
    while (mid+1 <= end && input[mid+1] <= input[key])
    {
        ++mid;
    }
    for (auto i = mid + 1; i <= end; ++i)
    {
        if (input[i] <= input[key])
        {
            ++mid;
            std::swap(input[mid], input[i]);
        }
    }
    std::swap(input[begin], input[mid]);
    return mid;
}

template <typename T>
int partition2(std::vector<T>& input, int begin, int end)
{
    auto key = begin;
    auto mid = begin;
    for (auto i = mid + 1; i <= end; ++i)
    {
        if (input[i] <= input[key])
        {
            ++mid;
            std::swap(input[mid], input[i]);
        }
    }
    std::swap(input[key], input[mid]);

    return mid;
}

template <typename T>
int partition(std::vector<T>& input, int begin, int end)
{
    auto key = end;//key must be end
    auto mid = begin - 1;
    for (auto i = begin; i <= end; ++i)
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

//quick sort for [begin, end] or [begin, end+1)
template <typename T>
void quickSort(std::vector<T>& input, int begin, int end)
{
    std::cout << "begin: " << begin << " end:" << end << std::endl;
    for (auto &element: input)
    {
        std::cout << " " << element;
    }
    std::cout << std::endl;
    if (begin >= end)
    {
        return;
    }
    auto mid = partition(input, begin, end);
    quickSort(input, begin, mid - 1);
    quickSort(input, mid + 1, end);
}

template <typename T>
void quickSort(std::vector<T>& input)
{
    quickSort(input, 0, input.size() - 1);
}

}

