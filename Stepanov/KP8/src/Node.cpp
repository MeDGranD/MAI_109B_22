#include "../include/Node.hpp"


template<typename T>
Node<T>::Node(const T &val)
{
    data = val;
    prev = nullptr;
    next = nullptr;
}
