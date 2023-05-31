#ifndef LAB23_NODE_HPP
#define LAB23_NODE_HPP
#include <iostream>

template <typename T>
class Node
{
private:
    T val;
    Node* left = nullptr;
    Node* right = nullptr;

public:
    Node() = default;
    explicit Node(const T &value);

    T GetVal() const;
    Node* GetLeft() const;
    Node* GetRight() const;

    Node* AddNode(Node* root, const T &value);

    void TreePrint(Node* root, int64_t depth) const;

    void DeleteNode(Node<T>* root, const T &value);
    Node<T>* SearchList(Node<T>* deleting_node) const;
    void DeleteBranch(Node<T>* current_node);
    int64_t FindMaxDepth(Node<T>* root) const;
    int64_t Task(Node<T>* root, int64_t counter);

    ~Node() = default;
};

#include "../src/Node.cpp"

#endif //LAB23_NODE_HPP
