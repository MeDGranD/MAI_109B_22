#include "Table.hpp"

Table::Table(size_t size, std::string* collumsNames, std::string name){
    this->lines = 0;
    this->collums = size;
    this->name = name;
    this->collumsNames = new std::string[size];
    this->tableElements = new std::string*[0];
    for (size_t currentCollum = 0; currentCollum < collums; ++currentCollum){
        this->collumsNames[currentCollum] = collumsNames[currentCollum];
    }
}

int Table::getCollumNumber(std::string collumName){
    for (size_t currentCollum = 0; currentCollum < collums; ++currentCollum){
        if (collumsNames[currentCollum] == collumName) {
            return currentCollum;
        }
    }
    return -1;
}

void Table::AddLine(){
    ++lines;
    std::string** newArr = new std::string*[lines];
    newArr[lines-1] = new std::string[collums];
    for (size_t currentLine = 0; currentLine < lines - 1; ++currentLine){
        newArr[currentLine] = tableElements[currentLine];
    }
    delete[] tableElements;
    tableElements = newArr; 
    for (size_t currentCollum = 0; currentCollum < collums; ++currentCollum){
        ChangeElement(lines-1, currentCollum, "none");
    }
}

void Table::DeleteLine(size_t line){
    --lines;
    std::string** newArr = new std::string*[lines];
    int deletedLine = 0;
    for (size_t currentLine = 0; currentLine < lines; ++currentLine){
        if (currentLine == line) {
            deletedLine = 1;
            delete[] tableElements[currentLine];
        }
        newArr[currentLine] = tableElements[currentLine + deletedLine];
    }
    delete[] tableElements;
    tableElements = newArr;

}

std::string* Table::ReadLine(size_t line){
    return tableElements[line];
}

void Table::ChangeElement(size_t line, size_t collum, std::string element){
    tableElements[line][collum] = element;
}

void Table::WriteTable(){
    for (size_t currentCollum = 0; currentCollum < collums; ++currentCollum) { std::cout << collumsNames[currentCollum] << ' '; }
    std::cout << std::endl;
    for(size_t currentLine = 0; currentLine < lines; ++currentLine){
        for(size_t currentCollum = 0; currentCollum < collums; ++currentCollum){
            std::cout << tableElements[currentLine][currentCollum] << ' ';
        }
        std::cout << std::endl;
    }
}

std::string Table::GetDescription(){
    std::string getterString = "";
    getterString += name + '\n' + std::to_string(lines) + '\n' + std::to_string(collums) + '\n';
    for (size_t currentCollum = 0; currentCollum < collums; ++currentCollum){
        getterString += collumsNames[currentCollum] + '\n';
    }
    return getterString;
}

void Table::SaveWrite(std::ofstream& fileIn){
    for (size_t currentLine = 0; currentLine < lines; ++currentLine){
        for (size_t currentCollum = 0; currentCollum < collums; ++currentCollum){
            fileIn << tableElements[currentLine][currentCollum] << std::endl;
        }
    }
}

Table::~Table(){
    delete[] collumsNames;
    for (size_t currentLine = 0; currentLine < lines; ++currentLine){
        delete[] tableElements[currentLine];
    }
    delete[] tableElements;
}