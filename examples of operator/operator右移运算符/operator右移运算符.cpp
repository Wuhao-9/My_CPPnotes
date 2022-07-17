#include<iostream>

class Introduction
{
    friend std::istream& operator>>(std::istream& in,Introduction& cur_person);
private:
    std::string name;
    int age;
    std::string hobby;
public:
    void self_Introduction(){
        std::cout << "我是" << this->name << "，我今年" << this->age << "岁，" << "我喜欢" << this->hobby << std::endl;
    }
};

std::istream& operator>>(std::istream& in,Introduction& cur_person){ //注意：
    std::cout << "您的姓名是？" << std::endl;
    getline(std::cin,cur_person.name);    //此处调用全局函数getline实现string类型整行输入，cin默认遇见空格、制表符、换行符停止读取，
    std::cout << "您多大了？" << std::endl;  //又因为类函数cin.get()虽然能读取空格和制表符但却不支持string类型（因为string类型是后加入c++的）
    in >> cur_person.age;                   //故利用函数重载技术重载全局函数getline实现string类型的整行读取（碰到换行符停止输入）
    std::cout << "您有什么爱好？" << std::endl;
    in >> cur_person.hobby;
    std::cout << "信息录入完成!" << std::endl;
    return in;
}

int main(){
    Introduction Xiaoming;
    std::cin >> Xiaoming;
    Xiaoming.self_Introduction();
    return 0;
}

/*Terminal：
您的姓名是？
Linus Benedict Torvalds
您多大了？
20
您有什么爱好？
code
信息录入完成!
我是Linus Benedict Torvalds，我今年20岁，我喜欢code
*/