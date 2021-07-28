# Records of C++&&Qt Practicing 

### C++

#### day_one
###### 描述
假设存在一个m*n的栅格，编写函数计算从左下角（坐标：0, 0）走右上角（坐标：m, n）的路径有多少种。只能沿栅格线走，且不能反向走，既只能向上或向右走。

###### 实现思路

递归   [源代码](https://github.com/learnway299/Cpp_Qt_Practicing/blob/main/day_one/task_1.cpp)

#### day_two
###### 描述
使用C++实现quick sort算法。   
###### 实现思路
函数模板 [源代码](https://github.com/learnway299/Cpp_Qt_Practicing/blob/main/day_two/quicksort.cpp)

#### day_three

###### 描述

###### 使用C++语言编写模块导入三维模型文件并管理模型数据。 三维模型文件为OFF格式。OFF格式是一种简单的网格（mesh）模型文件格式，定义如下： https://shape.cs.princeton.edu/benchmark/documentation/off_format.html实现思路

1. 导入指定文件，输出模型基本信息（顶点数、面片数）；

2. 支持根据顶点索引查询顶点坐标，根据面索引查询面片定点坐标；

3. 使用面向对象编程，具备良好的抽象及封装；

   ###### 实现思路

   实现了基本功能
   [源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_three)

#### day_four
###### 描述

###### Dog类和Cat类继承Animal类，根据用户输入的数值，创建相应个数的Dog对象和Cat对象，然后调用speak()，如果发现是Dog类，调用swim()，最后销毁。实现思路

- Dog类和Cat类继承Animal类； Dog类、Cat类、Animal类各有一个默认构造函数，分别输出字符串“Dog”、“Cat”和“Animal”。输出字符串后换行。注意三个字符串的首字母都是大写。
- 在 Animal 类中定义纯虚函数 speak()；
- 在 Dog 和 Cat类中覆写基类的 speak() 函数。Dog类的speak函数输出字符串“wang”之后换行；Cat类的speak函数输出字符串“miao”之后换行。
- 在 Dog 类定义 swim() 函数，swim() 函数输出字符串“swim”之后换行。
- 在主函数中接受用户输入的一个整数N（大于0）；
- 创建一个vector对象v （你可以用其它名字），存储Animal对象的指针。
- 按照先创建一个 Dog 对象，紧接着再创建一个 Cat 对象这样交替创建的次序，一共创建 N 个 Dog对象和 N 个 Cat 对象；将这些Dog对象和Cat对象的指针按照创建的次序都存入v中。（提示：可以使用vector::push_back()函数）。
- 将存入v中的对象，按照先后次序，逐个调用 speak() 函数，如果发现是Dog，调用 swim() 函数，然后用 delete 显式销毁。（注意：每调用一个对象的 speak() 之后，就立即用 delete 销毁该对象）。

###### 实现带日期的时钟类

- 需要类外实现Date类的days方法，根据年和月，返回该年该月对应的天数 实现Date类的NewDay方法，该方法将Date代表的日期增加一天。
- 实现ClockWithDate类，它继承至Clock类和Date类，记录时间和日期 重新实现ClockWithDate类的showTime方法和run方法。 showTime方法输出当的时间和日期，先输出时间再输出日期。 run方法每次将现在的时间增加一秒，并且当时间超过23：59：59时，更新日期。
- 比如某次程序运行输入当前时间是：1 1 1 7 10 2000（2000年10月7号1点1分1秒），然后输入运行时间x: 5,则程序运行的输入输出如下：

​       Now:1:1:1 2000-10-7 现在运行x秒:Now:1:1:6 2000-10-7

###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_four)

#### day_five
###### 描述
###### 实现向量类

通过运算符重载实现一个向量类Vec2D，可以使以下测试代码编译通过。

```cpp
#include <iostream>
#include "Vec2D.h"
using std::cout;
using std::endl;

int main() {
	// 创建向量对象
	Vec2D v1{ 3,5 }, v2{ 4,6 };

	// 向量转为字符串
	cout << "v1 = " << v1.toString() << endl;
	cout << "v2 = " << v2.toString() << endl;
	// 向量加法： 向量+向量，向量+数
	Vec2D v3 = v1 + v2;
	Vec2D v4 = v3 + 10.0;
	cout << "v3 = " << v3.toString() << endl;
	cout << "v4 = " << v4.toString() << endl;
	// 向量减法，向量点积，向量数乘
	Vec2D v5 = v2 - v1;
	double v6 = v2 * v1;
	Vec2D v7 = 2.1 * v3;
	cout << "v2 - v1 = " << v5.toString() << endl;
	cout << "v2 . v1 = " << v6 << endl;
	cout << "v3 * 2.1 = " << (v3 * 2.1).toString() << endl;
	cout << "2.1 * v3 = " << v7.toString() << endl;

	Vec2D va1{ 10, 12 }, va2{ 1, 2 };
	cout << " va1 += va2 : " << (va1 += va2).toString() << endl;
	cout << " va1 -= va2 : " << (va1 -= va2).toString() << endl;
	// 向量求负值
	Vec2D v8 = v2.negative();
	cout << "-v2 = " << (-v2).toString() << endl;
	// 向量自增/自减
	cout << "++v8 = " << (++v8).toString() << endl;
	cout << "v8++ = " << (v8++).toString() << endl;
	cout << "v8 = " << v8.toString() << endl;
	cout << "--v2 = " << (--v2).toString() << endl;
	// 读取或者修改向量元素
	v1[0] = 31.1;
	cout << "v1.x_ = " << v1[0] << endl;
	cout << "v1.y_ = " << v1[1] << endl;
	// v1[ 8 ] = 10.0;
	// 向量的长度magnitude 和角度direction
	cout << "v1.magnitude = " << v1.magnitude() << endl;
	cout << "double(v1) = " << static_cast<double>(v1) << endl;
	cout << "v1.direction = " << v1.direction() << endl;
	// 比较两个向量
	cout << "v1 compare v2 : " << v1.compareTo(v2) << endl;
	cout << "Please input a Vec2D:";
	Vec2D v9{};
	std::cin >> v9; // operator>>(std::cin, v9);
	cout << v9 << endl;
}
```

###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_five)

#### weekend_one
###### 描述

超市里共有五大类商品（例：饮料、纸巾），要求设计一个抽象类（Commodity）来表示商品的共有特性（如商品名、商品ID、价格、特性描述等），饮料等商品派生自该抽象类并支持商品价格比较排序（重载’<‘运算符），超市管理类（SupermarketManager）负责管理所有的商品（增加商品、删除商品等功能实现）同时重载’[]’运算符支持按商品类型获取同类型所有商品（例子：[“Drinks”]返回所有饮料列表）。

###### 输出示例

```
文本界面与功能：
1、新增商品信息
2、删除商品信息
3、修改商品信息（ps：例如按Id修改价格、描述等）
4、商品信息检索
5、商品按价格排序输出
6、输出价格前五的商品
0、退出
请选择功能(0-6)：
```

###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/weekend_one)

#### day_six
##### 实现一个KsoString类
###### 描述

使用C++语言编写一个KsoString容器类，要点如下。

- 1.容器类可以存储char / WCHAR两种类型。
- 2.容器类采用链表结构来存储，一个结点存储一个字符，并提供插入字符、删除字符、追加字符、元素个数等常用接口。
- 3.容器类提供operator[]的随机访问接口, 返回值为对应位置的字符，对于超出位置的情况，则返回0。

###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_six)

#### day_seven
##### 智能指针
###### 描述

- 实现一个智能指针类，基本功能与std::shared_ptr相同。
- 基于模板实现，支持不同类型；
- 构造方式接受原生指针即可；
- 支持指针的各种访问方式，如->, *, 指针判空等操作；
- 支持get, use_count等方法；
- 编写智能指针类的测试用例，覆盖到上述各个方法；

###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_seven)

#### day_eight
##### 实现一个KMatrix矩阵容器类
###### 描述

使用C++编写一个KMatrix容器类，内部可以存储一个二维矩阵数据，并满足以下要求：

1、使用所学的标准容器来组织和存储矩阵数据；

2、KMatrix可以存储int/double等常规数值类型，同一个矩阵内部存储的数据类型是一致的；

3、实现KMatrix的初始化函数:

```cpp
void KMatrix::init(row_count, col_count) //初始数据为0
```

4、实现KMatrix获取行列数的函数:

```cpp
int KMatrix::getRows() const;
int KMatrix::getCols() const;
```

5、实现KMatrix的数据修改与获取函数:

```cpp
void KMatrix::setData(row, col, value);
Value KMatrix::getData(row, col) const;
```

6、实现KMatrix删除行列的函数:

```cpp
void KMatrix::erase_row(row);
void KMatrix::erase_col(col);
```

7、实现KMatrix的加(+)、减(-)、叉乘(*)运算,使用运算符重载实现；实现KMatrix的点乘:

```cpp
KMatrix::dotMul(const KMatrix&);
```

8、实现KMatrix的转置:

```cpp
KMatrix KMatrix::transpose() const; //交换行列
```

9、实现KMatrix的控制台打印输出:

```cpp
void KMatrix::print() const; //需要体现矩阵的基本结构
```

10、实现赋值函数(operator=())以及拷贝构造函数（实现深拷贝）；

11、实现一个迭代器，可以遍历及修改KMatrix的数据，遍历顺序先行后列；

12、实现异常处理，比如叉乘不满足行列要求等其他异常的情况时抛出对应的异常；

13、提供demo程序，演示上述操作。
###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_eight)

### Qt
#### day_nine
###### 描述
1. 要求实现一个简单的计算，可以实现加法运算。
2. 利用信号-槽机制。
3. 点击 = 后，可以对表达是进行运算，如：3+5 ，点击 = 后，可直接显示成 8.	
###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_nine)

#### weekend_two
###### 描述
安装引导程序
- 实现一个登录框
-  实现一个进度条
-  弹出一个模态对话框。
-  菜单、工具栏
###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/weekend_two)

#### day_ten
###### 描述
绘制一个奥运五环标志
###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_ten)

#### day_eleven
###### 描述
-  实现无边框对话框， 利用image中的图片，可不要求对话框尺寸以及显示效果完全相同。
- 要求对话框可以标题栏进行拖动
- 中文处理使用ts文件进行翻译。
- 尽量使用qss 文件对对话进行美化。
###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_eleven)

#### day_twelve
###### 描述
文件的读写同步到日志文件，监听日志文件发生改变后发送到界面显示
###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_twelve)

#### day_thirteen
###### 描述
两个对话框实现C-S通信
###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_thirteen)

#### day_fourteen
###### 描述
Process Monitor等工具的使用
###### 实现思路
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/day_fourteen)

#### weekend_finnally
##### 一个简单工具的实现
系统桌面文件遍历工具
###### 描述：
开发一个能够搜索系统桌面目录下的文件的GUI工具，具有的功能清单如下:

-   在搜索栏输入关键字，快速搜索系统桌面目录里的文件和文件夹，展示在列表中，包含程序图标、名称、路径、大小信息。（搜索结果无需包含桌面文件夹中的子文件和子文件夹;）
-   为搜索结果增加右键菜单，右键中菜单中包含启动和删除功能;
-   程序启动后默认隐藏，通过alt+空格唤出，再次按下alt+空格隐藏;
-   中文名称的程序支持通过拼音首字母进行搜索，例如输入“wx"，能够搜到“微信”程序;
  参考everything,listary等实现一个简化版本。
###### 完成效果：
实现了模糊匹配等基本功能，中文转拼音借鉴了[参考网址](http://blog.csdn.net/csnd_ayo)，std::string(xx.toLocal8Bit());//解决了转换乱码问题
[源代码](https://github.com/learnway299/Cpp_Qt_Practicing/tree/main/weekend_finnally)
