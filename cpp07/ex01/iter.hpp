#ifndef __ITER__
#define __ITER__

#include <iostream>
#include <typeinfo>

#define INT_NAME typeid(int).name()
#define FLOAT_NAME typeid(float).name()
#define STRING_NAME typeid(std::string).name()

template <typename T>
void	iter(T& array, int length, void (*func)(T elem)){
	for (int i = 0; i < length; i++)
		func(&array[i]);
}

template <typename T>
void	addOne(T elem){
	std::string	type(typeid(*elem).name());
	if (type == INT_NAME)
		*elem += 1;
	else if (type == FLOAT_NAME)
		*elem += 1.5;
}

template <typename T>
void	addMark(T elem){
	std::string	type(typeid(*elem).name());
	if (type == STRING_NAME)
		elem->append("!");
}

template <typename T>
void	printArray(T& array, int length){
	std::cout << "PRINTING ARRAY OF " << typeid(array[0]).name() << std::endl;
	for (int i = 0; i < length; i++)
		std::cout << array[i] << std::endl;
	std::cout << std::endl;
}


#endif
