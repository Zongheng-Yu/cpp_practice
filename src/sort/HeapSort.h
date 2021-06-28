//
// Created by zonyu on 2019/10/9.
//

#pragma once

#include <vector>

namespace heat_sort
{
template <typename T>
class Heap
{
public:
    void insert(T&&);
    T pop();
    std::size_t size();

private:
    static std::size_t parent(std::size_t index) { return (index + 1)/2 - 1;}
    static std::size_t left_child(std::size_t index) { return index * 2 + 1;}
    static std::size_t right_child(std::size_t index) { return index * 2 + 2;}
    void bubble_up(std::size_t index);
    void bubble_down(std::size_t index);

private:
    std::vector<T> data;
};

template <typename T> inline std::size_t Heap<T>::size()
{
    return this->data.size();
}

template <typename T> inline T Heap<T>::pop()
{
    T tmp = std::move(this->data[0]);
    if (this->data.size() > 1)
    {
        this->data[0] = std::move(this->data.back());
    }
    this->data.pop_back();
    this->bubble_down(0);
    return std::move(tmp);
}

template <typename T> void Heap<T>::bubble_up(std::size_t index)
{
    if (index > 0)
    {
        auto parent = this->parent(index);
        if (this->data[index] < this->data[parent])
        {
            std::swap(this->data.at(index), this->data.at(this->parent(index)));
            this->bubble_up(this->parent(index));
        }
    }
}

template <typename T> void Heap<T>::bubble_down(std::size_t index)
{
    auto min = index;
    auto left_child = this->left_child(index);
    auto right_child = this->right_child(index);
    if (left_child < this->data.size() && this->data[left_child] < this->data[min])
    {
        min = left_child;
    }
    if (right_child < this->data.size() && this->data[right_child] < this->data[min])
    {
        min = right_child;
    }
    if (min != index)
    {
        std::swap(this->data[index], this->data[min]);
        this->bubble_down(min);
    }
}

template <typename T> void Heap<T>::insert(T && element)
{
    this->data.emplace_back(element);
    this->bubble_up(this->data.size() - 1);
}

template <typename T>
void sort(std::vector<T>& input)
{
    Heap<T> heap;
    for (auto each: input)
    {
        heap.insert(std::move(each));
    }
    input.clear();
    while (heap.size() > 0)
    {
        input.push_back(std::move(heap.pop()));
    }
}

}
