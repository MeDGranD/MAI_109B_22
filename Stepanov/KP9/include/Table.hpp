#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED
#include "../../KP7/include/Vector.hpp"

template<typename T>
class Table
{
    Vector<std::string> lines;
    Vector<T> keys;
    size_t winner(const size_t pos_a, const size_t pos_b, const size_t n, Vector<size_t> &win_match, Vector<T> &t_keys);
public:
    Table() = default;
    ~Table() = default;
    void push_back(const T &key, const std::string &input_data);
    std::string search(const T &key, const T &inf);
    template<typename j>
    friend std::ostream &operator<<(std::ostream &out, Table<j> &x);
    template<typename j>
    friend std::istream &operator>>(std::istream &in, Table<j> &x);
    void sort(const T &inf);
};
#include "../src/Table.cpp"

#endif// TABLE_HPP_INCLUDED
