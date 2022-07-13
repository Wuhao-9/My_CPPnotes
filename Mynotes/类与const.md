## const修饰成员函数

this指针：
当一个对象调用类内函数时this指针指向该对象，this指针本质上是一个指针常量
```cpp
class person
{
public:
    //当对象p调用该函数时this指针本质上是指针常量，person* const this = &p;
    void func(){
        this = NULL; //error,指针的指向（地址）不能修改，
        this->a = 10; //okey,指针指向的值可以修改
    }

    int a;
};

int main(){
    person p;
    p.func();
    return 0;
}
```

常函数：
```cpp
class person
{
public:
    //当对象p调用常函数时this指针本质上是const指针常量，const person* const this = &p;
    void func() const{
        this->a = 10; //error:指针的指向（地址）不能修改，指针指向的值也不可以修改
        this->b = 100;//okey,mutable修饰的成员属性b
    }

    int a;
    mutable int b;
};

int main(){
    person p;
    p.func();
    return 0;
}
```
* 成员函数后面加const(修饰的是this指针)，称该函数为**常函数**
* 常函数内部不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改


常对象：
* 声明对象前加const称该对象为常对象，常对象不能修改成员属性(但可以访问)
* 常对象只能调用常函数,不能调用普通成员函数（因为普通成员函数可以修改成员属性）
* 常对象的创建需要用户定义构造函数


mutable：
由mutable修饰的成员属性，在常函数和常对象下都可以进行修改
