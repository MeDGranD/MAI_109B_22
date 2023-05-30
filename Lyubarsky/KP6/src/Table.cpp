#include "../include/Table.hpp"

Table::Table(const Vector<std::string>& collumNames){
    this->collumNames = static_cast<Vector<std::string>>(collumNames);
}