#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include "friend_list_declaration.hpp"
#include <iostream>
template<typename T>
class Node
{
    T data;
    Node *prev = nullptr;
    Node *next = nullptr;

public:
    friend class Iterator<T>;
    friend class List<T>;
    Node() = default;
    Node(const T &val);
    ~Node() = default;
};
#include "../src/Node.cpp"
#endif// NODE_HPP_INCLUDED
