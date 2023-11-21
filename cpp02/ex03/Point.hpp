#ifndef __POINT__
#define __POINT__

#include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x, _y;
public:
	Point();
	Point(float const x, float const y);
	Point(const Point &point);
	~Point();
	Point&	operator = (const Point &Point);

	const Fixed&	getX() const;
	const Fixed&	getY() const;

};
bool	bsp(Point const a,  Point const b, Point const c, Point const point);

#endif
