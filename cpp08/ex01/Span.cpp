#include "Span.hpp"

Span::Span(int length){
	_length = length;
	std::cout << "Creating a new Span!!" << std::endl;
	return ;
}

Span::Span(const Span& span){
	std::cout << "Copying a Span!!" << std::endl;
	if (!span._list.empty()){
		for (std::list<int>::const_iterator i = span._list.begin(); i != span._list.end(); i++)
			_list.push_back(*i);
	}
	return ;
}

Span::~Span(){
	std::cout << "Deleting a Span!!" << std::endl;
	return ;
}

Span&		Span::operator = (const Span& span){
	std::cout << "Copy & assign a Span!!" << std::endl;
	if (this != &span){
		_list.clear();
		for (std::list<int>::const_iterator i = span._list.begin(); i != span._list.end(); i++)
			_list.push_back(*i);
	}
	return *this;
}

void Span::addNumber(int number){
	if (_list.size() >= _length)
		throw std::out_of_range("\e[31mSpan full, cannot add more!!\e[0m");
	else
		_list.push_back(number);
}

void Span::shortestSpan(int){
	if (_list.size() < 2)
		throw std::out_of_range("\e[31mNot enough numbers to calculate span!!\e[0m");
}

void Span::longestSpan(int){
	if (_list.size() < 2)
		throw std::out_of_range("\e[31mNot enough numbers to calculate span!!\e[0m");
}
