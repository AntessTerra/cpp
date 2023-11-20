#include "Point.hpp"
#include <cmath>

Fixed	calc_w1(Point const a, Point const b, Point const c, Point const point){
	Fixed	num = (a.getX() * (c.getY() - a.getY())) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY());
	Fixed	denum = (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY());
	Fixed	w1 = Fixed(num / denum);

	return (w1);
}

Fixed	calc_w2(Fixed w1, Point const a, Point const b, Point const c, Point const point){
	Fixed	num = point.getY() - a.getY() - w1 * (b.getY() - a.getY());
	Fixed	denum = c.getY() - a.getY();
	Fixed	w2 = Fixed(num / denum);

	return (w2);
}

// Fixed	area(int x1, int y1, int x2, int y2, int x3, int y3){
// 	float	area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))) / 2.0;
// 	return (area);
// }

bool	bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed	w1 = calc_w1(a, b, c, point);
	Fixed	w2 = calc_w2(w1, a, b, c, point);

	if (w1.toFloat() > 0 && w2.toFloat() > 0 && (w1.toFloat() + w2.toFloat()) < 1)
		return (true);
	else
		return (false);

	// Fixed	A = area(a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	// Fixed	A1 = area(point.getX().toInt(), point.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	// Fixed	A2 = area(a.getX().toInt(), a.getY().toInt(), point.getX().toInt(), point.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	// Fixed	A3 = area(a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt(), point.getX().toInt(), point.getY().toInt());
	// return (A == A1 + A2 + A3);
}
