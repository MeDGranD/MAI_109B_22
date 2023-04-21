#ifndef TREENODE_HPP_INCLUDED
#define TREENODE_HPP_INCLUDED
#include <iostream>

template<typename T>
class TreeNode{
public:
    TreeNode();
    TreeNode(T);
    TreeNode(T, TreeNode*, TreeNode*);

    T data;
    int64_t depth = 0;

    TreeNode* nextLeftNode;
    TreeNode* nextRightNode;
};

#include "../src/TreeNode.cpp"

#endif