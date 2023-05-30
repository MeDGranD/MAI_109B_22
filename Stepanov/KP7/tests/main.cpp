#include "../include/Matrix.hpp"
#include "../src/brenchmark.cpp"
#include"../src/Matrix.cpp"
#include <iostream>
int main()
{
   brenchmark();

Vector<std::vector<int>> k;
k.resize(9);
for(int64_t y=0;y<9;y++){
    std::cout<<k[y].size()<<'\n';
}
std::cout<<"copy constructor"<<'\n';
Vector<std::vector<int>> kc(k);
for(int64_t y=0;y<kc.size();y++){
    std::cout<<kc[y].size()<<'\n';
}
std::cout<<"list of initialization"<<'\n';
Vector<std::string> sk({"a","abb","abaca"});
for(int64_t y=0;y<sk.size();y++){
    std::cout<<sk[y]<<'\n';
}
Vector<std::string> sk2={"a","abb","abaca"};
for(int64_t y=0;y<sk2.size();y++){
    std::cout<<sk2[y]<<'\n';
}
    return 0;
}
