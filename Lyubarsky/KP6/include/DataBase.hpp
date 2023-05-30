#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Table.hpp"
#include <fstream>
#include <filesystem>

class DataBase{
public:
    DataBase();
    DataBase(std::string&);

    void creatTable();

    void open();
    void print(size_t) const;
    void save();

    void womenStateGrantsCounter(size_t) const;

    ~DataBase();

private:
    std::string name;
    Vector<Table> tables;

    std::ifstream fileReader;
    std::ofstream fileWritter;

};

#include "../src/DataBase.cpp"

#endif