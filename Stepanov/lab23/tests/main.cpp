#include "../include/Tree.hpp"
#include <iostream>


int main()
{
    Tree<int64_t> rotling;
    int64_t y = 3;
    int64_t a = 0;

    while (y > 0) {
        y--;

        rotling.insert_in_tree(19);
    }
    rotling.bypass();


    std::cout << rotling << '\n';
    rotling.b_tree_check();

    while (y > 0) {
        y--;

        rotling.delete_node(a);
    }
    rotling.b_tree_check();
    std::cout << rotling << '\n';
    rotling.bypass();

    return 0;
}
