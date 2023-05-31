#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"

template<typename T>
class List;

template<typename T>
class iterator{
    friend class List<T>;
public:
    iterator();
    iterator(const List<T>& list);
    iterator(node<T>* node);

    iterator<T>& operator++();
    T& operator*() const;
    iterator<T> operator+(size_t);
    bool operator==(const iterator<T>& other) const;
    bool operator!=(const iterator<T>& other) const;
private:
    node<T>* currentNode;
};

#include "../src/Iterator.cpp"

#endif