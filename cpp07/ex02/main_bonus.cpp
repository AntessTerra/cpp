#include <cstdlib>
#include "Array.hpp"
#include "Array_bonus.hpp"

#define N 10
int main(void)
{
	Array<int> numbers(N);
	srand(time(NULL));
	for (int i = 0; i < N; i++)
		numbers[i] = rand();

	::printArray(numbers);
	::iter(numbers, ::addOne);
	::printArray(numbers);

	Array<std::string> strings(N);
	for (int i = 0; i < N; i++)
		strings[i] = "Ahoj";
	::printArray(strings);
	::iter(strings, ::addMark);
	::printArray(strings);

	return 0;
}
