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

Span&	Span::operator = (const Span& span){
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
	_list.push_back(number);
	return ;
}

void Span::addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end){
	_list.insert(_list.end(), begin, end);
	if (_list.size() > _length)
		throw std::out_of_range("\e[31mSpan full, cannot add more!!\e[0m");
	return ;
}

int Span::shortestSpan(){
	if (_list.size() < 2)
		throw std::out_of_range("\e[31mNot enough numbers to calculate span!!\e[0m");
	std::list<int>	tmp(_list);
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	int	result = *(std::max_element(_list.begin(), _list.end()));
	for (std::list<int>::const_iterator it = ++tmp.begin(); it != tmp.end(); it++)
			if (abs(*it) < result) result = abs(*it);
	return result;
}

int Span::longestSpan(){
	if (_list.size() < 2)
		throw std::out_of_range("\e[31mNot enough numbers to calculate span!!\e[0m");
	return (*(std::max_element(_list.begin(), _list.end())) - *(std::min_element(_list.begin(), _list.end())));
}

void Span::print(){
	for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); it++)
			std::cout << *it << std::endl;
	return ;
}
