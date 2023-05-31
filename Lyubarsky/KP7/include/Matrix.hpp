#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"
#include <fstream>
#include <string>
#include <sstream>

class Matrix{
public:
    Matrix();
    Matrix(const std::string&);

    Matrix& operator*=(const int64_t);
    void print() const;
    void transpose();
    bool isSkewSymmetric() const;

private:
    Vector<int64_t> M; //Names from google drive KP file
    Vector<int64_t> A;
    size_t m = 0;
    size_t n = 0;
};

#include "../src/Matrix.cpp"

#endif