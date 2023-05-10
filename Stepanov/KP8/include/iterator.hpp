#ifndef ITERATOR_HPP_INCLUDED
#define ITERATOR_HPP_INCLUDED
#include "Node.hpp"
template<typename T>
class Iterator
{
    Node<T> *node;

public:
    friend List<T>;
    Iterator() = default;
    Iterator(Node<T> *_node);
    Iterator operator++();
    Iterator operator--();
    bool operator==(Iterator b);
    bool operator!=(Iterator b);
    Node<T> *get_node();
    Iterator operator+(int64_t value);
    Iterator operator-(int64_t value);
    ~Iterator() = default;
    T &operator*();
    T &operator*() const;
};
#include "../src/iterator.cpp"
#endif// ITERATOR_HPP_INCLUDED
