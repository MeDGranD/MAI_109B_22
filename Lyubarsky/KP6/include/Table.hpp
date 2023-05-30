#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>
#include "Vector.hpp"

class DataBase;

class Table{
    friend class DataBase;
public:
    Table(){}
    Table(Vector<std::string>&);
    void addRow(Vector<std::string>&);
private:
    Vector<std::string> collumNames;
    Vector<Vector<std::string>> table;
};

#endif