#ifndef TREENODE_HPP_INCLUDED
#define TREENODE_HPP_INCLUDED
#include <iostream>

template<typename T>
class Tree;

template<typename T>
class TreeNode{
    friend class Tree<T>;
public:
    TreeNode();
    TreeNode(const T&);
    TreeNode(const T&, TreeNode*, TreeNode*);

private:
    T data;
    int64_t depth = 0;

    TreeNode<T>* nextLeftNode;
    TreeNode<T>* nextRightNode;
};

#include "../src/TreeNode.cpp"

#endif