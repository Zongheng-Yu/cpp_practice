#pragma once
#include <vector>
#include "QuickSort.hpp"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

template <typename T>
void sort(std::vector<T>& input)
{
    quickSort::quickSort(input);
//    bubble_sort::sort(input);
//    heat_sort::sort(input);
//    merge_sort::sort(input);
}
