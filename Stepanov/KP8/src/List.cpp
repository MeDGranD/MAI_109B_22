#include "../include/List.hpp"


template<typename T>
List<T>::List()
{
    barrier = new Node<T>();
    barrier->next = barrier;
    barrier->prev = barrier;
    sz = 0;
}
template<typename T>
List<T>::~List()
{
    Node<T> *var_i = barrier->next;
    while (var_i != barrier) {
        Node<T> *temp_node = var_i;
        var_i = var_i->next;
        delete temp_node;
    }
    delete barrier;
    barrier = nullptr;
    sz = 0;
}
template<typename T>
Iterator<T> List<T>::begin()
{
    Iterator<T> temp(barrier->next);
    return temp;
}
template<typename T>
Iterator<T> List<T>::end()
{
    Iterator<T> temp(barrier);
    return temp;
}
template<typename T>
bool List<T>::empty()
{
    Iterator<T> first = this->begin();
    Iterator<T> last = this->end();
    return first == last;
}
template<typename T>
size_t List<T>::size() const
{
    return sz;
}
template<typename T>
Iterator<T> List<T>::insert(Iterator<T> insert_iter, const T &data)
{
    T tdata = data;
    Node<T> *temp_node = new Node<T>(tdata);
    temp_node->next = insert_iter.node;
    temp_node->prev = insert_iter.node->prev;
    temp_node->prev->next = temp_node;
    insert_iter.node->prev = temp_node;
    sz++;

    return Iterator<T>(temp_node);
}
template<typename T>
Iterator<T> List<T>::erase(Iterator<T> erase_iter)
{
    Iterator<T> res = this->end();
    if (res == erase_iter) {
        return res;
    }
    res.node = erase_iter.node->next;
    res.node->prev = erase_iter.node->prev;
    erase_iter.node->prev->next = res.node;
    sz--;
    delete erase_iter.get_node();
    return res;
}
template<typename T>
Iterator<T> List<T>::erase(Iterator<T> begin, Iterator<T> end)
{
    Iterator<T> res = begin;
    while (!(res == end)) {
        this->erase(res);
        ++res;
    }
    return res;
}
template<typename T>
void List<T>::push_back(const T &value)
{
    insert(this->end(), value);
}
template<typename T>
void List<T>::push_front(const T &value)
{
    insert(this->begin(), value);
}
template<typename T>
void List<T>::pop_back()
{
    erase(--(this->end()));
}
template<typename T>
void List<T>::pop_front()
{
    erase((this->begin()));
}
template<typename T>
void List<T>::emplace_back(){}
template<typename T>
template<typename... Args>
void List<T>::emplace_back(const T &First, const Args &...args)
{
    push_back(First);
    emplace_back(args...);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, List<T> &x)
{
    for (Iterator<T> temp_i = x.begin(); temp_i != x.end(); ++temp_i) {
        out << *temp_i << '\n';
    }
    return out;
}
template<typename T>
Iterator<T> List<T>::search(const T &value)
{
    for (Iterator<T> temp_i = this->begin(); temp_i != this->end(); ++temp_i) {
        if (temp_i.fetch() == value) {
            return temp_i;
        }
    }
    return this->end();
}
template<typename T>
void List<T>::lab_swap(const size_t k)
{
    Iterator<T> temp_it = this->begin();
    size_t counter = 0;
    while (temp_it != this->end()) {
        ++counter;
        if (counter == k) {
            break;
        }
        ++temp_it;
    }
    if (temp_it == this->end()) {
        return;
    }
    Iterator<T> it_prev = --temp_it;
    Iterator<T> it_next = temp_it + 2;
    if (it_prev == this->end() || it_next == this->end()) {
        return;
    }
    T temp_copy_n = *it_next;
    T temp_copy_p = *it_prev;
    *it_next = temp_copy_p;
    *it_prev = temp_copy_n;
}
