#pragma once
#include <vector>
#include <string>
#include <memory>

template <typename T>
class Blob {
    public:
        typedef T value_type;
        typedef typename std::vector<T>::size_type size_type;
        Blob();
        Blob(std::initializer_list<T> il);
        Blob(const Blob&) = default;
        Blob& operator=(Blob&) = default;
        Blob(Blob&&) = default;
        Blob& operator=(Blob&&) = default;
        size_type size() const {data->size();};
        bool empty() const {return data->empty();}
        void push_back(T& t) {data->push_back(t);}
        void push_back(T&& t) {data->push_back(std::move(t));}
        void pop_back();
        T& back();
        T& operator[](size_type i);
    private:
        void check(size_type i, const std::string& msg) const;
        std::shared_ptr<std::vector<T>> data;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>())
{
}
