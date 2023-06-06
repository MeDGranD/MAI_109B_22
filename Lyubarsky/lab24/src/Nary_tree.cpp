#include "../include/Nary_tree.hpp"

bool Nary_tree::isOperator(const char simbol) const{
    return (simbol == '-' || simbol == '+' || simbol == '*' || simbol == '/' || simbol == '^');
}

size_t Nary_tree::getPriority(const char oper) const{
    switch(oper){
        case('+'):
            return 1;
        case('-'):
            return 1;
        case('*'):
            return 2;
        case('/'):
            return 2;
        case('^'):
            return 3;
        case('~'):
            return 4;
    }
    return 0;
}

void Nary_tree::print(Node* node, size_t depth) const{

    if(node == nullptr){
        node = this->root;
    }

    for(int64_t currentChild = node->childs.size() - 1; currentChild >= 0; --currentChild){
        print(node->childs[currentChild], depth + 1);
    }
    for(size_t curerntTab = 0; curerntTab < depth; ++curerntTab){
        std::cout << '\t';
    }
    std::cout << node->val << '\n';

}

void Nary_tree::makeBinaryTree(const std::string& expression){
    
    if(expression == ""){
        std::cin >> this->infStr;
    }
    else{
        this->infStr = expression;
    }

    deque<char> operators;
    deque<Node*> nodes;

    std::string digit = "";

    for(size_t currentChar = 0; currentChar < this->infStr.size(); ++ currentChar){

        char simbol = this->infStr[currentChar];

        if(!isOperator(simbol) && simbol != ')' && simbol != '('){
            digit += simbol;
            if(currentChar == this->infStr.size()-1){
                nodes.push_back(new Node());
                nodes.back()->val = digit;
                digit = "";
                break;
            }
            if(isOperator(this->infStr[currentChar + 1]) || this->infStr[currentChar + 1] == ')'){
                nodes.push_back(new Node());
                nodes.back()->val = digit;
                digit = "";
            }
        }
        else if(simbol == '('){
            operators.push_back(simbol);
        }
        else if(simbol == ')'){
            while(operators.back() != '('){

                Node* newNode = new Node(operators.back());

                if(operators.back() == '~'){
                    newNode->childs.push_back(nodes.back());
                    nodes.back() = newNode;
                }
                else{
                    newNode->childs.push_back(nodes.back());
                    nodes.pop_back();
                    newNode->childs.push_back(nodes.back());
                    nodes.back() = newNode;
                }
                operators.pop_back();
            }
            operators.pop_back();
        }
        else{

            if(simbol == '-' && this->infStr[currentChar - 1] == '('){
                simbol = '~';
            }

            while(operators.size() != 0 && getPriority(simbol) <= getPriority(operators.back())){
                Node* newNode = new Node(operators.back());
                
                if(operators.back() == '~'){
                    newNode->childs.push_back(nodes.back());
                    nodes.back() = newNode;
                }
                else{
                    newNode->childs.push_back(nodes.back());
                    nodes.pop_back();
                    newNode->childs.push_back(nodes.back());
                    nodes.back() = newNode;
                }
                operators.pop_back();
            }
            operators.push_back(simbol);
        }

    }

    while(operators.size() != 0){
        Node* newNode = new Node(operators.back());
                
        if(operators.back() == '~'){
            newNode->childs.push_back(nodes.back());
            nodes.pop_back();
            nodes.push_back(newNode);
        }
        else{
            newNode->childs.push_back(nodes.back());
            nodes.pop_back();
            newNode->childs.push_back(nodes.back());
            nodes.pop_back();
            nodes.push_back(newNode);
        }
        operators.pop_back();
    }

    this->root = nodes.back();
}

void Nary_tree::makeNaryTree(Node* node){
    if(node == nullptr) node = this->root;

    for(size_t currentChild = 0; currentChild < node->childs.size(); ++currentChild){
        makeNaryTree(node->childs[currentChild]);
        if(node->childs[currentChild]->val == node->val){
            for(size_t childOfChild = 0; childOfChild < node->childs[currentChild]->childs.size() - 1; ++childOfChild){
                node->childs.push_back(node->childs[currentChild]->childs[childOfChild]);
            }
            Node* deleteNode = node->childs[currentChild];
            node->childs[currentChild] = node->childs[currentChild]->childs[node->childs[currentChild]->childs.size() - 1];
            delete deleteNode;
        }
    }
    if (this->nary_size < node->childs.size()){
        this->nary_size = node->childs.size();
    }
    
    if(node == this->root){
        this->incrieseAmountOfChilds(this->root);
    }
}

void Nary_tree::incrieseAmountOfChilds(Node* node){
    if(node == nullptr){
        node = this->root;
    }

    for(size_t currentChild = 0; currentChild < node->childs.size(); ++currentChild){
        incrieseAmountOfChilds(node->childs[currentChild]);
    }

    if(node->val == "+" || node->val == "-"){
        while(node->childs.size() != this->nary_size){
            node->childs.push_back(new Node('0'));
        }
    }
    if(node->val == "*" || node->val == "/" || node->val == "^"){
        while(node->childs.size() != this->nary_size){
            node->childs.push_back(new Node('1'));
        }
    }
}

Nary_tree::~Nary_tree(){
    deque<Node*> deleteDeque;
    deleteDeque.push_back(this->root);
    while(deleteDeque.size() != 0){
        for(size_t currentChild = 0; currentChild < deleteDeque.front()->childs.size(); ++currentChild){
            deleteDeque.push_back(deleteDeque.front()->childs[currentChild]);
        }
        
        delete deleteDeque.front();
        deleteDeque.pop_front();
    }
}