#include "../include/TreeNode.hpp"

template<typename T>
TreeNode<T>::TreeNode(){
    this->data = T();
    this->nextLeftNode = nullptr;
    this->nextRightNode = nullptr;
}

template<typename T>
TreeNode<T>::TreeNode(const T& data){
    this->data = data;
    this->nextLeftNode = nullptr;
    this->nextRightNode = nullptr;
}

template<typename T>
TreeNode<T>::TreeNode(const T& data, TreeNode* nextLeftNode, TreeNode* nextRightNode){
    this->data = data;
    this->nextLeftNode = nextLeftNode;
    this->nextRightNode = nextRightNode;
}