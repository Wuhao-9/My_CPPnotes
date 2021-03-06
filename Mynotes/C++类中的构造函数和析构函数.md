## 构造函数与析构函数：

* 写在前面：
  1. 构造函数与析构函数是被编译器自动调用的，完成对象的初始化和清理
  2. 如果我们不提供构造和析构，编译器会提供，**但是默认构造函数和析构函数它们的函数体为空**
  3. 若程序员创建一个类但不写构造函数，则编译器给该类默认添加3个函数
     * 默认构造函数（无参，函数体为空）
     * 默认析构函数（无参，函数体为空）
     * 默认拷贝构造函数，仅对成员属性进行**值拷贝**
  4. 构造函数与析构函数都只会被调用**一次**

* 构造函数调用规则：
  * 如果用户定义有参构造函数，C++不在提供默认（无参）构造函数，但会提供拷贝函数
  * 如果用户定义拷贝构造函数，C++不会在提供其他构造函数

### 构造函数：
  主要作用：创建对象时为对象的成员属性赋值，**创建对象时**由编译器自动调用
  * 构造函数语法 `类名() {相关实现}`：
  1. 构造函数没有返回值，也不写void
  2. 函数名与类名相同
  3. 构造函数可以有参数，因此可以发生承载
   * 构造函数的分类：
     * 按参数分为：有参构造和无参构造（默认构造）
     * 按类型分为：普通构造和拷贝构造（除了拷贝构造以外的都叫普通构造）
   * 拷贝构造的写法：`person(const person& a) {相关实现}` 
   * 拷贝构造的调用：
     1. 括号法：
        * 调用默认构造：`person p1;`
        * 调用有参构造：`person p2(100);`
        * 调用拷贝构造：`person p3(p2)   //将p2的成员属性拷贝给p3（初始化p3）;`
        注意事项1：**调用默认构造时不要加()**，因为会被编译器认为是一个函数声明，故编译器不会创建对象
     2. 显示法：
        * 调用默认构造：`person p1;`
        * 调用有参构造：`person p2 = person(10);`
        * 调用拷贝构造：`person p3 = person(p2);`
        匿名对象：`person(10); //匿名对象特点:当前行执行结束后，系统会立即回收掉匿名对象`
        注意事项2：**不要利用拷贝构造初始化匿名对象**
        编译器会认为`person(p3)等价于person  p3；`
        即创建了一个名为p3的person对象并**调用了默认构造**（无参构造）
     3. 隐式转换法：
        * 调用默认构造：`person p1;`
        * 调用有参构造：`person p2 = 10;`
        * 调用拷贝构造：`person p3 = p2;`




### 析构函数：
主要作用：对象在被**销毁前**系统自动调用，执行相关的清理工作
* 析构函数语法`~类名() {相关实现}`：
  1. 析构函数没有返回值，也不写void 
  2. 函数名与类名相同，在函数名前加上 ~
  3. 析构函数不能有参数，因此不能发生承载

## 拷贝构造函数调用时机的总结：
该案例使用的类的实现如下：
```cpp
class person
{
public:
    person(int age,int id){
        this->age = age;
        this->id = id;
        std::cout << "有参构造调用" << std::endl;
    }
    person(const person& p){
        this->age = p.age;
        this->id = p.id;
        std::cout << "拷贝构造调用" << std::endl;
    }

    int age,id;
};
```
   * 案例一：使用一个已经创建完毕的对象来初始化一个新对象
   ```cpp
   int main(){
    person p1(20,1);   //调用有参构造
    person p2(p1);   //调用拷贝构造
    return 0;
   }
   ----- ----- ----- -----
   终端输出：
   有参构造调用
   拷贝构造调用
   ```

   * 案例二：以值传递的给函数参数传值（以值传递的方式给函数传参）
   ```cpp
    void func(person p){   //函数形参是值传递
        p.age = 1000;
    }

    int main(){
        person p1(20,1);   //调用有参构造
        func(p1);
        //将p1以值传递的方式传给形参，形参会进行`person p = p1`操作，故该行调用拷贝构造
        return 0;
    }
   ----- ----- ----- -----
   终端输出：
   有参构造调用
   拷贝构造调用
   ----------------------------------------------------------------------
   -若以引用传递或地址传递的方式给函数传参呢？-

    void func(person& p){
        p.age = 1000;
    }

    int main(){
        person p1(20,1);
        std::cout << "p1.age=" << p1.age << std::endl;
        func(p1);
        std::cout << "p1.age=" << p1.age << std::endl;
        return 0;
    } 
   ----- ----- ----- -----
   终端输出： 
   有参构造调用  
   p1.age=20
   p1.age=1000
   //由此可知，没有调用拷贝构造函数。 
   /*
   原因：func函数的形参定义为以引用的形式传参，故执行person& p = p1，无需创建新的对象，直接将p1**本身**传入函数中
   */

   指针传递同上
   ```
### **需要注意**：以值方式返回局部对象
    ps:类定义中新创建析构函数
     ```cpp
        ~person(){
            std::cout << "析构函数调用" << std::endl;
        }
     ```
  1. person p1 = func(); // 声明的同时接收返回值（初始化）或 p1调用拷贝构造
   ```cpp
    person func(){
        person p(10,50);
        std::cout << "p的地址：" << &p << std::endl;
        return p;
    }

    int main(){ 
    person p1 = func();
        /*
        这里 person p1 = func(); 不会调用拷贝方法，因为编译器优化，会直接用对象p1存放func()的返回值;该在维基百科上叫做copy ellision,中文叫复制省略
        */
        std::cout << "p1的地址：" << &p1 << std::endl;
        return 0;
    }
    /*本人理解：编译器本应该将 person p1 = func(); 理解为隐式转换法格式的拷贝构造，但由于调用func()函数，该函数在**其栈区**创建了对象p,并且在函数结束前返回了值(p1)，但函数结束后编译器没有收回func函数栈区的p的内存，而是将这块内存给了p1使用.节省了创建对象的时间，进而增加了程序运行效率。
    */
    ----- ----- ----- -----
    终端输出：
    有参构造调用
    p的地址：0x7fffffffdc00
    p1的地址：0x7fffffffdc00
    析构函数调用
    /*
    由此可见，析构函数只出现了一次，故func函数结束后并没有释放在func函数栈区所创建的对象p的内存
    */
   ```
  2.  person p1; //p1直接调用默认构造函数
      p1 = func(); 
   
   ```cpp
    person func(){
        person p(10,50);
        std::cout << "p的地址：" << &p << std::endl;
        return p;
    }

    int main(){ 
        person p1;
        p1 = func();
        std::cout << "p1的地址：" << &p1 << std::endl;
        return 0;  
    }
    ----- ----- ----- -----
    终端输出：
    默认构造函数调用
    有参构造调用
    p的地址：0x7fffffffdc00
    析构函数调用 //由此可知，func函数所在其栈区创建的对象p在func函数结束后被操作系统自动释放
    p1的地址：0x7fffffffdbf8  
    析构函数调用
   ```