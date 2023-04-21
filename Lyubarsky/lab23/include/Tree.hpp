#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include "TreeNode.hpp"

template<typename T>
class Tree{
public:
    Tree();
    Tree(const T&);

    void addNode(const T&, TreeNode<T>*);
    TreeNode<T>* deleteNode(const T&, TreeNode<T>*);

    void linearize(TreeNode<T>*) const;
    void visualize(TreeNode<T>*) const;

    void deleteTree(TreeNode<T>*);
    ~Tree();

    TreeNode<T>* root = nullptr;
};

#include "../src/Tree.cpp"

#endif