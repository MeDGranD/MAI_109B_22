#include "../include/Tree.hpp"

int main() {
    Tree<int> bt;
    bt.insert_node(50);
    bt.insert_node(30);
    bt.insert_node(40);
    bt.insert_node(20);
    bt.insert_node(10);
    bt.insert_node(70);
    bt.insert_node(60);
    bt.insert_node(120);
    bt.insert_node(80);

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Nodes quantity: " << bt.count_nodes() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << bt;
    std::cout << "--------------------------------" << std::endl;
    bt.delete_node(50);
    std::cout << "Nodes quantity: " << bt.count_nodes() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    bt.print_tree();
    std::cout << "--------------------------------" << std::endl;
    bt.delete_node(30);
    std::cout << "Nodes quantity: " << bt.count_nodes() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << bt;
    std::cout << "--------------------------------" << std::endl;
    bt.insert_node(24);
    std::cout << "Nodes quantity: " << bt.count_nodes() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << bt;
    std::cout << "--------------------------------" << std::endl;
    bt.bypass();
    std::cout << "--------------------------------" << std::endl;

    return 0;
}
