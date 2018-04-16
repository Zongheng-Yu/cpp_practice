#ifndef COMPARE_HPP
#define COMPARE_HPP
#include <string.h>
#include <string>
#include <iostream>

template <typename T>
int compare(const T& a, const T& b)
{
    std::cout << "compare version 1 called" << std::endl;
//    if (a > b) {
//        return 1;
//    }
//    if (b > a) {
//        return -1;
//    }
    if (std::less<T>()(a, b)) {
        return -1;
    }
    if (std::less<T>()(b, a)) {
        return 1;
    }
    return 0;
}

template <size_t N, size_t M>
int compare(const char (&str1)[N], const char (&str2)[M])
{
    std::cout << "compare version 2 called" << std::endl;
    return strcmp(str1, str2);
}

#endif
