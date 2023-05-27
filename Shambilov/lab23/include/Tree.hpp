#ifndef LAB23_TREE_HPP
#define LAB23_TREE_HPP

#include "Node.hpp"

template <typename T>
class Tree {
private:
    Node<T>* root = nullptr;

public:
    Tree() = default;
    explicit Tree(Node<T>* node);

    Node<T>* GetRoot();

    void InsertNode(const T &value);
    void DeleteNode(const T &value);
    void PrintTree() const;
    void MaxDepth() const;
    void Task() const;

    ~Tree();
};

#include "../src/Tree.cpp"

#endif //LAB23_TREE_HPP
