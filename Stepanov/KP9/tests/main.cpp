#include "../include/Table.hpp"
#include "../src/brenchmark.cpp"
#include <cstdint>
#include <iostream>



int main()
{   //brenchmark();
    Table<std::string> t;
    t.push_back("aaaaa", "aaa2");
    t.push_back("zacaf", "aaa2234");
    t.push_back("aacaf", "aaa221");
    t.push_back("aabal", "aaa233456");


    std::cout << t;
    std:: cout << '\n';
    t.sort("zzzzzzzz");
     std::cout << t;
     std::cout << t.search("aacaf", "zzzzzzzz") <<  std::endl;
     std::cout << t.search("aacak", "zzzzzzzz") <<  std::endl;
     std::cout << t.search("aabal", "zzzzzzzz") <<  std::endl;
    Table<int64_t> t1;
     std::cout << '\n';

     std::cout << '\n';
    t1.push_back(99, "1wasd");
    t1.push_back(1, "wasd");
    t1.push_back(-10, "121wasd");

     std::cout << t1;
    t1.sort(INT64_MAX);
     std::cout << t1;
    Table<std::string> t_test;

    std:: cout << t_test;
    t_test.sort("zzzzzzzz");
     std::cout << t_test;
    return 0;
}
