#include<iostream>
#include<fstream> //对文件进行操作，包含fstream头文件

int main(){
    std::string str = "你好\n这是我通过ofstream类写的文件";
    //创建输出流的流对象
    std::ofstream ofs;
    //打开文件
    ofs.open("./write_test.txt",std::ios::out|std::ios::trunc);
    //写入数据
    ofs << str;
    //关闭文件
    ofs.close();
}