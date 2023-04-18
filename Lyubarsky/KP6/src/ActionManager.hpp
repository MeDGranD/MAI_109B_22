#pragma once

#include "DataBase.hpp"
#include <memory>

class ActionManager{
public:
    void Input();
    void OPEN();
    void DELETE();
    void CREATE();
    void SELECT();
    void DROP();
    void UPDATE();
    void INSERT();
    ~ActionManager() {delete currentDataBase;}

    void stringMassiveIncrement(std::string*, std::string); 

private:
    DataBase* currentDataBase = nullptr;
    std::string currentCommand;
    std::string getterstr;
};