#pragma once

#include <cstddef>
#include <string>

namespace mystd
{

template<typename T>
class my_vector
{
public:
    my_vector()
    {
     //   std::cout << "my_vector ctr" << std::endl;
       data_ = new T[10];
    }
    ~my_vector()
    {
        delete[] data_;
    }

    void push_back(const T& value);
    const T& operator[](size_t i) const { return data_[i]; }
    T& pop_back();
private:
    T* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};

/*
template class my_vector<std::string>;
template class my_vector<double>;
template class my_vector<int64_t>;
*/


} // namespace mystd

#include "vector.tpp"
