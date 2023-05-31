#include "../include/Allocator.hpp"
template<typename T>
T *Allocator<T>::Allocate(size_t n)
{
    return (T *) (::operator new(n * sizeof(T)));
}

template<typename T>
void Allocator<T>::Deallocate(T *p, size_t n)
{
    delete (p);
}

template<typename T>
template<typename... Args>
void Allocator<T>::Construct(T *p, Args &&...args)
{
    new (p) T(args...);
}

template<typename T>
void Allocator<T>::Destroy(T *p)
{
    p->~T();
}