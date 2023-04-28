#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED
#include "Node.hpp"

template<typename T>
class Tree
{
    Node<T> *root;

public:
    Node<T> *get_root();
    Tree();
    void insert_in_tree(const T &inserted_variable);
    void bypass() const;
    void delete_node(const T &value);
    void b_tree_check() const;
    template<typename J>
    friend std::ostream &operator<<(std::ostream &o, const Tree<J> &x);
    void print_tree() const;
    ~Tree();
};

#include "../src/Tree.cpp"

#endif// TREE_HPP_INCLUDED
