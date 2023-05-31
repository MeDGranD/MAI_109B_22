#include "../include/Table.hpp"

template<typename T>
void Table<T>::push_back(const std::pair<double, T>& elem){
    this->table.push_back(elem);
}

template<typename T>
void Table<T>::print() const{
    for(size_t currentElement = 0; currentElement < this->table.size(); ++currentElement){
        std::cout << this->table[currentElement].first << ' ' << this->table[currentElement].second << '\n';
    }
}

template<typename T>
void Table<T>::sort(){

    deque<size_t> indexStack;
    indexStack.push_back(0);
    indexStack.push_back(this->table.size() - 1);

    while(indexStack.size() != 0){

        size_t end = indexStack.back();
        indexStack.pop_back();
        size_t start = indexStack.back();
        indexStack.pop_back();

        if((end - start) > 1){
            size_t middle = end;
            size_t compareElement = start;

            while(compareElement != middle){
                if(compareElement < middle){
                    if(this->table[compareElement].first > this->table[middle].first){
                        std::pair<double, T> tempPair = this->table[middle];
                        this->table[middle] = this->table[compareElement];
                        this->table[compareElement] = tempPair;

                        size_t tempSize = middle;
                        middle = compareElement;
                        compareElement = tempSize;

                        continue;
                    }
                    ++compareElement;
                }
                if(compareElement > middle){
                    if(this->table[compareElement].first < this->table[middle].first){
                        std::pair<double, T> temp = this->table[middle];
                        this->table[middle] = this->table[compareElement];
                        this->table[compareElement] = temp;

                        size_t stemp = middle;
                        middle = compareElement;
                        compareElement = stemp;

                        continue;
                    }
                    --compareElement;
                }
            }

            if(start != middle){
                indexStack.push_back(start);
                indexStack.push_back(middle - 1);
            }
            if(end != middle){
                indexStack.push_back(middle + 1);
                indexStack.push_back(end);
            }
        }
        else{
            if(this->table[start].first > this->table[end].first){
                std::pair<double, T> temp = this->table[start];
                this->table[start] = this->table[end];
                this->table[end] = temp;
            }
        }
        
    }
}
