#include "alg.h"
#include <iterator>
#include <string>
#include<algorithm>
#include<iostream>

int main()
{
    std::string space=" ";
    int a[]={1,2,3,4,5,6,7,8,9};
    auto p= Add_n(std::begin(a),std::end(a),3);
    for(int i: a)
    {
        std::cout<<i<<space;
    }
    std::cout<<"\np is pointion on: "<<*p<<std::endl;
   
    int ai[]={1,2,3,4,5,6,7,8,9};
     p= Add_n(std::begin(ai),std::end(ai),2);
    for(int i: ai)
    {
        std::cout<<i<<space;
    }
    std::cout<<"\np is pointion on: "<<*p<<std::endl;
    return 0;
}