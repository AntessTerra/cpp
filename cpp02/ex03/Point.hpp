#ifndef __POINT__
#define __POINT__

#include "Fixed.hpp"

class Point
{
private:
	Fixed	_x, _y;
public:
	Point(int x, int y);
	Point(const Point &point);
	~Point();
	Point&	operator = (const Point &Point);
};

#endif __POINT__
