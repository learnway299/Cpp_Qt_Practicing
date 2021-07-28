#include "Vec2D.h"
#include<cmath>
#include<iostream>
using namespace std;
#define PI 3.14

double Vec2D::magnitude() const
{
	return sqrt(x * x + y * y);
}

//根据坐标x、y值计算其方位角
double GetPointHAngle(double xx, double yy)
{
	double angle_temp = 0.0;
	if (xx == 0.0)
		angle_temp = PI / 2.0;
	else
		angle_temp = atan(fabs(yy / xx));
	if ((xx < 0.0) && (yy >= 0.0))
		angle_temp = PI - angle_temp;
	else if ((xx < 0.0) && (yy < 0.0))
		angle_temp = PI + angle_temp;
	else if ((xx >= 0.0) && (yy < 0.0))
		angle_temp = PI * 2.0 - angle_temp;
	return angle_temp;
}

double Vec2D::direction()
{
	return  GetPointHAngle(x, y);
}

string Vec2D::toString() const
{
	return "(" + to_string(x) + "," + to_string(y) + ")";
}

double& Vec2D::operator[](int i)
{
	if (i == 0) {
		return x;
	}
	else if (i == 1) {
		return y;
	}
	else
	{
		std::cout << "error index gived" << std::endl;
		double flg = 0.0;
		return flg;
	}
}

Vec2D::operator double() const
{
	return magnitude();
}

Vec2D Vec2D::negative()
{
	x *= -1;
	y *= -1;
	return *this;
}

Vec2D Vec2D::operator++()
{
	x += 1;
	y += 1;
	return *this;
}

Vec2D Vec2D::operator++(int)
{
	Vec2D tmp(x, y);
	tmp.x += 1;
	tmp.y += 1;
	return tmp;
}

Vec2D Vec2D::operator--()
{
	x -= 1;
	y -= 1;
	return *this;
}

Vec2D Vec2D::operator--(int)
{
	Vec2D tmp(x, y);
	x -= 1;
	y -= 1;
	return tmp;
}

int Vec2D::compareTo(const Vec2D& r)
{
	if (magnitude() > r.magnitude())
		return 1;
	if (magnitude() < r.magnitude())
		return -1;
	else
		return 0;
}

Vec2D Vec2D::operator+(const Vec2D& t)
{
	Vec2D r(t.x, t.y);
	r.x = x + r.x;
	r.y = y + r.y;
	return r;
}

Vec2D Vec2D::operator-(const Vec2D& t)
{
	Vec2D r(t.x, t.y);
	r.x = x - r.x;;
	r.y = y - r.y;
	return r;
}

int Vec2D::operator*(const Vec2D& r)
{
	double tmp = x * r.x + y * r.y;
	return int(tmp);
}

Vec2D Vec2D::operator+=(const Vec2D& r)
{
	x += r.x;
	y += r.y;
	return *this;
}

Vec2D Vec2D::operator-=(const Vec2D& r)
{
	x -= r.x;
	y -= r.y;
	return *this;
}

Vec2D Vec2D::operator-()
{
	x *= -1;
	y *= -1;
	return *this;
}

Vec2D operator*(double n, const Vec2D& t)
{
	Vec2D r(t.x, t.y);
	r.x *= n;
	r.y *= n;
	return r;
}

Vec2D operator*(const Vec2D& t, double n)
{
	Vec2D r(t.x, t.y);
	r.x *= n;
	r.y *= n;
	return r;
}

Vec2D operator+(const Vec2D& t, double n)
{
	Vec2D r(t.x, t.y);
	r.x += n;
	r.y += n;
	return r;
}

Vec2D operator+(double n, const Vec2D& t)
{
	Vec2D r(t.x, t.y);
	r.x += n;
	r.y += n;
	return r;
}

ostream& operator<<(ostream& str, const Vec2D& r)
{
	str << r.toString();
	return str;
}

istream& operator>>(istream& str, Vec2D& r)
{
	str >> r.x >> r.y;
	return str;
}