#pragma once
#include <exception>          //�쳣
#include <stdexcept>          //�쳣
#include <stdexcept>          //�쳣����
#include <iostream>
using namespace std;

//���������������ڳ����߼�����ʱ��������Ϣ
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
	KMatrix() :row(0), column(0) {}//�����վ���
	KMatrix(int row, int column); //����row X column�վ���
	KMatrix<T>(int row, int column, T* data);//�����鹹������
	KMatrix<T>(const KMatrix<T>& another);//��������

	bool isempty();//���Ƿ�վ���
	bool operator==(KMatrix<T>& another);//���ؾ���Ⱥ�==�����
	void myiterator();
	KMatrix<T>& operator=(const KMatrix<T>& another);//���ظ�ֵ�����
	T operator()(int i, int j) const;//����()�����
	T operator()(int i) const;
	KMatrix<T> operator+(T x);//����Ԫ��+�����
	KMatrix<T>& operator+=(T x);//����Ԫ��+=�����
	KMatrix<T> operator+(const KMatrix<T>& another);//���ؾ���+�����
	KMatrix<T>& operator+=(const KMatrix<T>& another);//���ؾ���+=�����
	KMatrix<T> operator-(T x);//����Ԫ��-�����
	KMatrix<T>& operator-=(T x);//����Ԫ��-=�����
	KMatrix<T> operator-(const KMatrix<T>& another);//���ؾ���-�����
	KMatrix<T>& operator-=(const KMatrix<T>& another);//���ؾ���-=�����
	KMatrix<T> operator*(T x);//����Ԫ��*�����
	KMatrix<T>& operator*=(T x);//����Ԫ��*=�����
	KMatrix<T> operator*(const KMatrix<T>& another);//���ؾ���*�����
	T dotMul(const KMatrix<T>& another);//ʵ��KMatrix�ĵ��

	void init(int, int, const T);//��ʼ������
	int getRows() const;//��ȡ����
	int getCols() const;//��ȡ����
	void setData(int row, int col, T value);//�����޸�
	T getData(int row, int col) const;//���ݻ�ȡ
	void erase_row(int row);//ɾ����
	void erase_col(int col);//ɾ����
	KMatrix transpose() const;//ת��
	void print() const;////��Ҫ���־���Ļ����ṹ,����̨��ӡ���
};

template<class T>
inline KMatrix<T>::KMatrix(int row, int column)
{
	//this->data = new T[row * column];ע�ʹ���isempty()��Ч ��ע��ʧЧ
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
			std::cout << "��Ҫ��������1 ����������������" << std::endl;
			std::cin >> flg;
			if (flg == 1) {
				std::cout << "��Ҫ���ĺ������" << std::endl;
				std::cin >> tmp;
				setData(i, j, tmp);
				std::cout << "�������ݳɹ�" << std::endl;
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
		throw_logic_error("��ȡ����Ԫ�أ���������Χ");
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
		throw_logic_error("����ƥ��");
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
		throw_logic_error("����ƥ��");
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
		throw_logic_error("����ƥ��");
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
		throw_logic_error("����ƥ��");
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
		throw_logic_error("����˷�����Ϊ��");
	if (this->getCols() != another.getRows())
		throw_logic_error("����ƥ��");
	KMatrix<T> p(this->getRows(), another.getCols());
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.column; j++)
		{
			T sum = 0;//������
			for (int t = 0; t < column; t++)  //��һ������ĵ�i�г��Եڶ�������ĵ�j��
				sum += data[i * column + t] * another(t, j);
			p.setData(i, j, sum);
		}
	return p;
}

template<class T>
inline T KMatrix<T>::dotMul(const KMatrix<T>& another)
{
	T sum = 0;//������
	if (!another.data || !data)
		throw_logic_error("����������Ϊ��");
	if (this->getCols() != another.getCols() || this->getRows() != another.getRows())
		throw_logic_error("��˾���ƥ��");
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
		throw_logic_error("��ȡ����Ԫ�أ���������Χ");
	if (j > this->column - 1 || j < 0)
		throw_logic_error("��ȡ����Ԫ�أ���������Χ");
	return data[i * column + j];
}

template<class T>
inline void KMatrix<T>::erase_row(int rowindex)
{
	if (rowindex >= row || rowindex < 0)
	{
		throw_logic_error("ɾ���з�ΧԽ��");
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
		throw_logic_error("ɾ���з�ΧԽ��");
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