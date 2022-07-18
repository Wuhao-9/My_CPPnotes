**C++中对文件操作需要包含头文件< fstream >**

文件类型分为两种：
1. **文本文件**：文件以文本的**ASCII码**形式存储在计算机中
2. **二进制文件**：文件以文本的**二进制**形式存储在计算机中

操作文件的三大**类**：
1. ofstream：写文件
2. ifstream：读文件
3. fstream：读写文件

## 文本文件：
### 写文件步骤：
* 包含头文件 —— #include<fstream>
* 创建**流对象** —— ofstream ofs;
* 打开文件 —— ofs.open("文件路径",打开方式);
* 写数据 —— ofs << "要写入的数据";
* 关闭文件 —— ofs.close();

[写文件示例](/home/wuhao/MyProject/VS_C++/ 读写 flow for files/O flow for Files)
  
**注意：对文件操作完后要关闭文件！**

### 打开文件的方式：

|打开方式|解释|
|---|---|
|ios::in|为读文件而打开文件|
|ios::out|为写文件而打开文件|
|ios::ate|初始位置为文件尾部|
|ios::app|追加方式写文件|
|iso::trunc|若文件存在，先删除再创建|
|ios::binary|二进制方式|

注意：打开方式可以配合使用，利用`|`操作符
eg：用二进制方式写文件`ios::binary | ios::out`

### 读文件步骤：
* 包含头文件 —— #include<fstream>
* 创建**流对象** —— ifstream ifs;
* 打开文件并判断文件是否打开成功 —— ifs.open("文件路径",打开方式);
* 读取数据 —— 五种方式读取
* 关闭文件 —— ifs.close();
判断文件是否打开成功调用类方法：`ifs.is_open();`若成功返回true,失败返回false

[读文件示例(包含五种读取方法)](/home/wuhao/MyProject/VS_C++/ 读写 flow for files/I flow for Files/读文件.cpp)

#### EOF:
* 作用：以EOF作为文件结束标志的文件，前提：**必须是文本文件**
在文本文件中，数据都是以字符的ASCII代码值的形式存放。ASCII代码值的范围是0~127，不可能出现-1，而EOF会被读取为-1，因此可以用EOF作为文件结束标志。

总结：
* getline无论是类方法还是全局函数都**不能读取换行符**，但**可以读取空格和制表符**
* ifs.get()**逐字符读取，可读取换行符，制表符，空格**
* 以EOF作为文件结束标志的文件，前提：必须是文本文件

[文件读取相关案例](../Vs_c++/读写streams_for_files/)