#include "../include/Tree.hpp"

template<typename T>
Node<T> *Tree<T>::get_root()
{
    return this->root;
}
template<typename T>
Tree<T>::Tree() : root(nullptr)
{}
template<typename T>
void Tree<T>::insert_in_tree(const T &inserted_variable)
{
    if (!root) {
        root = new Node<T>(inserted_variable);
    }
    else {
        root->Node<T>::add_leaf(inserted_variable, root);
    }
}
template<typename T>
void Tree<T>::bypass() const
{
    if (root) {
        root->Node<T>::bypass(root);
        std::cout << '\n';
    }
}
template<typename T>
void Tree<T>::delete_node(const T &value)
{
    if (root) {
        if (root->Node<T>::get_data() == value) {
            root = root->Node<T>::delete_node(root, value);
        }
        else {
            root->Node<T>::delete_node(root, value);
        }
    }
}
template<typename T>
void Tree<T>::b_tree_check() const
{
    if (root) {
        bool ans = root->Node<T>::b_tree_bypass(root);
        if (ans) {
            std::cout << "It's a B-tree, my dudes" << '\n';
        }
        else {
            std::cout << "It's not a B-tree, my dudes" << '\n';
        }
    }
}
template<typename T>
void Tree<T>::print_tree() const
{
    if (root) {
        root->Node<T>::print_nodes(root, 0);
    }
}
template<typename T>
std::ostream &operator<<(std::ostream &out, const Tree<T> &PrintTree)
{
    if (PrintTree.root) {
        PrintTree.root->Node<T>::print_nodes(PrintTree.root, 0, out);
        return out;
    }
    return out;
};
template<typename T>
Tree<T>::~Tree()
{
    root->Node<T>::delete_branch(root);
    root = nullptr;
}


