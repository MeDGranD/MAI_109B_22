#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T &value): val(value)
{}

template <typename T>
T Node<T>::get_val() const
{
    return this->val;
}

template <typename T>
Node<T>* Node<T>::get_left() const{
    return this->left;
}

template <typename T>
Node<T>* Node<T>::get_right() const
{
    return this->right;
}

template <typename T>
Node<T>* Node<T>::AddNode(Node* root, const T &value)
{
    if(root == nullptr)
    {
        root = new Node(value);
    }
    else if(value < root->val)
    {
        root->left = AddNode(root->left, value);
    }
    else if(value > root->val)
    {
        root->right = AddNode(root->right, value);
    }
    return root;
}

template <typename T>
void Node<T>::TreePrint(Node<T>* root, int64_t depth) const
{   
    if(root != nullptr)
    {
        TreePrint(root->right, depth + 1);
        for(int64_t indent = 0 ; indent < depth ; ++indent)
        {
            std::cout << '\t' ;
        }
        std::cout << root->val << std::endl;
        TreePrint(root->left, depth + 1);
    }
}

template<typename T>
Node<T>* Node<T>::SearchNewNode(Node<T>* deleting_node_right) const
{
    if(deleting_node_right->left == nullptr)
    {
        return deleting_node_right;
    }
    else
    {
        SearchNewNode(deleting_node_right->left);
    }
}

template<typename T>
void Node<T>::DeleteNode(Node<T>* &root, const T &value)
{
    if(root == nullptr)
    {
        return;
    }
    else if(value < root->val)
    {
        DeleteNode(root->left, value);
    }
    else if(value > root->val)
    {
        DeleteNode(root->right, value);
    }
    else if(value == root->val)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
            delete root;
        }
        else if(root->left != nullptr && root->right != nullptr)
        {
            Node<T>* successor = SearchNewNode(root->right);
            T successor_val = successor->val;
            DeleteNode(successor, successor->val);
            root->val = successor_val;
        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            root = root->left;
        }
        else if(root->left == nullptr && root->right != nullptr)
        {
            root = root->right;
        }
    }
    else
    {
        std::cout << "Cannot found this value in the tree" << std::endl;
    }
}

template<typename T>
int64_t Node<T>::FindMaxDepth(Node<T>* root) const
{
    if(root == nullptr)
    {
        return 0;
    }
    int64_t LDepth = FindMaxDepth(root->left);
    int64_t RDepth = FindMaxDepth(root->right);
    return (std::max(LDepth, RDepth) + 1);
}

template<typename T>
void Node<T>::DeleteBranch(Node<T>* current_node)
{
    if(current_node == nullptr)
    {
        return;
    }
    DeleteBranch(current_node->left);
    delete current_node;
    DeleteBranch(current_node->right);
}
