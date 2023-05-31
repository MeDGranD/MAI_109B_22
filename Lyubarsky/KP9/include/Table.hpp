#ifndef TABLE_HPP
#define TABLE_HPP

#include "../../KP7/include/Vector.hpp"
#include "../../lab26/include/Deque.hpp"

template<typename T>
class Table{
public:
    Table() = default;
    ~Table() = default;

    void push_back(const std::pair<double, T>&);
    void print() const;
    void sort();

private:
    Vector<std::pair<double, T>> table;
};

#include "../src/Table.cpp"

#endif