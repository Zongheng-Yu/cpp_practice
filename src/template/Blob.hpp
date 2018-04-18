#pragma once
#include <vector>
#include <string>

template <typename T>
class Blob {
    public:
        typedef T value_type;
        typedef typename std::vector<T>::size_type size_type;
        Blob();
        Blob(std::initializer_list<T> il);
        void Blob(const Blob&) = default;
        void operator=(Blob&) = default;
        Blob(const Blob&&) = default;
        void operator=(Blob&&) = default;
        size_type size() const {data->size();};
        bool empty() const {return date->empty();}
        void push_back(T& t) {date->push_back(t);}
        void push_back(T&& t) {data->push_back(std::move(t));}
        void pop_back();
        T& back();
        T& operator[](size_type i);
    private:
        void check(size_type i, const std::string& msg) const;
        std::share_pointer<std::vector<T>> data;
};
