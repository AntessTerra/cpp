#ifndef __EASYFIND__
#define __EASYFIND__

#include <iostream>
#include <algorithm>
#include <list>
#include <numeric>

template <typename T>
typename T::value_type easyfind(T& li, typename T::value_type val){
	typename T::iterator found = std::find(li.begin(), li.end(), val);
	return (found != li.end())? *found : throw std::exception();
}

template <typename T>
void print(T& li){
	for (typename T::iterator it = li.begin(); it != li.end(); it++)
			std::cout << *it << std::endl;
}

#endif
