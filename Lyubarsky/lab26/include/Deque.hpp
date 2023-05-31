#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "../lib/Vector.hpp"

namespace Deque{

    template<typename T>
    struct chunk;

    template<typename T>
    class iterator;
}

const size_t chunkSize = 6;
const size_t resizeConst = 2;

template<typename T>
class deque{
    friend struct Deque::iterator<T>;
public:

    deque();
    deque(const size_t, const T& = T());
    deque(const std::initializer_list<T>&);
    deque(const deque<T>&);
    deque<T>& operator=(const deque<T>&);

    void resize(const size_t, const T& = T());
    size_t size() const;

    void push_back(const T&);
    void push_front(const T&);

    template<typename ...Args>
    void emplace_back(const Args&...);
    template<typename ...Args>
    void emplace_front(const Args&...);

    void pop_back();
    void pop_front();

    T& front() const;
    T& back() const;

    Deque::iterator<T> begin() const;
    Deque::iterator<T> end() const;
    
    void sort(const Deque::iterator<T>& = Deque::iterator<T>(), const Deque::iterator<T>& = Deque::iterator<T>());
    deque<T> operator+(const deque<T>&) const;
    deque<T>& operator+=(const deque<T>&);

private:
    Vector<Deque::chunk<T>> chunks;
    size_t start;
    size_t size_;
};

namespace Deque{

    template<typename T>
    struct chunk{
        T* array;

        chunk();
        chunk(const chunk<T>&);
        chunk<T>& operator=(const chunk<T>&);

        T* operator+(const size_t) const;
        T& operator[](const size_t) const;

        ~chunk();
    };

    template<typename T>
    class iterator{
        friend class deque<T>;
    public:
        iterator();
        iterator(const deque<T>&);
        iterator(const iterator<T>&);
        iterator<T>& operator=(const iterator<T>& other);

        T& operator*() const;
        iterator<T>& operator++();
        iterator<T>& operator--();
        iterator<T> operator+(const iterator<T> other);
        iterator<T> operator-(const iterator<T> other);

        bool operator>(const iterator<T>&) const;
        bool operator>=(const iterator<T>&) const;
        bool operator<(const iterator<T>&) const;
        bool operator<=(const iterator<T>&) const;
        bool operator==(const iterator<T>&) const;
        bool operator!=(const iterator<T>&) const;
        
    private:
        const deque<T>* currentDeque;
        size_t currentIndex; 
    };
}

#include "../src/Deque.cpp"

#endif