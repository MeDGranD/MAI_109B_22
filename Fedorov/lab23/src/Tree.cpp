#include "../include/Tree.hpp"

template<typename T>
Tree<T>::Tree(Node<T>* const node): root(node) {}

template<typename T>
Node<T> *Tree<T>::get_root() {
    return this->root;
}

template<typename T>
int64_t Tree<T>::count_nodes() const {
    int64_t counter = 0;
    root->count_nodes(root, &counter);
    return counter;
}

template<typename T>
void Tree<T>::insert_node(const T &value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    root->add_leaf(root, value);
}

template<typename T>
void Tree<T>::delete_node(const T &value) {
    root = root->delete_node(root, value);
}

template<typename T>
void Tree<T>::print_tree() const {
    root->print_nodes(root, 0);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Tree<T> &t)
{
    t.root->Node<T>::print_nodes(out, t.root, 0);
    return out;
};

template<typename T>
void Tree<T>::bypass() const {
    root->bypass(root);
}

template<typename T>
Tree<T>::~Tree() {
    root->delete_branch(root);
}