#ifndef NODE_HPP
#define NODE_HPP
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

    T get_val() const;
    Node* get_left() const;
    Node* get_right() const;

    Node* AddNode(Node* node, const T &value);

    void TreePrint(Node* root, int64_t depth) const;

    void DeleteNode(Node<T>* &root, const T &value);
    Node<T>* SearchNewNode(Node<T>* deleting_node) const;
    void DeleteBranch(Node<T>* current_node);
    int64_t FindMaxDepth(Node<T>* root) const;

    ~Node() = default;
};

#include "../src/Node.cpp"
#endif //NODE_HPP
