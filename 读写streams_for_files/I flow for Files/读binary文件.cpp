#include<iostream>
#include<fstream>   //对文件进行操作，包含fstream头文件
#include"./../class_content.hpp"

int main(){
    // 创建ifstream对象
    std::ifstream ifs;
    // 打开二进制文件
    ifs.open("../O flow for Files/write_binart_file.txt",std::ios::binary | std::ios::in);
    // 判断文件是否打开
    if (!ifs.is_open()){
        std::cout << "打开文件失败，即将退出程序" << std::endl;
        exit(1);
    }
    Personal_information person;
    ifs.read((char*)&person,sizeof(person));    //必须以与目标文件相同的类或数据类型读取目标文件的数据
    std::cout << person.name << std::endl;
    std::cout << person.age << std::endl;
    std::cout << person.phone_number << std::endl;
    return 0;
}