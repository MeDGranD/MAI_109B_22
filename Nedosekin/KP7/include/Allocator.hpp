#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <iostream>

template<typename T>
class Allocator
{
private:
    T *pointer;

public:
    T *Allocate(size_t n);
    void Deallocate(T *p, size_t n);
    template<typename... Args>
    void Construct(T *p, Args &&...args);
    void Destroy(T *p);
};

#include "../src/Allocator.cpp"

#endif//ALLOCATOR_HPP