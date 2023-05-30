#include "../include/List.hpp"
#include "../src/brenchmark.cpp"
#include <iostream>
using namespace std;

int main()
{
    brenchmark();
    Node<int64_t> y;
    Iterator<int64_t> l(&y);
    List<int64_t> j;
    cout << j.begin().get_node() << endl;
    cout << j.end().get_node() << endl;
    cout << j.empty() << endl;
    cout << j.size() << endl;
    j.insert(j.end(), 10);
    j.insert(j.end(), 101);
    j.insert(j.end(), 102);
    j.insert(j.end(), 111);

    cout << "R" << endl;
    cout << *j.begin() << endl;
    cout << "FFF" << endl;
    cout << *(--j.end()) << endl;
    cout << j.empty() << endl;
    cout << j.size() << endl;

    j.erase(++j.begin(), --j.end());
    cout << "FFF" << endl;
    j.pop_back();
    j.pop_front();
    j.push_back(120);
    j.push_back(230);
    j.push_front(99999);
    j.emplace_back(11, 12, 13, 14, 15, -100, 98, 9888, -102012);
    cout << j << endl;
    cout << "after_swap" << endl;
    j.lab_swap(6);
    j.lab_swap(12);
    cout << j << endl;
    cout << "oposite" << endl;
    for (Iterator<int64_t> u = --j.end(); u != j.end(); --u) {
        cout << *u << endl;
    }
    cout << "Rkk" << endl;

    cout << *((j.begin())) << endl;
    cout << *(j.end() + (-3)) << endl;
    cout << *(j.end() - 3) << endl;
    cout << (*(j.end() - 3)) << endl;
    (*(j.end() - 3)) = 444;
    cout << *(j.end() - 3) << endl;
    cout << j.empty() << endl;
    cout << j.size() << endl;
    return 0;
}
