#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>


template<typename T>
class Node
{
private:
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

public:
    T get_data() const;
    Node *get_left() const;
    Node *get_right() const;
    explicit Node(const T &new_data);
    Node() = default;
    ~Node() = default;


    void bypass(const Node *node) const;
    int64_t b_tree_bypass(const Node *node) const;
    void print_nodes(Node *node, int64_t height) const;
    void print_nodes(Node *node, int64_t height, std::ostream &out) const;


    Node *add_leaf(const T &insert_data, Node *cur_node);
    void delete_branch(Node *deleting_node);
    Node *delete_node(Node *node, const T &variable_of_interest);
};

#include "../src/Node.cpp"

#endif// NODE_HPP_INCLUDED
