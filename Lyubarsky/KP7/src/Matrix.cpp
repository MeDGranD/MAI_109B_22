#include "../include/Matrix.hpp"

Matrix::Matrix(){
    this->M.push_back(-1);
    this->A.push_back(-1);
}

Matrix::Matrix(const std::string& fileName){

    std::fstream file;
    std::string getterStr;

    file.open(fileName);
    
    while(!file.eof()){
        ++this->n;
        getline(file, getterStr);

        std::istringstream row(getterStr);
        size_t counter = 0;

        for (size_t getterInt; row >> getterInt; ){
           ++counter;

           if (getterInt!=0){

                if(this->M.size()!=this->n){
                    this->M.push_back(this->A.size());
                }
                else{
                    this->A.back() = this->A.size();
                }

                this->A.push_back(counter);
                this->A.push_back(getterInt);
                this->A.push_back(-1);
           }
        }

        if(this->M.size()!=this->n){
            this->M.push_back(-1);
        }

        if(this->m == 0){
            this->m = counter; 
        }
    }

    M.pop_back(); //Because programm also reads before EOF one time
    --this->n;
    file.close();
}

void Matrix::print() const{

    for(size_t currentRow = 0; currentRow < this->M.size(); ++currentRow){

        int64_t pointer = this->M[currentRow];
        size_t currentColumn = 1;

        while(pointer != -1) {

            while(currentColumn != this->A[pointer]){
                std::cout << "0 ";
                ++currentColumn;
            }

            std::cout << this->A[pointer + 1] << ' ';
            pointer = this->A[pointer + 2];
            ++currentColumn;
        }

        while(currentColumn <= this->m){
            std::cout << "0 ";
            ++currentColumn;
        }

        std::cout << std::endl;
    }
}

void Matrix::transpose(){

    Vector<int64_t> newM;
    Vector<int64_t> newA;

    for(size_t currentColumn = 0; currentColumn < this->m; ++currentColumn){

        newM.push_back(-1);

        for(size_t currentRow = 0; currentRow < this->n; ++currentRow){

            int64_t pointer = this->M[currentRow];

            while(pointer != -1){

                if(this->A[pointer] == this->m - currentColumn){

                    if(newM.back() == -1){
                        newM.back() = newA.size();
                    }
                    else{
                        newA.back() = newA.size();
                    }

                    newA.push_back(currentRow + 1);
                    newA.push_back(this->A[pointer + 1]);
                    newA.push_back(-1);
                    break;
                }
                pointer = this->A[pointer + 2];
            }
        }
    }

    this->n = this->m;
    this->m = this->M.size();
    this->M = newM;
    this->A = newA;
}

Matrix& Matrix::operator*=(const int64_t multiplicationInt){

    size_t pointer = 1;

    while(pointer < this->A.size()){
        this->A[pointer] *= multiplicationInt;
        pointer += 3;
    }

    return *this;
}

bool Matrix::isSkewSymmetric() const{

    if (this->m != this->n){
        return false;
    }

    for(size_t currentColumn = 0; currentColumn < this->m; ++currentColumn){

        int64_t pointerRow = this->M[currentColumn];

        while(pointerRow != -1){

            int64_t pointerColumn = this->M[this->A[pointerRow] - 1];

            while(pointerColumn != -1){

                if ((this->A[pointerColumn] == currentColumn + 1)&&(this->A[pointerColumn + 1] == -this->A[pointerRow + 1])){
                    break;
                }

                pointerColumn = this->A[pointerColumn + 2];
            }

            if (pointerColumn == -1){
                return false;
            }

            pointerRow = this->A[pointerRow + 2];
        }
    }
    
    return true;
}