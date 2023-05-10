#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template<typename T>
struct node;

template<typename T>
class iterator;

template<typename T>
class List;

template<typename T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list);

template<typename T>
class List{
    friend class iterator<T>;
    friend std::ostream& operator<<<T>(std::ostream&, const List&);
public:
    List();
    List(const size_t, const T& = T());
    List(const std::initializer_list<T>&);
    List(const List<T>&);

    void push_back(const T&);
    void push_front(const T&);

    template<typename... Args>
    void emplace_back(const Args&...);
    template<typename... Args>
    void emplace_front(const Args&...);

    void pop_back();
    void pop_front();

    void insert(iterator<T>&, const T& data);
    void erase(iterator<T>&, iterator<T>&);

    void cycle_shift(T = T(), iterator<T>& = iterator<T>());

    iterator<T> begin() const;
    iterator<T> end() const;

    ~List();    

private:
    node<T>* start;
};

template<typename T>
struct node{
    node<T>* nextNode;
    T data;
    node(const T& = T(), node<T>* = nullptr);
};

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

#include "../src/List.cpp"

#endif