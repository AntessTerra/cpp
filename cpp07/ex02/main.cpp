#include <cstdlib>
#include "Array.hpp"

#define N 10
int main(void)
{
	Array<int> numbers(N);
	int* mirror = new int[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	for (int i = 0; i < N; i++)
		if (mirror[i] != numbers[i])
			return std::cerr << "didn't save the same value!!" << std::endl, 1;

	try{
		numbers[-2] = 0;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	try{
		numbers[N] = 0;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	::printArray(numbers);
	delete [] mirror;

	Array<std::string> strings(N);
	for (int i = 0; i < N; i++)
		strings[i] = "Ahoj";
	::printArray(strings);

	Array<std::string> empty;
	::printArray(empty);

	return 0;
}
