#include<iostream>
//习惯上人们是使用 cin>> 和 cout<< 的，得使用友元函数来重载运算符，如果使用成员函数来重载会出现 d1<<cout; 这种不自然的代码。
class Time
{
    friend std::ostream& operator<<(std::ostream& out,const Time& t);
private:
    int hours;
    int minutes;
    int second;
public:
    Time(int h,int m,int s){
        this->hours = h;
        this->minutes = m;
        this->second = s;
    }
};
// 函数类型为引用，实现链式编程思想
std::ostream& operator<<(std::ostream& out,const Time& t){  //我们需要把运算符重载函数声明为类的友元函数，这样我们就能不用创建对象而直接调用函数
    std::cout << t.hours << ":" << t.minutes << ":" << t.second;  //此处的 out == std::cout
    return out;
}

int main(){
    Time t(12,59,35);
    std::cout << t << std::endl;  //12:59:35
    std::cout << Time(20,2,6) << std::endl;  //调用匿名对象，显示时间
    return 0;
}

