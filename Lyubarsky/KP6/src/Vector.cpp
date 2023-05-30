#include "../include/Vector.hpp"

template<typename T>
Vector<T>::Vector(){
    this->Array = reinterpret_cast<T*>(new char[sizeof(T)]);
    this->arraySize = 0;
    this->arrayCapacity = 1;
}

template<typename T>
Vector<T>::Vector(const size_t startSize, const T& value): Vector(){
    this->resize(startSize, value);
}

template<typename T>
Vector<T>::Vector(const Vector<T>& otherVector): Vector(){
    this->resize(otherVector.size());

    for (size_t currentValue = 0; currentValue < this->arraySize; ++currentValue){
        this->Array[currentValue].~T();
        new(this->Array + currentValue) T(otherVector[currentValue]);
    }
}

template<typename T>
Vector<T>::Vector(const std::initializer_list<T>& initList): Vector(){

    T* newArray = reinterpret_cast<T*>(new char[initList.size() * sizeof(T)]);

    try{
        std::uninitialized_copy(initList.begin(), initList.end(), newArray);
    }
    catch(...){
        delete[] reinterpret_cast<char*>(newArray);
        throw;
    }

    delete[] reinterpret_cast<char*>(this->Array);
    this->Array = newArray;
    this->arraySize = initList.size();
    this->arrayCapacity = this->arraySize;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rightVector){

    if (this == &rightVector){
        return *this;
    }

    this->resize(rightVector.size());
    for (size_t currentValue = 0; currentValue < this->arraySize; ++currentValue){
        this->Array[currentValue].~T();
        new(this->Array + currentValue) T(rightVector[currentValue]);
    }

    return *this;
}

template<typename T>
void Vector<T>::reserve(const size_t newCapacity) {

    T* newArray = reinterpret_cast<T*>(new char[newCapacity * sizeof(T)]);

    try{
        if(newCapacity > this->arrayCapacity){
            std::uninitialized_copy(this->Array, this->Array + this->arraySize, newArray);
        }
        else{
            std::uninitialized_copy(this->Array, this->Array + newCapacity, newArray);
        }
    }
    catch(...){
        delete[] reinterpret_cast<char*>(this->Array);
        throw;
    }

    for (size_t currentValue = 0; currentValue < this->arraySize; ++currentValue){
        this->Array[currentValue].~T();
    }

    delete[] reinterpret_cast<char*>(this->Array);
    this->Array = newArray;
    this->arrayCapacity = newCapacity;
}

template<typename T>
void Vector<T>::resize(const size_t newSize, const T& value){

    if (this->arraySize > newSize) { 
	for (size_t deleteValue = newSize; deleteValue < this->arraySize; ++deleteValue){
		this->Array[deleteValue].~T();
	}
	this->arraySize = newSize;
    	return;
    }

    if (newSize > this->arrayCapacity){
        this->reserve(newSize * 2);
    }

    for (size_t currentValue = this->arraySize; currentValue < newSize; ++currentValue){
        new(this->Array + currentValue) T(value);
    }
    this->arraySize = newSize;
}

template<typename T>
void Vector<T>::push_back(const T& pushData){
    this->resize(this->arraySize + 1, pushData);
}

template<typename T>
template<typename ...Args>
void Vector<T>::emplace_back(const Args&...args){

    if (this->arraySize == this->arrayCapacity){
        this->reserve(this->arrayCapacity * 2);
    }

    new(this->Array + this->arraySize) T(args...);
    ++this->arraySize;
}

template<typename T>
void Vector<T>::pop_back(){
    if (this->arraySize == 0){
        return;
    }
    this->resize(this->arraySize - 1);
}

template<typename T>
T& Vector<T>::at(const size_t index) const{
    if ((index >= this->arraySize)||(index < 0)){
        throw std::exception("Incorrect vector index!");
    }
    return this->Array[index];
}

template<typename T>
T& Vector<T>::operator[](const size_t index) const{
    return this->Array[index];
}

template<typename T>
T& Vector<T>::front() const{
    return this->Array[0];
}

template<typename T>
T& Vector<T>::back() const{
    return this->Array[this->arraySize - 1];
}

template<typename T>
bool Vector<T>::empty() const{
    return this->arraySize == 0;
}

template<typename T>
size_t Vector<T>::size() const{
    return this->arraySize;
}

template<typename T>
size_t Vector<T>::capacity() const{
    return this->arrayCapacity;
}

template<typename T>
void Vector<T>::shrink_to_fit(){
    if (this->arraySize == 0){
        this->reserve(1);
        return;
    }
    this->reserve(this->arraySize);
}

template<typename T>
void Vector<T>::clear(){
    this->resize(0);
}

template<typename T>
bool Vector<T>::operator==(const Vector<T>& otherVector) const{

    if (otherVector.size() != this->arraySize){
        return false;
    }

    for (size_t currentValue = 0; currentValue < this->arraySize; ++currentValue){
        if (otherVector[currentValue] != this->Array[currentValue]){
            return false;
        }
    }
    return true;
}

template<typename T>
bool Vector<T>::operator!=(const Vector<T>& otherVector) const{
    return !this->operator==(otherVector);
}

template<typename T>
Vector<T>::~Vector(){
    for (size_t currentValue = 0; currentValue < this->arraySize; ++currentValue){
        Array[currentValue].~T();
    }
    delete[] reinterpret_cast<char *>(this->Array);
}
