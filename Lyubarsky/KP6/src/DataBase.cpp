#include "../include/DataBase.hpp"

DataBase::DataBase(){
    this->name = "default";
    if(std::filesystem::exists(name)){
        this->open();
    }
    else{
        this->tables.emplace_back(Vector<std::string>{"name", "lastname", "sex", "group", "IT project", "Programming", "Economics", "Philosophy", "Mathematics"});
        this->save();
    }
}

DataBase::DataBase(std::string& name){
    this->name = name;
    if(std::filesystem::exists(name)){
        this->open();
    }
    else{
        this->tables.emplace_back(Vector<std::string>{"name", "lastname", "sex", "group", "IT project", "Programming", "Economics", "Philosophy", "Mathematics"});
        this->save();
    }
}

void DataBase::print(size_t indexOfTable) const{
    for(size_t currentCollum = 0; currentCollum < tables[indexOfTable].collumNames.size(); ++ currentCollum){
        std::cout << tables[indexOfTable].collumNames[currentCollum] << ' ';
    }
    std::cout << std::endl;

    for(size_t currentRow = 0; currentRow < tables[indexOfTable].table.size(); ++currentRow){
        for(size_t currentCollum = 0; currentCollum < tables[indexOfTable].table[currentRow].size(); ++currentCollum){
            std::cout << tables[indexOfTable].table[currentRow][currentCollum] << ' ';
        }
        std::cout << std::endl;
    }
}

void DataBase::open(){
    fileReader.open(this->name);
    size_t tableCounter;
    fileReader >> tableCounter;

    for(size_t currentTable = 0; currentTable < tableCounter; ++currentTable){
        size_t rowCounter;
        size_t collumCounter;
        fileReader >> rowCounter >> collumCounter;

        std::string getterStr;

        tables.emplace_back();
        for(size_t currentColum = 0; currentColum < collumCounter; ++currentColum){
            std::string getterStr;
            fileReader >> getterStr;
            tables[currentTable].collumNames.push_back(getterStr);
        }

        for(size_t currentRow = 0; currentRow < rowCounter; ++currentRow){
            tables[currentTable].table.emplace_back(collumCounter);
            for(size_t currentCollum = 0; currentCollum < collumCounter; ++currentCollum){
                std::string getterStr;
                fileReader >> getterStr;
                tables[currentTable].table[currentRow][currentCollum] = getterStr;
            }   
        }
    }

    fileReader.close();

}

void DataBase::save(){
    fileWritter << this->tables.size() << '\n';

    for(size_t currentTable = 0; currentTable < tables.size(); ++currentTable){
        fileWritter << this->tables[currentTable].table.size() << ' ' << this->tables[currentTable].table[0].size() << '\n';

        for(size_t currentCollum = 0; currentCollum < tables[currentTable].collumNames.size(); ++ currentCollum){
            fileWritter << tables[currentTable].collumNames[currentCollum] << ' ';
        }
        fileWritter << std::endl;

        for(size_t currentRow = 0; currentRow < tables[currentTable].table.size(); ++currentRow){
            for(size_t currentCollum = 0; currentCollum < tables[currentTable].table[currentRow].size(); ++currentCollum){
                fileWritter << tables[currentTable].table[currentRow][currentCollum] << ' ';
            }
        fileWritter << std::endl;
    }
    }

    fileWritter.close();
}

DataBase::~DataBase(){
    this->save();
}