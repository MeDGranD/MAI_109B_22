#include "DataBase.hpp"

DataBase::DataBase(std::string dataBaseName, bool open){
    this->dataBaseName = dataBaseName;
    if (open){
        dataBaseRead.open(dataBaseName);
        std::string getterLine;
        getline(dataBaseRead, getterLine);
        amountOfTables = std::stoi(getterLine);
        this->tables = new Table*[amountOfTables];
        for (size_t currentTable = 0; currentTable < amountOfTables; ++currentTable){
            std::string name;
            size_t lines;
            size_t collums;
            getline(dataBaseRead, name);
            getline(dataBaseRead, getterLine);
            lines = std::stoi(getterLine);
            getline(dataBaseRead, getterLine);
            collums = std::stoi(getterLine);
            std::string* collumsNames = new std::string[collums];
            for (size_t currentCollum = 0; currentCollum < collums; ++currentCollum){
                getline(dataBaseRead, collumsNames[currentCollum]);
            }
            tables[currentTable] = new Table(collums, collumsNames, name);
            for (size_t currentLine = 0; currentLine < lines; ++currentLine){
                tables[currentTable]->AddLine();
                for (size_t currentCollum = 0; currentCollum < collums; ++currentCollum){
                    std::string value;
                    getline(dataBaseRead, value);
                    tables[currentTable]->ChangeElement(currentLine, currentCollum, value);
                }
            }
            delete[] collumsNames;
        }
        dataBaseRead.close();
        
    }
    else {this->tables = new Table*[0];}
}

int DataBase::getTableNumber(std::string tableName){
    for (size_t currentTable = 0; currentTable < amountOfTables; ++currentTable){
        if (tables[currentTable]->getName()==tableName){
            return currentTable;
        }
    }
    return -1;
}

void DataBase::CREATE(size_t collums, std::string* collumsNames, std::string tableName){
    ++amountOfTables;
    Table** newArr = new Table*[amountOfTables];
    for (size_t currentTable = 0; currentTable < amountOfTables - 1; ++currentTable){
        newArr[currentTable] = tables[currentTable];
    }
    newArr[amountOfTables - 1] = new Table(collums, collumsNames, tableName);
    delete[] tables;
    tables = newArr;
}

void DataBase::Save(){
    dataBaseWrite.open(dataBaseName);
    dataBaseWrite << amountOfTables << std::endl;
    for (size_t currentTable = 0; currentTable < amountOfTables; ++currentTable){
        dataBaseWrite << tables[currentTable]->GetDescription();
        tables[currentTable]->SaveWrite(dataBaseWrite);
    }
    dataBaseWrite.close();
}

void DataBase::DELETE(std::string deleteName){
    --amountOfTables;
    Table** newArr = new Table*[amountOfTables];
    int deletedTable = 0;
    for (size_t currentTable = 0; currentTable < amountOfTables; ++currentTable){
        if(tables[currentTable]->getName()==deleteName){++deletedTable; delete tables[currentTable];}
        newArr[currentTable] = tables[currentTable + deletedTable];
    }
    delete[] tables;
    tables = newArr;
}

DataBase::~DataBase(){
    this->Save();
    for (size_t currentTable = 0; currentTable < amountOfTables; ++currentTable){
        delete tables[currentTable];
    }
    delete[] tables;
}