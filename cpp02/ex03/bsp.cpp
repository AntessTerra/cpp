#include "Point.hpp"
#include <cmath>

Fixed	area(int x1, int y1, int x2, int y2, int x3, int y3){
	float	area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))) / 2.0;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed	A = area(a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	Fixed	A1 = area(point.getX().toInt(), point.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	Fixed	A2 = area(a.getX().toInt(), a.getY().toInt(), point.getX().toInt(), point.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	Fixed	A3 = area(a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt(), point.getX().toInt(), point.getY().toInt());
	return (A == A1 + A2 + A3);
}
