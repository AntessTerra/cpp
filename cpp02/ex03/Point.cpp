#include "Point.hpp"

Point::Point(): _x(0), _y(0){
	std::cout << "Calling constructor!!!" << std::endl;
	return ;
}

Point::Point(float const x, float const y): _x(x), _y(y){
	return ;
}

Point::Point(const Point &point): _x(point.getX()), _y(point.getY()){
	return ;
}

Point::~Point(){
	return ;
}

Point&	Point::operator = (const Point &point){
	if (this == &point)
		return *this;
	return (*this);
}

const Fixed&	Point::getX() const{
	return (_x);
}

const Fixed&	Point::getY() const{
	return (_y);
}

