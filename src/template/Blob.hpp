#pragma once
#include <vector>
#include <string>
#include <memory>


template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    public:
        typedef T value_type;
        typedef typename std::vector<T>::size_type size_type;
        Blob();
        Blob(std::initializer_list<T> il);
        Blob(const Blob&) = default;
        Blob& operator=(const Blob&) = default;
        Blob(Blob&&) = default;
        Blob& operator=(Blob&&) = default;
        size_type size() const {return data->size();}
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

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): data{std::make_shared<std::vector<T>>(il)}
{
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "Empty, nothing to pop");
    data->pop_back();
}

template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
    if (i + 1 > data->size())
    {
        throw std::out_of_range(msg);
    }
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on Empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    return (*data)[i];
}
