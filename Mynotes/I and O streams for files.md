# 对于文件的I/O流
![各I/Ostream总揽](http://www.cplusplus.com/img/iostream.gif)
文件操作，主要运用`fstream`库

文件类型分为两种：
1. **文本文件**：文件以文本的**ASCII码**形式存储在计算机中
2. **二进制文件**：文件以文本的**二进制**形式存储在计算机中

操作文件的三大**类**：
1. ofstream：写文件
2. ifstream：读文件
3. fstream：读写文件


## fstream：
```cpp
#include <fstream>
ofstream         //文件写操作 内存写入存储设备 
ifstream         //文件读操作，存储设备读区到内存中
fstream          //读写操作，对打开的文件可进行读写操作 
```
### 打开文件
在fstream类中，成员函数`open()`实现打开文件的操作，**将数据流和文件进行关联**，从而通过ofstream,ifstream,fstream对象进行对文件的读写操作
fstream类内成员函数：open()
```cpp 
public member function
 
void open ( const char * filename,
            ios_base::openmode mode = ios_base::in | ios_base::out );
 
void open(const wchar_t *_Filename,
        ios_base::openmode mode= ios_base::in | ios_base::out,
        int prot = ios_base::_Openprot)；
 ```
参数列表：
* filename：要操作的文件名(路径)
* mode：打开文件的方式
* port：打开文件的属性(基本很少用到)

打开文件的方式在ios类(**所有I/O流式的基类**)中定义，有如下几种方式：
|打开方式|解释|
|---|---|
|ios::in|为读文件而打开文件|
|ios::out|为写文件而打开文件|
|ios::ate|初始位置为文件尾部|
|ios::app|追加方式写文件|
|iso::trunc|若文件存在，先删除再创建|
|ios::binary|二进制方式|

这些方式可用管道符 | 进行组合


打开文件的属性同样在ios类中也有定义：
|0  |普通文件，打开操作|
|-  |-|
|1  |只读文件|
|2	|隐含文件|
|4	|系统文件|

对于文件的属性也可以使用“或”运算和“+”进行组合使用

#### 巧用stream类的构造函数：
无须显式的去调用open()函数，因为在fstream类的构造函数中调用了open()函数,并拥有同样的构造函数，所以在这里可以直接使用流对象进行文件的操作,如下：
```cpp
ofstream out("文件名.txt", ios::out);
ifstream in("...", ios::in);
fstream foi("...", ios::in|ios::out);
```

### 关闭文件
当文件读写操作完成之后，我们必须将文件关闭以使文件重新变为可访问的。成员函数close()，它负责将缓存中的数据排放出来并关闭文件。这个函数一旦被调用，原先的流对象就可以被用来打开其它的文件了，这个文件也就可以重新被其它的进程所访问了。为防止流对象被销毁时还联系着打开的文件，**析构函数将会自动调用关闭函数close**。

### 状态标志符的验证(fstream成员函数)
1. eof——是ifstream 从类 ios 中继承过来的，当到达文件末尾时返回true 。
2. bad()——如果在读写过程中出错，返回 true 。例如：当我们要对一个不是打开为写状态文件进行写入时，或者我们要写入的设备没有剩余空间的时候。
3. fail()——除了与bad() 同样的情况下会返回 true 以外，加上格式错误时也返回true ，例如当想要读入一个整数，而获得了一个字母的时候。
4. good()——这是最通用的：如果调用以上任何一个函数返回true 的话，此函数返回 false 。
**要想重置以上成员函数所检查的状态标志，可以使用成员函数clear()，没有参数。**

### 所有输入/输出流对象(i/o streams objects)都有至少一个流指针：
* ifstream， 类似istream, 有一个被称为get pointer的指针，指向下一个将被读取的元素的位置。
* ofstream, 类似 ostream, 有一个被称为put pointer的指针 ，指向写入下一个元素的位置。
* fstream, 类似 iostream, 同时继承了get 和 put 

## 操作二进制文件：
在二进制文件中，使用<< 和>>，以及函数（如getline）来操作符输入和输出数据，没有什么实际意义，虽然它们是符合语法的。
文件流包括两个为顺序读写数据特殊设计的成员函数：write 和 read。write 是ostream 的一个成员函数，被ofstream所继承。而read 是istream 的一个成员函数，被ifstream 所继承。
类 fstream 的对象同时拥有这两个函数。它们的原型是：
`write ( char * buffer, streamsize size );`
`read ( char * buffer, streamsize size ); `
* 参数 buffer 是一块内存的地址，用来存储或读出数据。
* 参数size 是一个整数值，表示要从缓存（buffer）中读出或写入的字符数。

注意：读二进制文件的前提是该文件的数据是怎么被写入文件的，如文件数据的类型是int还是char，等等.否则，将无法正确读该文件的数据。

### 缓存和同步(Buffers and Synchronization)
#### 缓存：
当我们对文件流进行操作的时候，它们与一个streambuf 类型的缓存(buffer)联系在一起。这个缓存（buffer）实际是一块内存空间，作为流(stream)和物理文件的媒介。例如，对于一个输出流， 每次成员函数put (写一个单个字符)被调用，这个字符不是直接被写入该输出流所对应的物理文件中的，而是首先被插入到该流的缓存（buffer）中。
#### 同步：
当缓存被排放出来(flush)时，它里面的所有数据或被写入物理媒质中（如果是一个输出流的话），或简单的被抹掉(如果是一个输入流的话)。这个过程称为同步(synchronization)，它会在以下任一情况下发生：
* **当文件关闭时**：在文件被关闭之前，所有还没有被完全写出或读取的缓存都将被同步。
* **当缓存buffer满时**：缓存Buffers 有一定的空间限制。当缓存满时，它会被自动同步。
* **控制符明确指明**:当遇到流中某些特定的控制符时，同步会发生。这些控制符包括：flush 和endl。
* **明确调用函数sync()**: 调用成员函数sync() (无参数)可以引发立即同步。这个函数返回一个int 值，等于-1 表示该流没有联系的缓存或操作失败。

[文件读取相关案例](../Vs_c++/读写streams_for_files/)
