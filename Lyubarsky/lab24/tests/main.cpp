#include "../include/Nary_tree.hpp"

int main(){

    Nary_tree nr;

    nr.makeBinaryTree("2+2+2+5");
    nr.print();
    nr.makeNaryTree();
    nr.print();

    return 0;
}
