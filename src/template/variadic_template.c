//
// Created by zonyu on 2020/6/19.
//

#include <iostream>

template <typename Head, typename ...TypePack>
void print(Head head, TypePack ... args)
{
    std::cout << sizeof...(args);
}