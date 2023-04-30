#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

template <typename T>
class Node {
private:
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

public:
    Node() = default;
    explicit Node(const T &value);

    T get_data() const;
    Node *get_left() const;
    Node *get_right() const;

    void add_leaf(Node *current_node, const T &value);
    void print_nodes(std::ostream &out, Node<T> *node, int64_t height) const;
    void print_nodes(Node<T> *node, int64_t height) const;
    void count_nodes(Node *node, int64_t *counter) const;
    Node<T> *delete_node(Node<T> *current_node, const T &value);

    Node<T> *min_value_node(Node<T>* const node) const;
    void bypass(Node<T> *node) const;
    void delete_branch(Node<T> *current_node);
    ~Node() = default;
};

#include "../src/Node.cpp"

#endif
