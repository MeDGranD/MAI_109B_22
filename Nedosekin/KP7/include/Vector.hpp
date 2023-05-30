#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../include/Allocator.hpp"
#include <iostream>
#include <limits>

template<class T, class A = Allocator<T>>
class Vector
{
public:
    Vector();
    Vector(size_t size, const T &value = T());
    Vector(const Vector &other);
    Vector(Vector &&other) noexcept;
    Vector(const std::initializer_list<T> &init);
    ~Vector();
    Vector &operator=(const Vector &other);
    size_t CalculateCapacity(size_t newSize) const;
    void reallocate(size_t minSize);

    T &at(size_t pos);
    const T &at(size_t pos) const;
    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;
    T &back();
    const T &back() const;
    T *begin() noexcept;
    const T *begin() const noexcept;
    T *end() noexcept;
    const T *end() const noexcept;
    T *data() noexcept;
    const T *data() const noexcept;

    void pop_back();
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t new_cap);
    void clear();
    void push_back(T &item);
    void push_back(T &&item);
    template<class... Args>
    void emplace_back(T &&arg, Args &&...args);
    void resize(size_t count);
    void resize(size_t count, const T &value);

private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T *data_;
    Allocator<T> allocator_;
};

#include "../src/Vector.cpp"

#endif//VECTOR_HPP