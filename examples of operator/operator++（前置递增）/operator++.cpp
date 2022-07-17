#include<iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time(){
        hours = 0;
        minutes = 0;
        std::cout << "默认构造调用" << std::endl;

    }
    Time(int h,int m){
        this->hours = h;
        this->minutes = m;
        std::cout << "有参构造调用" << std::endl;
    }
    Time(const Time& temp){
        this->hours = temp.hours;
        this->minutes = temp.minutes;
        std::cout << "拷贝构造调用" << std::endl;
    }
    void display_time();
    Time& operator++();
};

void Time::display_time(){
    if(minutes==0){
        std::cout << "now:" << this->hours << ":00" << std::endl;
    }else{
        std::cout << "now:" << this->hours << ":" << this->minutes << std::endl;
    }
}

Time& Time::operator++(){  //返回类型为引用，return对象自身，引用接收自身从而实现链式思想
    minutes++;             //若返回类型为Time，return对象自身，则会调用拷贝构造函数创建一个新的对象！故不能实现链式思想
    if(minutes>=60){
        minutes -= 60;
        hours += 1;
    }
    return *this;
}

int main(){
    Time t(12,58);
    t.display_time();  //now:12:58
    ++(++t); 
    t.display_time();  //now:13:00
    return 0;
}
