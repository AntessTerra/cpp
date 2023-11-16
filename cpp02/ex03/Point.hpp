#ifndef __POINT__
#define __POINT__

class Point
{
private:
	int		_x, _y;
	Point*	_left;
	Point*	_right;
public:
	Point(int x, int y);
	~Point();
};

#endif __POINT__
