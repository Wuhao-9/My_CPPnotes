#include<iostream>
using namespace std;

class My_add
{
public:
    int operator()(int a,int b){
        return a+b;
    }
};

int main(){
    My_add m;
    cout << m(10,20) << endl;
}