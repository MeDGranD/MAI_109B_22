#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

template<typename T>
class Vector{
public:
    Vector();
    Vector(const size_t, const T& = T());
    Vector(const Vector<T>&);
    Vector(const std::initializer_list<T>&);
    Vector<T>& operator=(const Vector<T>&);

    void reserve(const size_t);
    void resize(const size_t, const T& = T());

    void push_back(const T&);
    template<typename ...Args>
    void emplace_back(const Args&...);
    void pop_back();

    T& at(const size_t) const;
    T& operator[](const size_t) const;

    T& front() const;
    T& back() const;
    bool empty() const;
    size_t size() const;
    size_t capacity() const;

    void shrink_to_fit();
    void clear();

    bool operator==(const Vector<T>&) const;
    bool operator!=(const Vector<T>&) const;

    ~Vector();
private:
    size_t arraySize;
    size_t arrayCapacity;
    T* Array;
};

#include "../src/Vector.cpp"

#endif