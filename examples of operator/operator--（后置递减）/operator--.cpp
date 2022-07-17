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
    Time operator--(int);
};

void Time::display_time(){
    if(minutes==0){
        std::cout << "now:" << this->hours << ":00" << std::endl;
    }else{
        std::cout << "now:" << this->hours << ":" << this->minutes << std::endl;
    }
}

Time Time::operator--(int){  //此处的int非函数形参的意思，而是为了与重载前缀递减区分，加上int表示重载后缀递减
    Time temp(*this);  //调用拷贝构造，将当前对象作为参数传值，保存原始值
    minutes--;
    if(minutes<0){
        minutes += 60;
        hours--;
    }
    return temp;
}

int main(){
    Time t(12,0);
    t.display_time();  //now:12:00
    t--;
    t.display_time();  //now:11:59
    return 0;
}
