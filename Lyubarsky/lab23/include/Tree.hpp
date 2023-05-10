#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include "TreeNode.hpp"

template<typename T>
class Tree{
public:
    Tree();
    Tree(const T&);

    TreeNode<T>* getRoot() const;

    void addNode(const T&, TreeNode<T>*);
    TreeNode<T>* deleteNode(const T&, TreeNode<T>*);

    void linearize(TreeNode<T>*);
    void visualize(TreeNode<T>*) const;

    void deleteTree(TreeNode<T>*);
    ~Tree();

private:
    TreeNode<T>* root = nullptr;
    bool linear;
};

#include "../src/Tree.cpp"

#endif