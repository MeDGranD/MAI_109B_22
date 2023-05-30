#include "../include/DataBase.hpp"

DataBase::DataBase(){
    this->name = "default";

    if(std::filesystem::exists(this->name)){
        this->open();
    }
    else{
        this->createTable();
        this->save();
    }
}

DataBase::DataBase(const std::string& name){
    this->name = name;

    if(std::filesystem::exists(this->name)){
        this->open();
    }
    else{
        this->createTable();
        this->save();
    }
}

void DataBase::createTable(){
    this->tables.emplace_back(Vector<std::string>{"name", "lastname", "sex", "group", "IT project", "Programming", "Economics", "Philosophy", "Mathematics"});
}

void DataBase::print(size_t indexOfTable) const{

    for(size_t currentCollum = 0; currentCollum < tables[indexOfTable].collumNames.size(); ++ currentCollum){
        std::cout << tables[indexOfTable].collumNames[currentCollum] << '\t';
    }
    std::cout << std::endl;

    for(size_t currentRow = 0; currentRow < tables[indexOfTable].table.size(); ++currentRow){
        for(size_t currentCollum = 0; currentCollum < tables[indexOfTable].table[currentRow].size(); ++currentCollum){
            std::cout << tables[indexOfTable].table[currentRow][currentCollum] << '\t';
        }
        std::cout << std::endl;
    }
}

void DataBase::open(){

    fileReader.open(static_cast<std::string>(this->name));

    size_t tableCounter;
    size_t rowCounter;
    size_t collumCounter;
    std::string getterStr;

    fileReader >> tableCounter;

    for(size_t currentTable = 0; currentTable < tableCounter; ++currentTable){

        fileReader >> rowCounter >> collumCounter;

        tables.emplace_back();

        for(size_t currentColum = 0; currentColum < collumCounter; ++currentColum){
            fileReader >> getterStr;
            tables[currentTable].collumNames.push_back(getterStr);
        }

        for(size_t currentRow = 0; currentRow < rowCounter; ++currentRow){
            tables[currentTable].table.emplace_back(collumCounter);
            for(size_t currentCollum = 0; currentCollum < collumCounter; ++currentCollum){
                fileReader >> getterStr;
                tables[currentTable].table[currentRow][currentCollum] = getterStr;
            }   
        }
    }

    fileReader.close();

}

void DataBase::save(){

    fileWritter.open(static_cast<std::string>(this->name));
    fileWritter << this->tables.size() << '\n';

    for(size_t currentTable = 0; currentTable < tables.size(); ++currentTable){

        fileWritter << this->tables[currentTable].table.size() << ' ' << this->tables[currentTable].collumNames.size() << '\n';

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

void DataBase::womenStateGrantsCounter(size_t tableIndex) const{

    std::cout << "Set minimumof marks:" << std::endl;
    double minimum;

    std::cin >> minimum;
    size_t counter = 0;

    for(size_t currentRow = 0; currentRow < this->tables[tableIndex].table.size(); ++currentRow){
        if(this->tables[tableIndex].table[currentRow][2] == "female"){
            double average = 0;

            for(size_t currentColum = 4; currentColum < this->tables[tableIndex].collumNames.size(); ++currentColum){
                average += std::stoi(this->tables[tableIndex].table[currentRow][currentColum]);
            }

            average /= (this->tables[tableIndex].collumNames.size() - 4);
            if(average >= minimum){
                ++counter;
            }
        }
    }
    std::cout << counter << '\n';
}
