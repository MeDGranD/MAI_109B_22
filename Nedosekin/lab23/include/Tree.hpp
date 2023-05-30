#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"

template<typename T>
class Tree
{
private:
    Node<T>* root = nullptr;

public:
    Tree() = default;
    explicit Tree(Node<T>* node);
    
    Node<T>* get_root();

    void InsertNode(const T &value);
    void DeleteNode(const T &value);
    void PrintTree() const;
    void MaxDepth() const;

    ~Tree();
};

#include "../src/Tree.cpp"
#endif //TREE_HPP
