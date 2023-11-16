#include "Point.hpp"

Point::Point(int x, int y): _x(x), _y(y){
	return ;
}

Point::Point(const Point &point){
	*this = point;
}

Point::~Point(){
	return ;
}

Point&	Point::operator = (const Point &point){
	_x = point._x;
	_y = point._y;
	return (*this);
}

