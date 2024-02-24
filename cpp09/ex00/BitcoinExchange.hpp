#ifndef __BITCOINEXCHANGE__
#define __BITCOINEXCHANGE__

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack& original) : std::stack<T>() {
		if (!original.empty())
			for (const_iterator it = original.begin(); it != original.end(); it++)
				this->push(*it);
	}
	MutantStack& operator=(const MutantStack& src){
		if (this != &src){
			this->clear();
			for (const_iterator it = src.begin(); it != src.end(); it++)
				this->push(*it);
		}
		return *this;
	}
	~MutantStack(){};

	//::container_type just points to std::deque in stack class
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	/*
		c is a protected member of stack class that references std::deque class
		which has iterators. This code just expooses them to be used outside
	*/
	iterator begin(){return this->c.begin();}
	iterator end(){return this->c.end();}

	const_iterator begin() const {return this->c.begin();}
	const_iterator end() const {return this->c.end();}

	//Empties the stack
	void clear(){while (!this->empty()) this->pop();}
};

template <typename T>
void print(T& li){
	for (typename T::const_iterator it = li.begin(); it != li.end(); it++)
		std::cout << *it << std::endl;
}

#endif
