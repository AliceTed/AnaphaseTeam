#ifndef _POINT_H_
#define _POINT_H_
struct Point
{
public:
	int x;
	int y;
	Point();
	Point(const Point& _p);
	Point(int _x, int _y);

	Point& operator +();
	Point& operator -();
	Point& operator +=(const Point& p);
	Point& operator -=(const Point& p);
	Point& operator *=(int i);
	Point& operator /=(const Point& p);
	Point& operator /=(int i);
	bool operator ==(const Point& p);
	bool operator !=(const Point& p);
	bool operator >=(const Point& p);
	bool operator <=(const Point& p);
	bool operator >(const Point& p);
	bool operator <(const Point& p);
};

const Point operator +(const Point& p1, const Point& p2);
const Point operator -(const Point& p1, const Point& p2);
const Point operator *(const Point& p, int i);
const Point operator /(const Point& p, int i);
const Point operator /(int i, const Point& p);

const bool operator ==(const Point& p1, const Point& p2);
const bool operator !=(const Point& p1, const Point& p2);
const bool operator >=(const Point& p1, const Point& p2);
const bool operator <=(const Point& p1, const Point& p2);
const bool operator >(const Point& p1, const Point& p2);
const bool operator <(const Point& p1, const Point& p2);

#endif