#include "../include/Table.hpp"

Table::Table(Vector<std::string>& collumNames){
    this->collumNames = collumNames;
}

void Table::addRow(Vector<std::string>& row){
    this->table.push_back(row);
}