#ifndef __SPAN__
#define __SPAN__

#include <iostream>
#include <algorithm>
#include <list>
#include <numeric>

class Span
{
private:
	std::list<int>	_list;
	unsigned int	_length;
public:
	Span(int);
	Span(const Span&);
	~Span();
	Span& operator = (const Span&);

	void addNumber(int);
	int shortestSpan();
	int longestSpan();
	void addNumbers(std::list<int>::iterator, std::list<int>::iterator);
	void print();
};

#endif
