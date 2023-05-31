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
            size_t midle = end;
            size_t compareElement = start;

            while(compareElement != midle){
                if(compareElement < midle){
                    if(this->table[compareElement].first > this->table[midle].first){
                        std::pair<double, T> tempPair = this->table[midle];
                        this->table[midle] = this->table[compareElement];
                        this->table[compareElement] = tempPair;

                        size_t tempSize = midle;
                        midle = compareElement;
                        compareElement = tempSize;

                        continue;
                    }
                    ++compareElement;
                }
                if(compareElement > midle){
                    if(this->table[compareElement].first < this->table[midle].first){
                        std::pair<double, T> temp = this->table[midle];
                        this->table[midle] = this->table[compareElement];
                        this->table[compareElement] = temp;

                        size_t stemp = midle;
                        midle = compareElement;
                        compareElement = stemp;

                        continue;
                    }
                    --compareElement;
                }
            }

            if(start != midle){
                indexStack.push_back(start);
                indexStack.push_back(midle - 1);
            }
            if(end != midle){
                indexStack.push_back(midle + 1);
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