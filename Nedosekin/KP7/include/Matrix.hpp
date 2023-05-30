#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "../include/Vector.hpp"
#include <fstream>

typedef int64_t Item;

class elementA
{
public:
    int64_t column = 0;
    Item value = 0;
    int64_t indexNext = 0;
};

class Matrix
{
private:
    Vector<elementA> A;
    Vector<int64_t> M;

public:
    void readingMatrix(const std::string &fileName);
    void multiplyMatrixByColumn(const std::string &fileName);
    void printMatrix(const std::string& fileName);
    void printA();
    void printM();
    void clearVectors();
};

#include "../src/Matrix.cpp"

#endif//MATRIX_HPP