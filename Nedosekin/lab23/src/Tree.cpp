#include "../include/Tree.hpp"

template<typename T>
Tree<T>::Tree(Node<T>* node): root(node)
{}

template<typename T>
Node<T>* Tree<T>::get_root() 
{
    return this->root;
}

template<typename T>
void Tree<T>::InsertNode(const T &value)
{
    if(root == nullptr)
    {
        root = new Node(value);
        return;
    }
    else
    {
        root->AddNode(root, value);
    }
    return;
}

template<typename T>
void Tree<T>::DeleteNode(const T &value)
{
    root->DeleteNode(root,value);
}

template<typename T>
void Tree<T>::PrintTree() const
{
    root->TreePrint(root, 0);
}

template<typename T>
void Tree<T>::MaxDepth() const
{
    int64_t depth = 0;
    depth = root->FindMaxDepth(root);
    std::cout << depth << std::endl;
}

template<typename T>
Tree<T>::~Tree()
{
    root->DeleteBranch(root);
}
