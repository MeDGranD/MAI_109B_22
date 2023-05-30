#include "../include/Vector.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>


void brenchmark()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ifstream fin;
    fin.open("tests.txt");
    Vector<int64_t> test1;
    std::vector<int64_t> test2;
    int64_t number, in_int;
    fin >> number;
    std::cout << number << std::endl;

    std::cout << "push_back O(1)" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        fin >> in_int;
        test1.push_back(in_int);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    fin.clear();
    fin.seekg(0);
    fin >> in_int;
    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        fin >> in_int;
        test2.push_back(in_int);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    if (test1.size() != test2.size()) {
        throw std::exception();
    }
    for (size_t b = 0; b < test2.size(); ++b) {
        if (test2[b] != test1[b]) {
            std::cout << b << ": test1[b] =" << test1[b] << " test2[b] =" << test2[b] << std::endl;
            throw std::exception();
        }
    }

    std::cout << "pop.back O(1)" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        test1.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        test2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    if (test1.size() != test2.size()) {
        throw std::exception();
    }
    for (size_t b = 0; b < test2.size(); ++b) {
        if (test2[b] != test1[b]) {
            std::cout << b << ": test1[b] =" << test1[b] << " test2[b] =" << test2[b] << std::endl;
            throw std::exception();
        }
    }

    std::cout << "shrink_to_fit" << '\n';
    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        test1.shrink_to_fit();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        test2.shrink_to_fit();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    if (test1.capacity() != test2.capacity()) {
        std::cout << ": test1.cap =" << test1.capacity() << " test2.cap =" << test2.capacity() << std::endl;
    }
    begin = std::chrono::steady_clock::now();
    test1.reserve(2 * number);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    begin = std::chrono::steady_clock::now();
    test2.reserve(2 * number);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << ": test1.cap =" << test1.capacity() << " test2.cap =" << test2.capacity() << std::endl;
    std::cout << "resize" << std::endl;
    begin = std::chrono::steady_clock::now();
    test1.resize(number, in_int);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    begin = std::chrono::steady_clock::now();
    test2.resize(number, in_int);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    if (test1.size() != test2.size()) {
        throw std::exception();
    }
    for (size_t b = 0; b < test2.size(); ++b) {
        if (test2[b] != test1[b]) {
            std::cout << b << ": test1[b] =" << test1[b] << " test2[b] =" << test2[b] << std::endl;
            throw std::exception();
        }
    }
    std::cout << ": test1.cap =" << test1.capacity() << " test2.cap =" << test2.capacity() << std::endl;
    std::cout << ": test1.size =" << test1.size() << " test2.size =" << test1.size() << std::endl;
    std::cout << "clear" << std::endl;
    begin = std::chrono::steady_clock::now();
    test1.clear();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    begin = std::chrono::steady_clock::now();
    test2.clear();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Copy constructors" << std::endl;
    begin = std::chrono::steady_clock::now();
    Vector<int64_t> test3(test1);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    begin = std::chrono::steady_clock::now();
    std::vector<int64_t> test4(test2);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "eqequality" << std::endl;
    begin = std::chrono::steady_clock::now();
    std::cout << (test3 == test1) << std::endl;
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    begin = std::chrono::steady_clock::now();
    std::cout << (test2 == test4) << std::endl;
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    return;
}
