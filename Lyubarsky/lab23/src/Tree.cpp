#include "../include/Tree.hpp"

template<typename T>
Tree<T>::Tree(){
    this->root = new TreeNode<T>(0);
    this->root->depth = 0;
    this->linear = true;
}

template<typename T>
Tree<T>::Tree(const T& data){
    this->root = new TreeNode<T>(data);
    this->root->depth = 0;
    this->linear = true;
}

template<typename T>
TreeNode<T>* Tree<T>::getRoot() const{
    return this->root;
}

template<typename T>
void Tree<T>::addNode(const T& newData, TreeNode<T>* node){
    if (node->data > newData){
        if (node->nextLeftNode == nullptr){
            node->nextLeftNode = new TreeNode<T>(newData);
            node->nextLeftNode->depth = node->depth + 1;
        }
        else {
            addNode(newData, node->nextLeftNode);
        }
    }
    else if (node->data <= newData){
        if (node->nextRightNode == nullptr){
            node->nextRightNode = new TreeNode(newData);
            node->nextRightNode->depth = node->depth + 1;
        }
        else{
            addNode(newData, node->nextRightNode);
        }
    }
}

template<typename T>
TreeNode<T>* Tree<T>::deleteNode(const T& deleteData, TreeNode<T>* node){
    
    if (node == nullptr){
        return node;
    }
    if (node->data > deleteData){
        node->nextLeftNode = deleteNode(deleteData, node->nextLeftNode);
    }
    else if (node->data < deleteData){
        node->nextRightNode = deleteNode(deleteData, node->nextRightNode);
    }
    else {
        TreeNode<T>* newNode;
        if (node->nextRightNode == nullptr) {
            newNode = node->nextLeftNode;
        }
        else {
            TreeNode<T>* seekNode = node->nextRightNode;
            if (seekNode->nextLeftNode == nullptr) {
                seekNode->nextLeftNode = node->nextLeftNode;
                newNode = seekNode;
            }
            else {
                TreeNode<T>* minNode = seekNode->nextLeftNode;
                while (minNode->nextLeftNode != nullptr) {
                    seekNode = minNode;
                    minNode = seekNode->nextLeftNode;
                }
                seekNode->nextLeftNode = minNode->nextRightNode;
                minNode->nextLeftNode = node->nextLeftNode;
                minNode->nextRightNode = node->nextRightNode;
                newNode = minNode;
            }
        }

        newNode->depth = node->depth;
        delete node;
        return newNode;
    }
    return node;

}

template<typename T>
void Tree<T>::visualize(TreeNode<T>* node) const {
    if (node == nullptr){
        return;
    }
    visualize(node->nextRightNode);

    for (size_t currentDepth = 0; currentDepth < node->depth; ++currentDepth){
        std::cout << '\t';
    }
    std::cout << node->data << std::endl;

    visualize(node->nextLeftNode);
}

template<typename T>
void Tree<T>::linearize(TreeNode<T>* node) {
    if (node == nullptr) { return; }
    linearize(node->nextLeftNode);

    if ((node->nextRightNode != nullptr) && (node != root) && (node->data < this->root->data)) { 
        linear = false; 
        return;
    }

    if (node != root) { return; }

    linearize(node->nextRightNode);

    if ((node->nextLeftNode != nullptr) && (node != root) && (node->data >= this->root->data)) { 
        linear = false; 
        return; 
    }

    if (node == root){
        if (linear){
            std::cout << "This tree is linear!" << std::endl;
        }
        else {
            std::cout << "This tree is not linear" << std::endl;
        }
    }
}

template<typename T>
void Tree<T>::deleteTree(TreeNode<T>* node){
    if(node == nullptr){
        return;
    }

    deleteTree(node->nextLeftNode);
    deleteTree(node->nextRightNode);
    delete node;
}

template<typename T>
Tree<T>::~Tree(){
    deleteTree(root);
    root = nullptr;
}