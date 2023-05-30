#include <iostream>
#include "../include/Tree.hpp"

int main() {
    Tree<int> BT;

    BT.InsertNode(1);
    BT.InsertNode(2);
    BT.InsertNode(3);
    BT.InsertNode(4);
    BT.InsertNode(5);
    BT.InsertNode(6);
    BT.InsertNode(7);

    BT.PrintTree();
    std::cout << "#############################" << '\n';
    std::cout << "Number of nodes with degree equal to value: " ;
    BT.Task();
    BT.DeleteNode(1);
    BT.InsertNode(2);
    std::cout << "#############################" << '\n';
    std::cout << "Number of nodes with degree equal to value: " ;
    BT.Task();
    std::cout << "#############################" << '\n';
    BT.PrintTree();
    std::cout << "#############################" << '\n';
    std::cout << "Max Depth right now it`s - ";
    BT.MaxDepth();

    return 0;
}
