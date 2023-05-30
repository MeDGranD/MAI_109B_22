#include "../include/Matrix.hpp"
#include "../src/Benchmark.cpp"
#include <iostream>

int main()
{
    //benchmark();
    Matrix matrix;
    bool exitCondition = true;
    char operation;
    std::string fileName;
    while (exitCondition) {
        std::cout << "Choose operation:\n1 - input matrix\n2 - multiply matrix by column\n"
                     "3 - print matrix\n4 - run a benchmark comparing the library vector and my own\n5 - print vector A\n"
                     "6 - print vector M\n7 - finish the programm\n";
        std::cin >> operation;
        switch (operation) {
            case '1':
                std::cout << "Enter file name in format: test + digit from 1 to 6. For example: test3.\n";
                std::cin >> fileName;
                matrix.readingMatrix(fileName);
                break;
            case '2':
                matrix.multiplyMatrixByColumn(fileName);
                break;
            case '3':
                matrix.printMatrix(fileName);
                break;
            case '4':
                benchmark();
                break;
            case '5':
                matrix.printA();
                break;
            case '6':
                matrix.printM();
                break;
            case '7':
                exitCondition = false;
                break;
        }
    }
}