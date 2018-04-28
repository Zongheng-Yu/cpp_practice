#pragma once
#include <vector>
#include "quickSort/QuickSort.hpp"

template <typename T>
void sort(std::vector<T>& input)
{
    quickSort::quickSort(input);
}
