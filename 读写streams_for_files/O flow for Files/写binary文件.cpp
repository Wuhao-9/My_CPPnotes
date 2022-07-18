#include<iostream>
#include<fstream>   //对文件进行操作，包含fstream头文件
#include"./../class_content.hpp"

int main(){
    Personal_information person1 = {"Xiaoming",18,"138xxxxxxxx"};
    //创建ofstream类对象
    std::ofstream ofs;
    //打开文件，将输出流引入文件路径
    ofs.open("./write_binart_file.txt",std::ios::binary | std::ios::trunc | std::ios::out);
    //向文件输出数据
    ofs.write((const char*)&person1,sizeof(person1));   // 通过.write()方法以二进制方式写数据 参数1：传入要输入的数据的地址并强转换为const char*类型，参数2：传入数据的大小
    //关闭输出流与文件的链接
    ofs.close();
    return 0;
}