#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Iterator.hpp"

template<typename T>
class List{
    friend class iterator<T>;
public:
    List();
    List(const size_t, const T& = T());
    List(const std::initializer_list<T>&);
    List(const List<T>&);

    std::ostream& operator<<(std::ostream& stream);

    void push_back(const T&);
    void push_front(const T&);

    template<typename... Args>
    void emplace_back(const Args&...);
    template<typename... Args>
    void emplace_front(const Args&...);

    void pop_back();
    void pop_front();

    void insert(const iterator<T>&, const T& data);
    void erase(const iterator<T>&, const iterator<T>&);

    void cycle_shift(T = T(), iterator<T>& = iterator<T>());

    iterator<T> begin() const;
    iterator<T> end() const;

    ~List();    

private:
    node<T>* start;
};

#include "../src/List.cpp"

#endif