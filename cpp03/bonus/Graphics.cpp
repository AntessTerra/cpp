#include "Graphics.hpp"

Window::Window(float height, float width, float startx, float starty): _height(height), _width(width), _startx(startx), _starty(starty){
	_window = newwin(_height, _width, _starty, _startx);
	box(_window, 0 , 0);
	wrefresh(_window);
	return ;
}

Window::Window(const Window& window){

}

Window::~Window(){
	return ;
}

Window&	Window::operator = (const Window& window){

}

void	Window::doBox(){
	box(_window, 0, 0);
	return ;
}

void	Window::doRefresh(){
	Window::doBox();
	wrefresh(_window);
	return ;
}


Graphics::Graphics(){

}

Graphics::Graphics(const Graphics& graphics){

}

Graphics::~Graphics(){

}

Graphics&	Graphics::operator = (const Graphics &graphics){

}
