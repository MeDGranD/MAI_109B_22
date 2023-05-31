#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
struct node{
    node<T>* nextNode;
    T data;
    node(const T& = T(), node<T>* = nullptr);
};

#include "../src/Node.cpp"

#endif