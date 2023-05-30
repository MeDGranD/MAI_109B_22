#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Table.hpp"
#include <fstream>
#include <filesystem>

class DataBase{
public:
    DataBase();
    DataBase(std::string&);

    void open();
    void print(size_t) const;
    void save();

    //void womenStateGrantsCounter();

    ~DataBase();

private:
    std::string name;
    Vector<Table> tables;

    std::ifstream fileReader;
    std::ofstream fileWritter;

};

#endif