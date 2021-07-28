#pragma once
#include <exception>          //异常
#include <stdexcept>          //异常
#include <stdexcept>          //异常类型
#include <iostream>
using namespace std;

//内联函数，用于在出现逻辑错误时，弹出信息
inline void throw_logic_error(string str) {
	throw logic_error(str);
}

template<class T>
class KMatrix
{
private:
	T* data = nullptr;
	int row;
	int column;
public:
	KMatrix() :row(0), column(0) {}//构建空矩阵
	KMatrix(int row, int column); //构建row X column空矩阵
	KMatrix<T>(int row, int column, T* data);//从数组构建矩阵
	KMatrix<T>(const KMatrix<T>& another);//拷贝构造

	bool isempty();//判是否空矩阵
	bool operator==(KMatrix<T>& another);//重载矩阵等号==运算符
	void myiterator();
	KMatrix<T>& operator=(const KMatrix<T>& another);//重载赋值运算符
	T operator()(int i, int j) const;//重载()运算符
	T operator()(int i) const;
	KMatrix<T> operator+(T x);//重载元素+运算符
	KMatrix<T>& operator+=(T x);//重载元素+=运算符
	KMatrix<T> operator+(const KMatrix<T>& another);//重载矩阵+运算符
	KMatrix<T>& operator+=(const KMatrix<T>& another);//重载矩阵+=运算符
	KMatrix<T> operator-(T x);//重载元素-运算符
	KMatrix<T>& operator-=(T x);//重载元素-=运算符
	KMatrix<T> operator-(const KMatrix<T>& another);//重载矩阵-运算符
	KMatrix<T>& operator-=(const KMatrix<T>& another);//重载矩阵-=运算符
	KMatrix<T> operator*(T x);//重载元素*运算符
	KMatrix<T>& operator*=(T x);//重载元素*=运算符
	KMatrix<T> operator*(const KMatrix<T>& another);//重载矩阵*运算符
	T dotMul(const KMatrix<T>& another);//实现KMatrix的点乘

	void init(int, int, const T);//初始化函数
	int getRows() const;//获取行数
	int getCols() const;//获取列数
	void setData(int row, int col, T value);//数据修改
	T getData(int row, int col) const;//数据获取
	void erase_row(int row);//删除行
	void erase_col(int col);//删除列
	KMatrix transpose() const;//转置
	void print() const;////需要体现矩阵的基本结构,控制台打印输出
};

template<class T>
inline KMatrix<T>::KMatrix(int row, int column)
{
	//this->data = new T[row * column];注释此行isempty()生效 不注释失效
	this->data = new T[row * column];
	this->row = row;
	this->column = column;
}

template<class T>
inline KMatrix<T>::KMatrix(int row, int column, T* data)
{
	this->row = row;
	this->column = column;
	this->data = new T[row * column];
	for (int i = 0; i < row * column; i++)
		this->data[i] = data[i];
}

template<class T>
inline KMatrix<T>::KMatrix(const KMatrix<T>& another)
{
	this->row = another.getRows();
	this->column = another.getCols();
	this->data = new T[row * column];
	for (int i = 0; i < row * column; i++)
		this->data[i] = another.data[i];
}


template<class T>
inline bool KMatrix<T>::isempty()
{
	if (data == nullptr)
		return true;
	else
		return false;
}

template<class T>
inline bool KMatrix<T>::operator==(KMatrix<T>& another)
{
	if (this->row != another.getRows())
		return false;
	if (this->column != another.getCols())
		return false;

	for (int i = 0; i < row * column; i++)
		if (this->data[i] != another.data[i])
			return false;
	return true;
}

template<class T>
inline void KMatrix<T>::myiterator()
{
	T tmp;
	int flg;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			flg = 0;
			std::cout << "data(" << i << "," << j << ") :" << getData(i, j) << std::endl;
			std::cout << "若要更改输入1 否则输入其他整数" << std::endl;
			std::cin >> flg;
			if (flg == 1) {
				std::cout << "若要更改后的数据" << std::endl;
				std::cin >> tmp;
				setData(i, j, tmp);
				std::cout << "更改数据成功" << std::endl;
			}
		}
}

template<class T>
inline KMatrix<T>& KMatrix<T>::operator=(const KMatrix<T>& another)
{
	if (this == &another)
		return *this;
	this->row = another.getRows();
	this->column = another.getCols();
	if (data != nullptr)
		delete[] data;
	this->data = new T[row * column];
	for (int i = 0; i < row * column; i++)
		this->data[i] = another.data[i];
	return *this;
}

template<class T>
inline T KMatrix<T>::operator()(int i, int j) const
{
	return getData(i, j);
}

template<class T>
inline T KMatrix<T>::operator()(int i) const
{
	if (i > this->row * this->column - 1 || i < 0)
		throw_logic_error("读取矩阵元素，超出矩阵范围");
	return data[i];
}

template<class T>
inline KMatrix<T> KMatrix<T>::operator+(T x)
{
	KMatrix<T> p(row, column);
	//p.data = new T[p.row * p.column];
	for (int i = 0; i < p.row * p.column; i++)
		p.data[i] = data[i] + x;
	return p;
}

template<class T>
inline KMatrix<T>& KMatrix<T>::operator+=(T x)
{
	for (int i = 0; i < row * column; i++)
		this->data[i] += x;
	return *this;
}

template<class T>
inline KMatrix<T> KMatrix<T>::operator+(const KMatrix<T>& another)
{
	if (!another.data)
		return *this;
	if (row != another.getRows() || column != another.getCols())
		throw_logic_error("矩阵不匹配");
	KMatrix<T> p(row, column);
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.column; j++)
			p.setData(i, j, (getData(i, j) + another.getData(i, j)));
	//p(i) = data[i] + another(i);
	return p;
}

template<class T>
inline KMatrix<T>& KMatrix<T>::operator+=(const KMatrix<T>& another)
{
	if (another.isempty())
		return *this;
	if (row != another.getRows() || column != another.getCols())
		throw_logic_error("矩阵不匹配");
	for (int i = 0; i < row * column; i++)
		this->data[i] += another.data[i];
	return *this;
}

template<class T>
inline KMatrix<T> KMatrix<T>::operator-(T x)
{
	KMatrix<T> p(row, column);
	//p.data = new T[p.row * p.column];
	for (int i = 0; i < p.row * p.column; i++)
		p.data[i] = data[i] - x;
	return p;
}

template<class T>
inline KMatrix<T>& KMatrix<T>::operator-=(T x)
{
	for (int i = 0; i < row * column; i++)
		this->data[i] -= x;
	return *this;
}

template<class T>
inline KMatrix<T> KMatrix<T>::operator-(const KMatrix<T>& another)
{
	if (!another.data)
		return *this;
	if (row != another.getRows() || column != another.getCols())
		throw_logic_error("矩阵不匹配");
	KMatrix<T> p(row, column);
	//p.data = new T[p.row * p.column];
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.column; j++)
			p.setData(i, j, (getData(i, j) - another.getData(i, j)));
	return p;
}

template<class T>
inline KMatrix<T>& KMatrix<T>::operator-=(const KMatrix<T>& another)
{
	if (another.isempty())
		return *this;
	if (row != another.getRows() || column != another.getCols())
		throw_logic_error("矩阵不匹配");
	for (int i = 0; i < row * column; i++)
		this->data[i] -= another.data[i];
	return *this;
}

template<class T>
inline KMatrix<T> KMatrix<T>::operator*(T x)
{
	KMatrix<T> p(row, column);
	for (int i = 0; i < p.row * p.column; i++)
		p.data[i] = data[i] * x;
	return p;
}

template<class T>
inline KMatrix<T>& KMatrix<T>::operator*=(T x)
{
	for (int i = 0; i < row * column; i++)
		this->data[i] *= x;
	return *this;
}

template<class T>
inline KMatrix<T> KMatrix<T>::operator*(const KMatrix<T>& another)
{
	if (!another.data || !data)
		throw_logic_error("矩阵乘法数据为空");
	if (this->getCols() != another.getRows())
		throw_logic_error("矩阵不匹配");
	KMatrix<T> p(this->getRows(), another.getCols());
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.column; j++)
		{
			T sum = 0;//待完善
			for (int t = 0; t < column; t++)  //第一个矩阵的第i行乘以第二个矩阵的第j列
				sum += data[i * column + t] * another(t, j);
			p.setData(i, j, sum);
		}
	return p;
}

template<class T>
inline T KMatrix<T>::dotMul(const KMatrix<T>& another)
{
	T sum = 0;//待完善
	if (!another.data || !data)
		throw_logic_error("矩阵点乘数据为空");
	if (this->getCols() != another.getCols() || this->getRows() != another.getRows())
		throw_logic_error("点乘矩阵不匹配");
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			sum += this->getData(i, j) * another(i, j);
	return sum;
}

template<class T>
inline void KMatrix<T>::init(int row_count, int col_count, const T x)
{
	row = row_count;
	column = col_count;
	this->data = new T[row * column];
	for (int i = 0; i < row * column; i++)
		this->data[i] = x;
}

template<class T>
inline int KMatrix<T>::getRows() const
{
	return row;
}

template<class T>
inline int KMatrix<T>::getCols() const
{
	return column;
}

template<class T>
inline void KMatrix<T>::setData(int row, int col, T value)
{
	data[row * (this->column) + col] = value;
}

template<class T>
inline T KMatrix<T>::getData(int i, int j) const
{
	if (i > this->row - 1 || i < 0)
		throw_logic_error("读取矩阵元素，超出矩阵范围");
	if (j > this->column - 1 || j < 0)
		throw_logic_error("读取矩阵元素，超出矩阵范围");
	return data[i * column + j];
}

template<class T>
inline void KMatrix<T>::erase_row(int rowindex)
{
	if (rowindex >= row || rowindex < 0)
	{
		throw_logic_error("删除行范围越界");
		return;
	}
	T* datetemp = data;
	int newrow = row - 1;
	data = new T[newrow * column];
	for (int i = 0; i < rowindex; i++)
		for (int j = 0; j < this->column; j++)
			this->data[i * column + j] = datetemp[i * column + j];
	for (int i = rowindex; i < newrow; i++)
		for (int j = 0; j < this->column; j++)
			this->data[i * column + j] = datetemp[(i + 1) * column + j];
	row = newrow;
	delete[] datetemp;
}

template<class T>
inline void KMatrix<T>::erase_col(int columnindex)
{
	if (columnindex >= column || columnindex < 0)
	{
		throw_logic_error("删除列范围越界");
		return;
	}
	T* datetemp = data;
	int newcolumn = column - 1;
	data = new T[row * newcolumn];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < columnindex; j++)
			this->data[i * newcolumn + j] = datetemp[i * column + j];
	for (int i = columnindex; i < newcolumn; i++)
		for (int j = 0; j < this->row; j++)
			this->data[i * row + j] = datetemp[(i + 1) * row + j];
	column = newcolumn;
	delete[] datetemp;
}

template<class T>
inline KMatrix<T> KMatrix<T>::transpose() const
{
	KMatrix p(column, row);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			p.setData(i, j, this->getData(j, i));
	return p;
}

template<class T>
inline void KMatrix<T>::print() const
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			if (j == 0) {
				std::cout << "| ";
			}
			std::cout.width(5);
			std::cout << getData(i, j) << " ";
			if (j == column - 1) {
				std::cout << "|";
				std::cout << endl;
			}
		}
}