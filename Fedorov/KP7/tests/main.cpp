#include <iostream> 
#include <filesystem> 
#include "../include/Matrix.hpp"
#include "../src/benchmark.cpp"

int main() {

    std::cout << std::filesystem::current_path() << std::endl;

    std::cout << "--------------------------------------------------\n";
    std::cout << """Vector benchmark and comparison with STL "
                   "(first my, then STL)""" << "\n";
    std::cout << "--------------------------------------------------\n";
    benchmark();

    std::cout << "--------------------------------------------------\n";
    std::cout << "Matrix tests" << "\n";
    std::cout << "--------------------------------------------------\n";


    std::ifstream fin;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    fin.open("./tests/matrix_test1.txt",std::ios_base::in);
    Matrix a;
    fin >> a;
    std::cout << "Test 1. Number of elements: " << a.get_m_sz() * a.get_n_sz() << "\n";
    std::cout << "Matrix usual view:" << "\n";
    a.print();
    std::cout << std::endl;
    std::cout << "Matrix internal view:" << "\n";
    std::cout << a << std::endl;
    std::cout << std::endl;
    std::cout << "Check if matrix is skew symmetric:" << "\n";
    std::cout << a.is_skew_symmetric() << std::endl;
    std::cout << "Matrix usual view after being transposed:" << "\n";
    a.transpose();
    a.print();
    std::cout << "--------------------------------------------------\n";
    fin.close();

    fin.open("./tests/matrix_test2.txt",std::ios_base::in);
    Matrix b;
    fin >> b;
    std::cout << "Test 2. Number of elements: " << b.get_m_sz() * b.get_n_sz() << "\n";
    std::cout << "Matrix usual view:" << "\n";
    b.print();
    std::cout << std::endl;
    std::cout << "Matrix internal view:" << "\n";
    std::cout << b << std::endl;
    std::cout << std::endl;
    std::cout << "Check if matrix is skew symmetric:" << "\n";
    std::cout << b.is_skew_symmetric() << "\n\n";
    std::cout << "Matrix usual view after being transposed:" << "\n";
    b.transpose();
    b.print();
    std::cout << std::endl;
    std::cout << "Check if matrix is skew symmetric:" << "\n";
    std::cout << b.is_skew_symmetric() << std::endl;
    std::cout << "--------------------------------------------------\n";
    fin.close();

    fin.open("./tests/matrix_test3.txt",std::ios_base::in);
    Matrix c;
    fin >> c;
    std::cout << "Test 3. Number of elements: " << c.get_m_sz() * c.get_n_sz() << "\n";
    std::cout << "Matrix usual view is too big, it's better to open the file" << "\n";
    std::cout << "Matrix internal view is too big, it's better to open the file" << "\n";
    std::cout << "Check if matrix is skew symmetric:" << "\n";
    std::cout << c.is_skew_symmetric() << std::endl;
    std::cout << "--------------------------------------------------\n";
    fin.close();

    fin.open("./tests/matrix_test4.txt",std::ios_base::in);
    Matrix d;
    fin >> d;
    std::cout << "Test 4. Number of elements: " << d.get_m_sz() * d.get_n_sz() << "\n";
    std::cout << "Matrix usual view is too big, it's better to open the file" << "\n";
    std::cout << "Matrix internal view is too big, it's better to open the file" << "\n";
    std::cout << "Check if matrix is skew symmetric:" << "\n";
    std::cout << d.is_skew_symmetric() << std::endl;
    std::cout << "--------------------------------------------------\n";
    fin.close();

    return 0;
}
