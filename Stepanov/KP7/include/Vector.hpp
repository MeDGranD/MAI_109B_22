#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include <iostream>
template<typename T>
class Vector
{
    T *arr;
    size_t sz;
    size_t cap;

public:
    Vector();
    Vector(const Vector &copyd);
    Vector(std::initializer_list<T> init);
    void reserve(size_t n);
    void resize(size_t n, const T &value = T());
    void push_back(const T &value);
    template<typename... Args>
    void emplace_back(const T &First, const Args &...args);
    void emplace_back();
    void pop_back();
    T &at(size_t pos);
    T &front();
    T &back();
    bool empty();
    size_t size() const;
    size_t capacity() const;
    void shrink_to_fit();
    void clear();
    T &operator[](size_t pos);
    bool operator==(Vector &b);
    bool operator!=(Vector &b);
    ~Vector();
};
#include "../src/Vector.cpp"

#endif// VECTOR_HPP_INCLUDED
