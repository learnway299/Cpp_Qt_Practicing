#pragma once
#include <string>
using namespace std;

class Vec2D
{
private:
	double x;
	double y;

public:
	Vec2D() { x = 0.0; y = 0.0; };
	Vec2D(double a, double b) :x(a), y(b) {};

	double magnitude()const;
	double direction();
	string toString()const;
	double& operator[](int i);
	operator double() const;
	Vec2D negative();

	Vec2D operator ++();
	Vec2D operator ++(int);
	Vec2D operator --();
	Vec2D operator --(int);
	int compareTo(const Vec2D&);

	Vec2D operator +(const Vec2D&);
	Vec2D operator -(const Vec2D&);
	int operator *(const Vec2D&);
	Vec2D operator +=(const Vec2D&);
	Vec2D operator -=(const Vec2D&);
	Vec2D operator -();

	friend Vec2D operator *(double, const Vec2D&);
	friend Vec2D operator *(const Vec2D&, double);
	friend Vec2D operator +(const Vec2D&, double);
	friend Vec2D operator +(double, const Vec2D&);
	friend ostream& operator<<(ostream&, const  Vec2D&);
	friend istream& operator>>(istream&, Vec2D&);
};

