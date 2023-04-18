#pragma once

#include <filesystem>
#include "Table.hpp"

class DataBase{
public:
    DataBase(std::string, bool);
    int getTableNumber(std::string);
    void Save();
    void CREATE(size_t, std::string*, std::string = "default");
    void DELETE(std::string);
    std::string getName() {return dataBaseName;}
    ~DataBase();

    Table** tables;
private:
    std::ifstream dataBaseRead;
    std::ofstream dataBaseWrite;

    std::string dataBaseName;
    size_t amountOfTables = 0;
};