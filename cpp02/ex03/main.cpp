#include <iostream>
#include "Point.hpp"

void	draw(Point const a, Point const b, Point const c, Point const point){
	Fixed	bigest;
	int	x,y;
	bigest = a.getX().max(a.getX(), b.getX());
	bigest = b.getX().max(bigest.toInt(), c.getX());
	bigest = c.getX().max(bigest.toInt(), point.getX());
	x = bigest.toInt();
	bigest = a.getY().max(a.getY(), b.getY());
	bigest = b.getY().max(bigest.toInt(), c.getY());
	bigest = c.getY().max(bigest.toInt(), point.getY());
	y = bigest.toInt();
	for (int i = y; i >= 0; i--){
		for (int f = 0; f <= x; f++){
			if (a.getX() == f && a.getY() == i)
				std::cout << 'A';
			else if (b.getX() == f && b.getY() == i)
				std::cout << 'B';
			else if (c.getX() == f && c.getY() == i)
				std::cout << 'C';
			else if (point.getX() == f && point.getY() == i)
				std::cout << 'P';
			else
				std::cout << '.';
		}
		std::cout << std::endl;
	}
}

int main( void ) {
	Point	A(0, 0), B(20, 0), C(10, 30), P(10, 15);
	draw(A, B, C, P);
	if (bsp(A, B, C, P))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is NOT inside the triangle" << std::endl;
	return (0);
}
