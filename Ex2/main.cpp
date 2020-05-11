#include "alg.h"
#include <iterator>
#include <string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<array>

template<typename T, size_t n>
void print_array(T const (&arr)[n])
{
    std::cout<< "[ ";
    for(size_t i=0; i!=n; ++i)
        std::cout<< arr[i] <<' ';
    std::cout<< "]" <<std::endl;
}


int main()
{
    std::cout<<"\n~~~~~Add_n function~~~~~"<<std::endl;
    int a[]={1,2,3,4,5,6,7,8,9};
    auto p= Add_n(std::begin(a),std::end(a),3);
    print_array(a);
    std::cout<<"p is pointing on: "<<*p<<std::endl;
   
    int ai[]={1,2,3,4,5,6,7,8,9};
     p= Add_n(std::begin(ai),std::end(ai),2);
     print_array(ai);
    std::cout<<"p is pointing on: "<<*p<<std::endl;

    std::cout<<"\n~~~~~Transpose function~~~~~"<<std::endl;
    int ai2[]={1,2,3,4,5,6,7,8,9};
    auto p2= Transpose(std::begin(ai2),std::end(ai2));
     print_array(ai2);
    std::cout<<"p is pointing on: "<<*p2<<std::endl;
    int ai3[]={1,2,3,4,5,6,7,8,9,10};
    p2= Transpose(std::begin(ai3),std::end(ai3));
     print_array(ai3);
    std::cout<<"is p==end(ai3)? "<<bool(p2==std::end(ai3))<<std::endl;
    int ai4[]={1,2,3};
    p2= Transpose(std::begin(ai4),std::end(ai4));
    print_array(ai4);
    std::cout<<"p is pointing on: "<<*p2<<std::endl;
    
    std::cout<<"\n~~~~~Transform function~~~~~"<<std::endl;
    int ai5[]={1,2,3,10,8,6};
    std::vector<int>vec(100);
    auto p3= Transform(std::begin(ai5), std::end(ai5),vec.begin(),[](const int i, const int j){ return i+j;});
    int size_ai5= std::end(ai5)- std::begin(ai5);
   std::cout<<"vec[ ";
    for(int i=0; i!=(size_ai5/2);++i)
        std::cout<<vec[i]<<" ";
    std::cout<<"]"<<std::endl;
    return 0;

}