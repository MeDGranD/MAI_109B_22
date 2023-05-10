#include "../include/Vector.hpp"
#include <memory>
template<typename T>
Vector<T>::Vector()
{
    arr = reinterpret_cast<T *>(new int8_t[sizeof(T)]);
    sz = 0;
    cap = 1;
}
template<typename T>
Vector<T>::Vector(const Vector<T> &copyd)
{
    sz = copyd.sz;
    cap = copyd.cap;
    T *new_arr = reinterpret_cast<T *>(new int8_t[cap * sizeof(T)]);

    try {
        std::uninitialized_copy(copyd.arr, copyd.arr + copyd.sz, new_arr);
    }
    catch (...) {
        delete[] reinterpret_cast<char *>(new_arr);
        throw;
    }
    arr = new_arr;
}
template<typename T>
Vector<T>::Vector(std::initializer_list<T> init)
{
    T *new_arr = reinterpret_cast<T *>(new int8_t[init.size() * sizeof(T)]);

    try {
        std::uninitialized_copy(init.begin(), init.end(), new_arr);
    }
    catch (...) {
        delete[] reinterpret_cast<char *>(new_arr);
        throw;
    }
    arr = new_arr;
    cap = init.size();
    sz = init.size();
}
template<typename T>
void Vector<T>::reserve(size_t n)
{
    if (n > UINT_MAX) {
        throw std::range_error("capacity overflow");
    }
    if (n < cap)
        return;
    T *new_arr = reinterpret_cast<T *>(new int8_t[n * sizeof(T)]);
    try {
        std::uninitialized_copy(arr, arr + sz, new_arr);
    }
    catch (...) {
        delete[] reinterpret_cast<char *>(new_arr);
        throw;
    }
    for (size_t i = 0; i < sz; ++i) {
        arr[i].~T();
    }
    delete[] reinterpret_cast<char *>(arr);
    arr = new_arr;
    cap = n;
}
template<typename T>
void Vector<T>::resize(size_t n, const T &value)
{
    if (n > UINT_MAX) {
        throw std::range_error("capacity overflow");
    }
    if (n > cap) {

        reserve(n);
    }

    if (n < sz) {
        for (size_t i = n; i < sz; ++i) {
            arr[i].~T();
        }
    }
    if (n > sz) {
        for (size_t i = sz; i < n; ++i) {
            new (arr + i) T(value);
        }
    }
    for (size_t i = 0; i < sz; ++i) {
        arr[i] = T(value);
    }
    sz = n;
}
template<typename T>
void Vector<T>::push_back(const T &value)
{

    if (cap == sz) {
        if (cap * 2 < cap) {
            throw std::range_error("capacity overflow");
        }
        reserve(2 * cap);
    }
    new (arr + sz) T(value);
    ++sz;
}
template<typename T>
void Vector<T>::emplace_back(){}
template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(const T &First, const Args &...args)
{

    push_back(First);
    emplace_back(args...);
    return;
}
template<typename T>
void Vector<T>::pop_back()
{

    if (sz > 0) {
        --sz;
        arr[sz].~T();
    }
    else {
        return;
    }
}
template<typename T>
Vector<T>::~Vector()
{
    for (size_t i = 0; i < sz; ++i) {
        arr[i].~T();
    }
    delete[] reinterpret_cast<char *>(arr);
    sz = 0;
    cap = 0;
}
template<typename T>
T &Vector<T>::at(size_t pos)
{

    if (pos < sz) {
        return arr[pos];
    }
    else {
        throw std::out_of_range("The requested position is outside the vector");
    }
}
template<typename T>
T &Vector<T>::front()
{
    return arr[0];
}
template<typename T>
T &Vector<T>::back()
{
    return arr[sz - 1];
}
template<typename T>
bool Vector<T>::empty()
{
    return sz == 0;
}
template<typename T>
size_t Vector<T>::size() const
{
    return sz;
}
template<typename T>
size_t Vector<T>::capacity() const
{
    return cap;
}
template<typename T>
void Vector<T>::clear()
{

    for (size_t i = 0; i < sz; ++i) {
        arr[i].~T();
    }
    sz = 0;
}
template<typename T>
void Vector<T>::shrink_to_fit()
{

    for (size_t i = sz; i < cap; ++i) {
        arr[i].~T();
    }
    cap = sz;
    if (!cap) {
        cap = 1;
    }
}
template<typename T>
T &Vector<T>::operator[](size_t pos)
{
    return arr[pos];
}
template<typename T>
bool Vector<T>::operator==(Vector<T> &b)
{

    if (sz != b.sz) {
        return false;
    }
    for (size_t i = 0; i < sz; ++i) {
        if (this->arr[i] != b.arr[i]) {
            return false;
        }
    }
    return true;
}
template<typename T>
bool Vector<T>::operator!=(Vector<T> &b)
{

    if (sz != b.sz) {
        return true;
    }
    for (size_t i = 0; i < sz; ++i) {
        if (this->arr[i] != b.arr[i]) {
            return true;
        }
    }
    return false;
}
