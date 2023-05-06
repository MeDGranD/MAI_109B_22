#include "../include/Deque.hpp"

template<typename T>
deque<T>::deque(){

    this->chunks.resize(2);
    this->start = 6;
    this->size = 0;

}

template<typename T>
deque<T>::deque(const size_t size, const T& value): deque() {
    this->resize(size, value);
};

template<typename T>
deque<T>::deque(const std::initializer_list<T>& list): deque(){
    for (T elem : list){
        this->push_back(elem);
    }
}

template<typename T>
deque<T>::deque(const deque<T>& other): deque(){
    this->chunks = other.chunks;
    this->size = other.size;
    this->start = other.start;
}

template<typename T>
deque<T>& deque<T>::operator=(const deque<T>& other){
    this->chunks = other.chunks;
    this->size = other.size;
    this->start = other.start;
    return *this;
}

template<typename T>
void deque<T>::resize(const size_t newSize, const T& value){

    if (this->size < newSize){
        for(size_t currentValue = this->size + newSize; currentValue < this->start + this->size; ++currentValue){
            this->chunks[currentValue/6][currentValue%6].~T();
        }
        return;
    }

    size_t freeSpace = this->chunks.size() * 6 - (this->size + this->start);
    size_t neededSpace = newSize - this->size;

    if (freeSpace < neededSpace){
        this->chunks.resize(this->chunks.size() *3 / 2);
    }

    for (size_t currentValue = this->start + this->size; currentValue < this->start + newSize; ++currentValue){
        new(this->chunks[currentValue/6] + currentValue%6)  T(value);
    }
    this->size = newSize;
}

template<typename T>
size_t deque<T>::Size() const{
    return this->size;
}

template<typename T>
void deque<T>::push_back(const T& value) {

    if (this->start + this->size >= this->chunks.size() * 6){
        this->chunks.resize(this->chunks.size() * 3 / 2);
    }
    size_t index = this->size + this->start;
    new(this->chunks[index/6] + index%6) T(value);
    ++this->size;
}

template<typename T>
void deque<T>::push_front(const T& value){
    if(this->start == 0){
        Vector<Deque::chunk<T>> newChunks(this->chunks.size() * 3 / 2);
        for (size_t currentValue = this->start; currentValue < this->size + this->start; ++currentValue){
            size_t newIndex = (newChunks.size() - this->chunks.size()) * 6 + currentValue;
            new(newChunks[newIndex/6] + newIndex%6) T(this->chunks[currentValue/6][currentValue%6]);
        }
        this->start = (newChunks.size() - this->chunks.size()) * 6;
        this->chunks = newChunks;
    }
    --this->start;
    ++this->size;
    new(this->chunks[this->start/6] + this->start%6) T(value);
}

template<typename T>
template<typename ...Args>
void deque<T>::emplace_back(const Args&...args){
    if (this->start + this->size >= this->chunks.size() * 6){
        this->chunks.resize(this->chunks.size() * 3 / 2);
    }
    size_t index = this->size + this->start;
    new(this->chunks[index/6] + index%6) T(args...);
    ++this->size;
}

template<typename T>
template<typename ...Args>
void deque<T>::emplace_front(const Args&...args){
    if(this->start == 0){
        Vector<Deque::chunk<T>> newChunks(this->chunks.size() * 3 / 2);
        for (size_t currentValue = this->start; currentValue < this->size + this->start; ++currentValue){
            size_t newIndex = (newChunks.size() - this->chunks.size()) * 6 + currentValue;
            new(newChunks[newIndex/6] + newIndex%6) T(this->chunks[currentValue/6][currentValue%6]);
        }
        this->start = (newChunks.size() - this->chunks.size()) * 6;
        this->chunks = newChunks;
    }

    --this->start;
    ++this->size;
    new (this->chunks[this->start/6] + this->start%6)  T(args...);
}

template<typename T>
void deque<T>::pop_back(){
    size_t index = this->size + this->start - 1;
    this->chunks[index/6][index%6].~T();
    --this->size;
}

template<typename T>
void deque<T>::pop_front(){
    this->chunks[this->start/6][this->start%6].~T();
    ++this->start;
    --this->size;
}

template<typename T>
T& deque<T>::front() const{
    return this->chunks[this->start/6][this->start%6];
}

template<typename T>
T& deque<T>::back() const{
    return this->chunks[(this->start + this->size - 1)/6][(this->start + this->size - 1)%6];
}

template<typename T>
Deque::iterator<T> deque<T>::begin() const{
    return Deque::iterator<T>(*this);
}

template<typename T>
Deque::iterator<T> deque<T>::end() const{
    Deque::iterator<T> returnIterator(*this);
    returnIterator.currentIndex = this->start + this->size;
    return returnIterator;
}

template<typename T>
void deque<T>::sort(const Deque::iterator<T>& start, const Deque::iterator<T>& end){

    if(end < start) return;
    if(start.currentDeque == nullptr){
        this->sort(this->begin(), --this->end());
    }

    Deque::iterator<T> compare(start);
    Deque::iterator<T> pivot(end);
    
    while(compare != pivot){
        if (compare > pivot){
            if (*compare < *pivot){

                T tempValue = *pivot;
                size_t tempPointer = pivot.currentIndex;

                *pivot = *compare;
                *compare = tempValue;
                
                pivot.currentIndex = compare.currentIndex;
                compare.currentIndex = tempPointer;

                continue;
            }
            --compare;
        }
        if(compare < pivot){
            if(*compare >= *pivot){

                T tempValue = *pivot;
                size_t tempPointer = pivot.currentIndex;

                *pivot = *compare;
                *compare = tempValue;
                
                pivot.currentIndex = compare.currentIndex;
                compare.currentIndex = tempPointer;

                continue;
            }
            ++compare;
        }
    }
    if((end.currentIndex-start.currentIndex)>=2){
        this->sort(start, --pivot);
        this->sort(++++pivot, end);
    }

}

template<typename T>
deque<T> deque<T>::operator+(const deque<T>& other) const{
    deque<T> returnDeque(this->size + other.size);
    for(Deque::iterator<T> it(other); it < other.end(); ++it){
        returnDeque.push_back(T(*it));
    }
    for(Deque::iterator<T> it(*this); it < this->end(); ++it){
        returnDeque.push_back(T(*it));
    }
    returnDeque.sort();
    return returnDeque;
}

template<typename T>
deque<T>& deque<T>::operator+=(const deque<T>& other){
    this->resize(this->size + other.size);
    for(Deque::iterator<T> it(other); it < other.end(); ++it){
        this->push_back(T(*it));
    }
    this->sort();
    return *this;
}

namespace Deque{
    template<typename T>
    chunk<T>::chunk(){
        this->array = reinterpret_cast<T*>(new char[sizeof(T)*6]);
    }
    template<typename T>
    chunk<T>::chunk(const chunk<T>& other): chunk(){
        for(size_t currentValue = 0; currentValue < 6; ++currentValue){
            new(this->array + currentValue) T(other.array[currentValue]);
        }
    }
    template<typename T>
    chunk<T>& chunk<T>::operator=(const chunk<T>& other){
        for(size_t currentValue = 0; currentValue < 6; ++currentValue){
            this->array[currentValue].~T();
            new(this->array + currentValue) T(other.array[currentValue]);
        }
    }
    template<typename T>
    template<typename Y>
    T* chunk<T>::operator+(const Y plus) const{
        return (this->array + plus);
    }
    template<typename T>
    T& chunk<T>::operator[](const size_t index) const{
        return array[index];
    }
    template<typename T>
    chunk<T>::~chunk(){
        delete[] reinterpret_cast<char*>(this->array);
    }



    template<typename T>
    iterator<T>::iterator(){
        this->currentDeque = nullptr;
        this->currentIndex = 0;
    }
    template<typename T>
    iterator<T>::iterator(const deque<T>& deque) : currentDeque(&deque){
        this->currentIndex = deque.start;
    }
    template<typename T>
    iterator<T>::iterator(const iterator<T>& other): currentDeque(other.currentDeque){
        this->currentIndex = other.currentIndex;
    }
    template<typename T>
    iterator<T>& iterator<T>::operator=(const iterator<T>& other){
        this->currentDeque = other.currentDeque;
        this->currentIndex = other.currentIndex;
        return *this;
    }
    template<typename T>
    T& iterator<T>::operator*() const{
        return currentDeque->chunks[this->currentIndex/6][this->currentIndex%6];
    }
    template<typename T>
    iterator<T>& iterator<T>::operator++(){
        ++this->currentIndex;
        return *this;
    }
    template<typename T>
    iterator<T>& iterator<T>::operator--(){
        --this->currentIndex;
        return *this;
    }
    template<typename T>
    iterator<T> iterator<T>::operator+(const iterator<T> other){
        iterator<T> returnIterator(*this);
        returnIterator.currentIndex += other.currentIndex;
        return returnIterator;
    }
    template<typename T>
    iterator<T> iterator<T>::operator-(const iterator<T> other){
        iterator<T> returnIterator(*this);
        returnIterator.currentIndex -= other.currentIndex;
        return returnIterator;
    }
    template<typename T>
    bool iterator<T>::operator>(const iterator<T>& other) const{
        if(this->currentIndex > other.currentIndex){
            return true;
        }
        return false;
    }
    template<typename T>
    bool iterator<T>::operator>=(const iterator<T>& other) const{
        if(this->currentIndex >= other.currentIndex){
            return true;
        }
        return false;
    }
    template<typename T>
    bool iterator<T>::operator<(const iterator<T>& other) const{
        if(this->currentIndex < other.currentIndex){
            return true;
        }
        return false;
    }
    template<typename T>
    bool iterator<T>::operator<=(const iterator<T>& other) const{
        if(this->currentIndex <= other.currentIndex){
            return true;
        }
        return false;
    }
    template<typename T>
    bool iterator<T>::operator==(const iterator<T>& other) const{
        if(this->currentDeque == other.currentDeque){
            if(this->currentIndex == other.currentIndex){
                return true;
            }
        }
        return false;
    }
    template<typename T>
    bool iterator<T>::operator!=(const iterator<T>& other) const{
        return !(*this == other);
    }
}