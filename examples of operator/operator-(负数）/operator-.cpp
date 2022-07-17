#include<iostream>

class distance
{
private:
    int feet;  //英尺
    int inches;   //英寸
public:
    distance(){
        this->feet = 0;
        this->inches = 0;
    }
    distance(int f,int i){
        this->feet = f;
        this->inches = i;
    }
    void display_distance(){
        std::cout << "Feet:" << feet << "  Inches:" << inches << std::endl;
    }  
    distance operator-(){
        feet = -feet;
        inches = -inches;
        return distance(feet,inches);  //返回一个匿名对象（显示法构造函数）
    }
};

int main(){
    distance d1(10,50);
    d1.display_distance();  //Feet:10  Inches:50

    -d1;

    d1.display_distance();  //Feet:-10  Inches:-50
    return 0;
}