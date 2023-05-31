#include "../include/Iterator.hpp"

template<typename T>
iterator<T>::iterator(){
    this->currentNode = nullptr;
}

template<typename T>
iterator<T>::iterator(const List<T>& list){
    this->currentNode = list.start;
}

template<typename T>
iterator<T>::iterator(node<T>* node){
    this->currentNode = node;
}

template<typename T>
iterator<T>& iterator<T>::operator++(){
    this->currentNode = this->currentNode->nextNode;
    return *this;
}

template<typename T>
T& iterator<T>::operator*() const{
    return this->currentNode->data;
}

template<typename T>
iterator<T> iterator<T>::operator+(size_t size){
    iterator<T> returnIterator(*this);
    while(size != 0){
        ++returnIterator;
        --size;
    }
    return returnIterator;
}

template<typename T>
bool iterator<T>::operator==(const iterator<T>& other) const{
    return (other.currentNode == this->currentNode);
}

template<typename T>
bool iterator<T>::operator!=(const iterator<T>& other) const{
    return !(*this == other);
}