#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Table{
public:
    Table(size_t, std::string*, std::string);
    int getCollumNumber(std::string);
    void AddLine();
    std::string* ReadLine(size_t);
    void ChangeElement(size_t, size_t, std::string);
    void DeleteLine(size_t);
    void WriteTable();
    std::string GetDescription();
    void SaveWrite(std::ofstream&);
    std::string getName() { return name; }
    size_t getLines() { return lines; }
    ~Table();
private:
    std::string name;
    size_t lines = 0;
    size_t collums = 0;
    std::string* collumsNames;
    std::string** tableElements;
};