#include "../include/Tree.hpp"

template <typename T>
Tree<T>::Tree(Node<T>* node): root(node) {}

template <typename T>
Node<T>* Tree<T>::GetRoot() {
    return this->root;
}

template <typename T>
void Tree<T>::InsertNode(const T &value) {
    root->AddNode(root, value);
}

template <typename T>
void Tree<T>::DeleteNode(const T &value) {
    root->DeleteNode(root,value);
}

template <typename T>
void Tree<T>::PrintTree() const {
    root->TreePrint(root, 0);
}

template <typename T>
void Tree<T>::MaxDepth() const {
    int64_t height = root->FindMaxDepth(root);
    std::cout << height << std::endl;
}

template <typename T>
void Tree<T>::Task() const {
    std::cout << root->Task(root, 0) << std::endl;
}

template <typename T>
Tree<T>::~Tree() {
    root->DeleteBranch(root);
}
