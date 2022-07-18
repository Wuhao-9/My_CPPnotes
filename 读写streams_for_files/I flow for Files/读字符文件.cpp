#include<iostream>
#include<fstream>

//读取数据的四个方法：

//cin会忽略空格和换行符，但只是在读取的开头，开头不管有多少空格或者换行符，开始读取的时候，是从第一个有效字符开始读取的，如果在读取中间遇到了换行符或者空格，会认为读取结束
void Method_1(std::ifstream& ifs){  //ifstream类与istream类一样，只允许程序中存在一个对象(即不允许拷贝出新对象)
    char text[100];   // ifs与cin一样忽略开头的空格或换行符！
    while (ifs >> text){  //左移运算符重载 stream& operator>>(istream&, T &); 返回值为cin本身（非0值），只有当遇到EOF输入时，返回值为0。
        std::cout << text << std::endl;
    }    
}

void Method_2(std::ifstream& ifs){
    char text[100];
    while (ifs.getline(text,sizeof(text))){  //getline会读取空格和制表符！
        std::cout << text << std::endl;
    }
}

void Method_3(std::ifstream& ifs){
    char text;
    while ((ifs.get(text))){    //ifs.get() 逐字符读取，且能读取空格，制表符，换行符！将读取的字符赋给所传参数,返回值是ifstream对象
        std::cout << text;
    }
}

void Method_4(std::ifstream& ifs){
    std::string str;
    while (getline(ifs,str)){   //与Method_2不同，此处的getline()非类方法！
        std::cout << str << std::endl;
    }
}


void Method_5(std::ifstream& ifs){
    char text;
    while ((text = ifs.get()) != EOF){  //与Method_3不同，此处是ifsteam类内get函数的重载形式，会逐字符读取，且能读取空格，制表符，换行符，并且返回读取的字符串
        std::cout << text;              //EOF(End Of File),以EOF作为文件结束标志的文件，必须是文本文件
    }
}


int main(){
    //创建ifsteam类对象 
    std::ifstream ifs;
    //打开文件
    ifs.open("../O flow for Files/write_test.txt",std::ios::in);        
    // 判断文件是否打开
    if (!ifs.is_open()){  
        std::cout << "打开文件失败，即将退出程序" << std::endl;
        return 0;
    }
    // Method_1(ifs);
    // Method_2(ifs);
    // Method_3(ifs);
    // Method_4(ifs);
    Method_5(ifs);

    ifs.close();
    return 0;
}

/*总结： getline无论是类方法还是全局函数都不能读取换行符，但可以读取空格和制表符
    ifs.get()逐字符读取，可读取换行符，制表符，空格 
    以EOF作为文件结束标志的文件，前提：必须是文本文件,*/