#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED
#include "Vector.hpp"


class Matrix
{
    Vector<int64_t> matrix_in_line;
    size_t msz;
    size_t nsz;

public:
    Matrix();
    friend std::istream &operator>>(std::istream &in, Matrix &x);
    friend std::ostream &operator<<(std::ostream &out, Matrix &x);
    void normalization();
    void divide(int64_t &cur_max_collumn, int64_t &max_elem);
    void print();
};

#endif// MATRIX_HPP_INCLUDED
