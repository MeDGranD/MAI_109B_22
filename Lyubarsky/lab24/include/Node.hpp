#ifndef NODE_HPP
#define NODE_HPP

#include "../../KP7/include/Vector.hpp"

class Node{
public:
    Node() = default;
    Node(const char);
    std::string val;
    Vector<Node*> childs;
};

#include "../src/Node.cpp"

#endif