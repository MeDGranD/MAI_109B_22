#include "../include/Node.hpp"

template<typename T>
node<T>::node(const T& value, node<T>* next){
    this->nextNode = next;
    this->data = value;
}