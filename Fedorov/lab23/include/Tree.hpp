#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED
#include "Node.hpp"

template <typename T>
class Tree {
private:
    Node<T> *root = nullptr;
public:
    Tree() = default;
    explicit Tree(Node<T>* const node);

    Node<T> *get_root();
    void insert_node(const T &value);
    void delete_node(const T &value);
    int64_t count_nodes() const;
    void print_tree() const;
    void bypass() const;

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out, const Tree<U> &t);

    ~Tree();
};


#include "../src/Tree.cpp"
#endif
