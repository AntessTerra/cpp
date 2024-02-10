#ifndef __ARRAY_BONUS__
#define __ARRAY_BONUS__

#include <typeinfo>

#define INT_NAME typeid(int).name()
#define FLOAT_NAME typeid(float).name()
#define STRING_NAME typeid(std::string).name()

template <typename T>
void	iter(Array<T>& arr, void (*func)(T& elem)){
	for (int i = 0; i < arr.size(); i++)
		func(arr[i]);
}

template <typename T>
void	addOne(T& elem){
	std::string	type(typeid(elem).name());
	if (type == INT_NAME)
		elem += 1;
	else if (type == FLOAT_NAME)
		elem += 1.5;
}

template <typename T>
void	addMark(T& elem){
	std::string	type(typeid(elem).name());
	if (type == STRING_NAME)
		elem.append("!");
}

#endif
