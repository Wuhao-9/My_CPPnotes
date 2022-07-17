#ifndef __Person_hpp__
#define __Person_hpp__

#include<iostream>

using std::string;

class person
{
private:
    string name;
    int age;

public:
    person operator+(person& a){
        person temp;
        temp.name = "mixture";
        temp.age = this->age + a.age;
        return temp;
    }

    void Setname(string name){
        this->name = name;
    }
    string Getname(){
        return this->name;
    }
    void Setage(int age){
        this->age = age;
    }
    int Getage(){
        return this->age;
    }
    
};

#endif