#include<iostream>
#include"Person.hpp"

int main(){
    person A;
    A.Setage(20);
    person B;
    B.Setage(100);
    person C = A + B;
    std::cout << C.Getname() << std::endl << C.Getage() << std::endl;  //mixture  120
    return 0;
}
