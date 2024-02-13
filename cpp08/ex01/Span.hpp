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
	void shortestSpan(int);
	void longestSpan(int);
};

template <typename T>
void print(T& li){
	for (typename T::iterator it = li.begin(); it != li.end(); it++)
			std::cout << *it << std::endl;
}

#endif
