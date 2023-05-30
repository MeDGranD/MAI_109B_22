#include "../include/Vector.hpp"
#include <iostream>
#include <limits>
#include <memory>

template<class T, class A>
Vector<T, A>::Vector() : size_(0), capacity_(0)
{
    data_ = allocator_.Allocate(capacity());
}

template<class T, class A>
Vector<T, A>::Vector(size_t size, const T &value) : size_(size), capacity_(0)
{
    capacity_ = CalculateCapacity(size);
    data_ = allocator_.Allocate(capacity());
    std::fill_n(data(), size, value);
}

template<class T, class A>
Vector<T, A>::Vector(const Vector &other)
{
    this->resize(other.size());
    capacity_ = other.capacity();
    std::copy(other.begin(), other.end(), data());
}

template<class T, class A>
Vector<T, A>::Vector(Vector &&other) noexcept
{
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(data_, other.data_);
    other.clear();
}

template<class T, class A>
Vector<T, A>::Vector(const std::initializer_list<T> &init)
{
    size_ = init.size();
    capacity_ = CalculateCapacity(size());
    data_ = allocator_.Allocate(capacity());
    std::copy(init.begin(), init.end(), data());
}

template<typename T, typename A>
Vector<T, A>::~Vector()
{
    if (data_ != nullptr) {
        for (size_t i = 0; i < size(); ++i) {
            allocator_.Destroy(&data_[i]);
        }
        if (capacity() > 0) {
            allocator_.Deallocate(data(), capacity());
        }
        data_ = nullptr;
    }
    capacity_ = 0;
}

template<typename T, typename A>
void Vector<T, A>::push_back(T &value)
{
    emplace_back(std::move(value));
}

template<class T, class A>
void Vector<T, A>::push_back(T &&value)
{
    emplace_back(std::move(value));
}

template<typename T, typename A>
void Vector<T, A>::reallocate(size_t minSize)
{
    const size_t newCapacity = CalculateCapacity(minSize + 1);
    T *newData = allocator_.Allocate(newCapacity);
    for (size_t i = 0; i < size(); ++i) {
        allocator_.Construct(&newData[i], data_[i]);
        allocator_.Destroy(&data_[i]);
    }
    if (capacity() > 0) {
        allocator_.Deallocate(data(), capacity());
    }
    capacity_ = newCapacity;
    data_ = newData;
}

template<typename T, typename A>
[[nodiscard]] size_t Vector<T, A>::CalculateCapacity(size_t minSize) const
{
    std::size_t newCapacity;
    if (minSize < capacity()) {
        newCapacity = 1;
    }
    else if (capacity()) {
        newCapacity = capacity();
    }
    else {
        newCapacity = 1;
    }
    while (newCapacity < minSize) {
        if (newCapacity >= std::numeric_limits<size_t>::max() - newCapacity) {
            return std::numeric_limits<size_t>::max();
        }
        newCapacity *= 2;
    }
    return newCapacity;
}

template<typename T, typename A>
size_t Vector<T, A>::size() const
{
    return size_;
}

template<typename T, typename A>
size_t Vector<T, A>::capacity() const
{
    return capacity_;
}

template<typename T, typename A>
const T *Vector<T, A>::begin() const noexcept
{
    return data_;
}

template<typename T, typename A>
T *Vector<T, A>::begin() noexcept
{
    return data_;
}

template<typename T, typename A>
const T *Vector<T, A>::end() const noexcept
{
    return (data_ + size());
}

template<typename T, typename A>
T *Vector<T, A>::end() noexcept
{
    return (data_ + size());
}

template<typename T, typename A>
const T &Vector<T, A>::back() const
{
    return (data_[size() - 1]);
}

template<typename T, typename A>
T &Vector<T, A>::back()
{
    return (data_[size() - 1]);
}

template<typename T, typename A>
bool Vector<T, A>::empty() const
{
    return (size() == 0);
}

template<typename T, typename A>
const T *Vector<T, A>::data() const noexcept
{
    return data_;
}

template<typename T, typename A>
T *Vector<T, A>::data() noexcept
{
    return data_;
}

template<typename T, typename A>
void Vector<T, A>::reserve(size_t new_capacity)
{
    if (new_capacity > capacity()) {
        reallocate(new_capacity);
        capacity_ = new_capacity;
    }
}

template<typename T, typename A>
void Vector<T, A>::pop_back()
{
    if (size() > 0) {
        allocator_.Destroy(end() - 1);
        --size_;
    }
}

template<typename T, typename A>
void Vector<T, A>::resize(size_t count)
{
    resize(count, T());
}

template<typename T, typename A>
void Vector<T, A>::resize(size_t count, const T &value)
{
    if (count > capacity()) {
        reserve(count);
        for (size_t i = size(); i < count; ++i) {
            allocator_.Construct(data() + 1, value);
        }
    }
    else if (count < size()) {
        for (size_t i = count; i < size(); ++i) {
            allocator_.Destroy(data() + 1);
        }
    }
    size_ = count;
}

template<typename T, typename A>
template<typename... Args>
void Vector<T, A>::emplace_back(T &&arg, Args &&...args)
{
    if (capacity() == size()) {
        reallocate(capacity() + 1);
    }
    allocator_.Construct(end(), arg);
    ++size_;
    if constexpr (sizeof...(args) > 0) {
        emplace_back(args...);
    }
}

template<class T, class A>
bool operator==(const Vector<T, A> &lhs, const Vector<T, A> &rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs.at(i) != rhs.at(i)) {
            return false;
        }
    }
    return true;
}

template<class T, class A>
bool operator!=(const Vector<T, A> &lhs, const Vector<T, A> &rhs)
{
    return !(lhs == rhs);
}

template<class T, class A>
T &Vector<T, A>::operator[](size_t pos)
{
    return data_[pos];
}

template<class T, class A>
void Vector<T, A>::clear()
{
    for (size_t i = 0; i < size(); i++) {
        allocator_.Destroy(data() + i);
    }
    size_ = 0;
}

template<class T, class Allocator>
T &Vector<T, Allocator>::at(size_t pos)
{
    if (pos < size()) {
        return data_[pos];
    }
    else {
        throw std::out_of_range("position is out of range");
    }
}

template<class T, class Allocator>
const T &Vector<T, Allocator>::at(size_t pos) const
{
    if (pos < size()) {
        return data_[pos];
    }
    else {
        throw std::out_of_range("position is out of range");
    }
}