/*
 * SortableClass.hpp
 *
 *  Created on: 2018?4?27?
 *      Author: zonyu
 */

#pragma once

class SortableClass
{
    friend inline bool operator< (const SortableClass& a, const SortableClass& b);
    friend inline bool operator<= (const SortableClass& a, const SortableClass& b);
    friend inline bool operator> (const SortableClass& a, const SortableClass& b);
    friend inline bool operator>= (const SortableClass& a, const SortableClass& b);
    friend inline bool operator== (const SortableClass& a, const SortableClass& b);
    friend inline bool operator!= (const SortableClass& a, const SortableClass& b);
    friend inline std::ostream& operator<< (std::ostream& stream, const SortableClass& a);
    public:
        explicit SortableClass(int key): key(key){};
        SortableClass() = delete;
        SortableClass(const SortableClass& a) = default;
        SortableClass& operator=(const SortableClass& a) = delete;
        SortableClass(SortableClass&& a) = default;
        SortableClass& operator=(SortableClass&& a) = default;
        ~SortableClass() {}
    private:
        int key = 0;
};

inline bool operator< (const SortableClass& a, const SortableClass& b)
{
    return a.key < b.key;
}

inline bool operator<= (const SortableClass& a, const SortableClass& b)
{
    return a.key <= b.key;
}

inline bool operator> (const SortableClass& a, const SortableClass& b)
{
    return a.key > b.key;
}

inline bool operator>= (const SortableClass& a, const SortableClass& b)
{
    return a.key >= b.key;
}

inline bool operator== (const SortableClass& a, const SortableClass& b)
{
    return a.key == b.key;
}

inline bool operator!= (const SortableClass& a, const SortableClass& b)
{
    return a.key != b.key;
}

inline std::ostream& operator<< (std::ostream& stream, const SortableClass& a)
{
    return stream << a.key;
}
