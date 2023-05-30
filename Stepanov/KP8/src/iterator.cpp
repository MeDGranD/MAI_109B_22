#include "../include/iterator.hpp"

template<typename T>
Iterator<T>::Iterator(Node<T> *_node)
{
    node = _node;
}
template<typename T>
Iterator<T> Iterator<T>::operator++()
{
    if (node) {//
        node = node->next;
    }
    return *this;
}
template<typename T>
Iterator<T> Iterator<T>::operator--()
{
    if (node) {//
        node = node->prev;
    }
    return *this;
}


template<typename T>
Iterator<T> Iterator<T>::operator+(int64_t value)
{
    if (node) {
        if (value > 0) {
            do {
                --value;
                node = node->next;
            } while (value && node);
        }
        else if (value < 0) {

            do {
                ++value;

                node = node->prev;

            } while (value && node);
        }
    }
    return *this;
}
template<typename T>
Iterator<T> Iterator<T>::operator-(int64_t value)
{

    return *this + (-1 * value);
}
template<typename T>
Node<T> *Iterator<T>::get_node()
{
    return node;
}

template<typename T>
bool Iterator<T>::operator==(Iterator<T> b)
{
    return this->node == b.node;
}
template<typename T>
bool Iterator<T>::operator!=(Iterator<T> b)
{
    return !(this->node == b.node);
}
template<typename T>
T &Iterator<T>::operator*()
{
    return node->data;
}
template<typename T>
T &Iterator<T>::operator*() const
{
    return node->data;
}
