#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <ncurses.h>
#include <iostream>

class Window
{
private:
	WINDOW		*_window;
	float		_height, _width, _startx, _starty;
public:
	Window(float height, float width, float startx, float starty);
	Window(const Window& window);
	~Window();
	Window&	operator = (const Window& window);

	void	doBox();
	void	doRefresh();
};

class Graphics
{
private:
	/* data */
public:
	Graphics();
	Graphics(const Graphics& graphics);
	~Graphics();
	Graphics&	operator = (const Graphics& graphics);
};

#endif
