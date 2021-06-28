//
// Created by zonyu on 2019/10/8.
//

#pragma once
#include <vector>
#include <algorithm>
#include <utility>

namespace bubble_sort
{
template <typename T>
void sort(std::vector<T>& input)
{
    //do for size - 1 times
    for (std::size_t n = 0; n + 1 < input.size(); n++)
    {
        //start from the front, switch elements if the previous one is bigger than the later one, until size - 1 - n
        for (std::size_t m = 0; m + n + 1 < input.size(); m++)
        {
            if (input.at(m) > input.at(m+1))
            {
                std::swap(input.at(m), input.at(m+1));
            }
        }
    }
}
}
