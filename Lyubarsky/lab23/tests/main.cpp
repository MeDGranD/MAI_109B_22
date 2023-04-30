#include "../include/Tree.hpp"

int main(){

    Tree<int64_t> tree(8);

    for(int64_t nodeData = 1; nodeData < 10; ++nodeData){
        tree.addNode((nodeData*3)/2+5, tree.getRoot());
        tree.addNode((nodeData*2)/3+2, tree.getRoot());
    }
    tree.visualize(tree.getRoot());
    tree.linearize(tree.getRoot());
    
    Tree<int64_t> secondTree;
    for(int64_t nodeData = 1; nodeData < 11; ++nodeData){
        secondTree.addNode(nodeData, secondTree.getRoot());
        secondTree.addNode(-nodeData, secondTree.getRoot());
    }
    secondTree.visualize(secondTree.getRoot());
    secondTree.linearize(secondTree.getRoot());

    return 0;
}