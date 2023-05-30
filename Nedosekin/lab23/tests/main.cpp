#include <iostream>
#include "../include/Tree.hpp"
#pragma once
int main()
{
    Tree<int> BT_for_find_depth;
    
    char symbol = ' ';
    int value = 0;
    std::cout << "If you want to insert new node into tree, enter command ' i 'required value' '" << std::endl;
    std::cout << "If you want to delete node from the tree, enter command ' d 'required value' '" << std::endl;
    std::cout << "If you want to print the tree, enter command 'p'" << std::endl;
    std::cout << "If you want to find max depth tree, enter command 't' " << std::endl;
    while(symbol != '.')
    {
        std::cin >> symbol;

        switch(symbol)
        {
            case 'i':
                std::cin >> value;
                BT_for_find_depth.InsertNode(value);
                break;
            case 'd':
                std::cin >> value;
                BT_for_find_depth.DeleteNode(value);
                break;
            case 'p':
                BT_for_find_depth.PrintTree();
                break;
            case 't':
                BT_for_find_depth.MaxDepth();
                break;
            default:
                break;
        }
    }
    return 0;
}
