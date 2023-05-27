#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include "iterator.hpp"
#include <iostream>
template<typename T>
class List
{
    Node<T> *barrier;
    size_t sz;

public:
    List();
    ~List();
    Iterator<T> begin();
    Iterator<T> end();
    bool empty();
    size_t size() const;
    Iterator<T> insert(Iterator<T> insert_iter, const T &data);
    Iterator<T> erase(Iterator<T> begin, Iterator<T> end);
    Iterator<T> erase(Iterator<T> erase_iter);
    void push_back(const T &value);
    void push_front(const T &value);
    void pop_back();
    void pop_front();
    template<typename... Args>
    void emplace_back(const T &First, const Args &...args);
    void emplace_back();
    template<typename K>
    friend std::ostream &operator<<(std::ostream &out, List<K> &x);
    Iterator<T> search(const T &value);
    void lab_swap(const size_t k);
};
#include "../src/List.cpp"


#endif// LIST_HPP_INCLUDED
