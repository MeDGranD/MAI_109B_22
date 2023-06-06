#ifndef NARYTREE_HPP
#define NARYTREE_HPP

#include "Node.hpp"
#include <string>
#include "../../lab26/include/Deque.hpp"

class Nary_tree{
public:
    Nary_tree() = default;

    void print(Node* = nullptr, size_t = 0) const;

    bool isOperator(const char) const;
    size_t getPriority(const char) const;

    void makeBinaryTree(const std::string& = "");
    void makeNaryTree(Node* = nullptr);
    void incrieseAmountOfChilds(Node* = nullptr);

    ~Nary_tree();

private:
    Node* root;
    std::string infStr;
    size_t nary_size = 0;
};

#include "../src/Nary_tree.cpp"

#endif