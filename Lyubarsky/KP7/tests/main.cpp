#include "../include/Matrix.hpp"
#include "benchmark.cpp"

int main(){

    benchmark();
    
    Matrix matrix("Matrix");

    matrix.print();
    matrix.transpose();
    std::cout << "----------------------------" << std::endl;
    matrix.print();

    return 0;
}