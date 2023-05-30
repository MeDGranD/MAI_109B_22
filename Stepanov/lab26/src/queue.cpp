#include "../include/queue.hpp"
template<typename T>
void Queue<T>::push(const T &value)
{
    vector_in.push_back(value);
}
template<typename T>
size_t Queue<T>::size()
{
    return vector_in.size() + vector_out.size();
}
template<typename T>
bool Queue<T>::empty()
{
    return vector_in.empty() && vector_out.empty();
}
template<typename T>
T &Queue<T>::front()
{
    if (!vector_out.empty()) {
        return vector_out[vector_out.size() - 1];
    }
    else {
        return vector_in[0];
    }
}
template<typename T>
T &Queue<T>::back()
{
    if (!vector_in.empty())
        return vector_in[vector_in.size() - 1];
    else {
        return vector_out[0];
    }
}
template<typename T>
template<typename... Args>
void Queue<T>::emplace(const Args &...args)
{
    vector_in.emplace_back(args...);
}
template<typename T>
void Queue<T>::pop()
{
    if (this->size() > 0) {

        if (vector_out.empty()) {
            while (!vector_in.empty()) {
                vector_out.push_back(vector_in.back());
                vector_in.pop_back();
            }
        }
        vector_out.pop_back();
    }
}
template<typename T>
bool Queue<T>::resurface()
{
    bool sorted = true;
    T buffer_var;
    for (size_t i = 0; i < this->size() - 1; ++i) {
        buffer_var = this->front();
        this->pop();
        if (this->front() >= buffer_var) {
            this->push(buffer_var);
        }
        else {
            this->push(this->front());
            this->front() = buffer_var;
            sorted = false;
        }
    }
    this->push(this->front());
    this->pop();
    return sorted;
}
template<typename T>
void Queue<T>::sort()
{
    while (!resurface()) {
    }
}
