#include "../../../header/convenient/Point.h"

Point::Point()
	:x(0),y(0)
{
}
Point::Point(int _x, int _y)
	:x(_x),y(_y)
{
}

Point::Point(const Point& _p)
	: x(_p.x),y(_p.y)
{
}

Point&  Point::operator +()
{
	return *this; 
}
Point&  Point::operator -()
{
	this->y= -this->y;
	this->x = -this->x;
	return *this;
}
Point& Point::operator +=(const Point& p)
{
	x += p.x;
	y += p.y;
	return *this;
}
Point& Point::operator -=(const Point& p)
{
	x -= p.x;
	y -= p.y;
	return *this;
}
Point& Point::operator *=(int i)
{
	x *= i;
	y *= i;
	return *this;
}
Point& Point::operator /=(const Point& p)
{
	x /= p.x;
	y /= p.y;
	return *this;
}
Point& Point::operator /=(int i)
{
	x /= i;
	y /= i;
	return *this;
}
bool Point::operator ==(const Point& p)
{
	return x == p.x&&y == p.y;
}
bool Point::operator !=(const Point& p)
{
	return !(*this == p);
}
bool Point::operator >=(const Point& p)
{
	return (x >= p.x&&y >= p.y);
}
bool Point::operator >(const Point& p)
{
	return (x > p.x&&y > p.y);
}
bool Point::operator <=(const Point& p)
{
	return !(*this > p);
}
bool Point::operator <(const Point& p)
{
	return !(*this >= p);
}

//‚Q€‰‰ŽZŽq
const Point operator +(const Point& p1, const Point& p2)
{
	Point temp(p1);
	return temp += p2;
}
const Point operator -(const Point& p1, const Point& p2)
{
	Point temp(p1);
	return temp -= p2;
}
const Point operator *(const Point& p, int i)
{
	Point temp(p);
	return temp *= i;
}
const Point operator /(const Point& p, int i)
{
	Point temp(p);
	return temp /= i;
}
const Point operator /(int i, const Point& p)
{
	return Point(i / p.x, i/ p.y);
}
const bool operator ==(const Point& p1, const Point& p2)
{
	return p1.x == p2.x&& p1.y == p2.y;
}
const bool operator !=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}
const bool operator >=(const Point& p1, const Point& p2)
{
	return (p1.x >= p2.x&&p1.y >= p2.y);
}
const bool operator <=(const Point& p1, const Point& p2)
{
	return !(p1 > p2);
}
const bool operator >(const Point& p1, const Point& p2)
{
	return (p1.x > p2.x&&p1.y > p2.y);
}
const bool operator <(const Point& p1, const Point& p2)
{
	return !(p1 >= p2);
}