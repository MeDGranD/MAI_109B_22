#include "ActionManager.hpp"

void ActionManager::stringMassiveIncrement(std::string* inputMassive, std::string newElement){

    size_t inputMassiveSize = std::size_t(inputMassive);
    std::string* newMassive = new std::string[inputMassiveSize + 1];

    for (size_t currentString = 0;  currentString < inputMassiveSize; ++currentString){
        newMassive[currentString] = inputMassive[currentString];
    }

    newMassive[inputMassiveSize] = newElement;
    delete[] inputMassive;
    inputMassive = newMassive;
}

void ActionManager::INSERT(){
    //Definition
    std::string insertTarget;
    size_t amountValues;
    std::string* collumsNames = nullptr;
    //Initializise of Stream
    getline(std::cin, getterstr);
    std::stringstream strStream(getterstr);

    strStream >> insertTarget;

    while (strStream >> getterstr){

        if (getterstr == "VALUES"){
            break;
        }

        stringMassiveIncrement(collumsNames, getterstr);
    }

    currentDataBase->tables[currentDataBase->getTableNumber(insertTarget)]->AddLine();

    amountValues = std::size_t(collumsNames);

    for (size_t currentValue = 0; currentValue < amountValues; ++currentValue){

        strStream >> getterstr;

        size_t tableNumber = currentDataBase->getTableNumber(insertTarget);
        size_t tableLastLine = currentDataBase->tables[tableNumber]->getLines()-1;
        size_t tableCurrentCollum = currentDataBase->tables[tableNumber]->getCollumNumber(collumsNames[currentValue]);

        currentDataBase->tables[tableNumber]->ChangeElement(tableLastLine, tableCurrentCollum, getterstr);
    }

    delete[] collumsNames;
}

void ActionManager::OPEN(){

    std::string openTarget;
    std::cin >> openTarget;

    if(currentDataBase!=nullptr){
        currentDataBase->Save();
    }

    delete currentDataBase;
    currentDataBase = new DataBase(openTarget, 1);
}

void ActionManager::Input(){

    std::cout << "Enter command:" << std::endl;
    std::cin >> currentCommand;

    if (currentCommand == "EXIT") {
        return;
    }
    else if (currentCommand == "OPEN") {
        OPEN();
    }
    else if (currentCommand == "INSERT") {
        INSERT();
    }
    else if (currentCommand == "SELECT") {
        SELECT();
    }
    else if (currentCommand == "DELETE") {
        DELETE();
    }
    else if (currentCommand == "CREATE") {
        CREATE();
    }

    Input();
}

void ActionManager::CREATE(){

    std::string name;
    std::string createTarget;

    std::cin >> createTarget;
    
    if (createTarget == "TABLE"){

        size_t tableSize = 0;
        std::string* collumsNames = new std::string[0];

        getline(std::cin, getterstr);
        std::stringstream strStream(getterstr);

        strStream >> name;

        while (strStream >> getterstr){

            ++tableSize;
            std::string* newArr = new std::string[tableSize];
            for(size_t currentCollum = 0; currentCollum < (tableSize-1); ++currentCollum){
                newArr[currentCollum] = collumsNames[currentCollum];
            }
            newArr[tableSize-1] = getterstr;
            delete[] collumsNames;
            collumsNames = newArr;
        }
        currentDataBase->CREATE(tableSize, collumsNames, name);
        delete[] collumsNames;
    }
    else if (createTarget == "DATABASE"){
        if (currentDataBase!=nullptr){
            currentDataBase->Save();
        }
        delete currentDataBase;
        std::cin >> name;
        currentDataBase = new DataBase(name, 0);
    }
}

void ActionManager::DROP(){
    std::string DropTarget;
    std::cin >> DropTarget;
    if (std::filesystem::exists(DropTarget)){
        if (currentDataBase->getName()==DropTarget){
            delete[] currentDataBase;
            currentDataBase = nullptr;
        }
        std::filesystem::remove(DropTarget);
    }
}

void ActionManager::SELECT(){

    getline(std::cin, getterstr);
    std::stringstream strStream(getterstr);

    size_t amountOfCollums = 0;
    std::string* collumsNames = nullptr;
    while(strStream >> getterstr){
        if (getterstr == "FROM") break;
        ++amountOfCollums;
        std::string* newArr = new std::string[amountOfCollums];
        for (size_t currentValue = 0; currentValue < amountOfCollums - 1; ++currentValue){
            newArr[currentValue] = collumsNames[currentValue];
        }
        newArr[amountOfCollums-1] = getterstr;
        delete[] collumsNames;
        collumsNames = newArr;
    }
    std::string selectTarget;
    strStream >> selectTarget;
    for (size_t currentCollum = 0; currentCollum < amountOfCollums; ++currentCollum){
            std::cout << collumsNames[currentCollum] << '\t';
    }
    std::cout << std::endl;
    for (size_t currentLine = 0; currentLine < currentDataBase->tables[currentDataBase->getTableNumber(selectTarget)]->getLines(); ++currentLine){
        for (size_t currentCollum = 0; currentCollum < amountOfCollums; ++currentCollum){
            std::cout << currentDataBase->tables[currentDataBase->getTableNumber(selectTarget)]->ReadLine(currentLine)[currentDataBase->tables[currentDataBase->getTableNumber(selectTarget)]->getCollumNumber(collumsNames[currentCollum])] << '\t';
        }
        std::cout << std::endl;
    }
    delete[] collumsNames;
}

void ActionManager::DELETE(){
    std::string deleteTarget;
    std::cin >> deleteTarget;
    std::string collumName;
    std::cin >> collumName >> collumName;
    std::string action;
    std::cin >> action;
    std::string value;
    std::cin >> value;
    int deletedLines = 0;
    for (size_t currentLine = 0; (currentLine - deletedLines) < currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->getLines(); ++currentLine){
        if (action == "="){
            if (currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->ReadLine(currentLine - deletedLines)[currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->getCollumNumber(collumName)] == value){
                currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->DeleteLine(currentLine - deletedLines);
                ++deletedLines;
            }
        }
        else if (action == "<>"){
            if (currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->ReadLine(currentLine - deletedLines)[currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->getCollumNumber(collumName)] != value){
                currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->DeleteLine(currentLine - deletedLines);
                ++deletedLines;
            }
        }
        else if (action == "<"){
            if (std::stoi(currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->ReadLine(currentLine - deletedLines)[currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->getCollumNumber(collumName)]) < std::stoi(value)){
                currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->DeleteLine(currentLine - deletedLines);
                ++deletedLines;
            }
        }
        else if (action == ">"){
            if (std::stoi(currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->ReadLine(currentLine - deletedLines)[currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->getCollumNumber(collumName)]) > std::stoi(value)){
                currentDataBase->tables[currentDataBase->getTableNumber(deleteTarget)]->DeleteLine(currentLine - deletedLines);
                ++deletedLines;
            }
        }
    }
}

/*void ActionManager::UPDATE(){
    getline(std::cin, getterstr);
    std::stringstream strStream(getterstr);
    std::string* collumsNames = nullptr;
    std::string updateTarget;
    strStream >> updateTarget;
    while(strStream >> getterstr) {
        
    }
}*/