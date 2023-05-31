#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED
#include "Vector.hpp"

class Matrix {
private:
    Vector<int64_t> mat;
    size_t m_sz = 0;
    size_t n_sz = 0;
    Vector<size_t> line_beginnings;
public:
    Matrix();
    friend std::istream &operator>>(std::istream &in, Matrix &a);
    friend std::ostream &operator<<(std::ostream &out, Matrix &a);

    void print() const;
    void transpose();
    bool is_skew_symmetric() const;

    size_t get_m_sz() const;
    size_t get_n_sz() const;
};


#include "../src/Matrix.cpp"
#endif
