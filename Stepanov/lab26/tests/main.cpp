#include "../include/queue.hpp"
#include "../src/brenchmark.cpp"
#include <iostream>
int main()
{
    brenchmark();
    Queue<Vector<std::vector<int>>> T;
    Queue<int64_t> Y;
    Vector<std::vector<int>> k;
    k.resize(9);
    for (int64_t y = 0; y < 9; y++) {
        k[y].push_back(112);
        std::cout << k[y].size() << '\n';
    }
    std::cout << "Queque_tests" << '\n';
    T.push(k);
    T.push(k);
    T.push(k);
    std::cout << T.size() << '\n';
    Y.emplace(1, 2, 5, 99, -12, 33, 54, 33, 33, 54);
    std::cout << Y.front() << " " << Y.back() << " " << Y.size() << '\n';
    Y.pop();

    std::cout << Y.front() << " " << Y.back() << " " << Y.size() << '\n';
    Y.push(-1234);
    std::cout << Y.front() << " " << Y.back() << " " << Y.size() << '\n';
    int64_t tmp = 0;
    for (int64_t y = 0; y < Y.size(); ++y) {
        std::cout << Y.front() << " ";
        tmp = Y.front();
        Y.pop();
        Y.push(tmp);
    }
    std::cout << '\n';
    Y.sort();
    for (int64_t y = 0; y < Y.size(); ++y) {
        std::cout << Y.front() << " ";
        tmp = Y.front();
        Y.pop();
        Y.push(tmp);
    }
    std::cout << '\n';
    std::cout << "Return_to_VEC" << '\n';
    k.pop_back();
    k.pop_back();
    k.shrink_to_fit();
    std::cout << "copy constructor" << '\n';
    Vector<std::vector<int>> kc(k);
    for (int64_t y = 0; y < kc.size(); y++) {
        std::cout << kc[y].size() << '\n';
    }
    std::cout << "list of initialization" << '\n';
    Vector<std::string> sk({"a", "abb", "abaca"});
    for (int64_t y = 0; y < sk.size(); y++) {
        std::cout << sk[y] << '\n';
    }
    Vector<std::string> sk2 = {"a", "abb", "abaca"};
    for (int64_t y = 0; y < sk2.size(); y++) {
        std::cout << sk2[y] << '\n';
    }

    return 0;
}
