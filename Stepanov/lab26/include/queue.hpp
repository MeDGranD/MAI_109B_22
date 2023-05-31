#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED
#include "../../KP7/include/Vector.hpp"
template<typename T>
class Queue
{
    Vector<T> vector_in;
    Vector<T> vector_out;

public:
    Queue() = default;
    size_t size();
    bool empty();
    void push(const T &value);
    void pop();
    T &front();
    T &back();
    template<typename... Args>
    void emplace(const Args &...args);
    bool resurface();
    void sort();
    ~Queue() = default;
};
#include "../src/queue.cpp"
#endif// QUEUE_HPP_INCLUDED
