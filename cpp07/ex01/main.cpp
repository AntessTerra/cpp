#include "iter.hpp"

int	main(void){
	int ints[5]= {1, 2, 3, 4, 5};

	::printArray(ints, 5);
	::iter(ints, 5, ::addOne);
	::printArray(ints, 5);

	float floats[5]= {1, 2, 3, 4, 5};

	::printArray(floats, 5);
	::iter(floats, 5, ::addOne);
	::printArray(floats, 5);

	std::string strings[2] = {"Alex", "Dell"};

	::printArray(strings, 2);
	::iter(strings, 2, ::addMark);
	::printArray(strings, 2);
}
