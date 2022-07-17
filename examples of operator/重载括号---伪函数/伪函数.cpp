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
    cout << m(10,20) << endl;  //m(10,20) 等价与 m.operator()(10,20)
    cout << My_add()(100,100) << endl;  //创建了一个匿名对象，并调用了operator()函数
}