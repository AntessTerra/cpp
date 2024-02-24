#include "Span.hpp"

int main(void){
	Span span = Span(10);
	// srand(time(0));
	// for (int count=0; count < 5; ++count)
	// 	span.addNumber(rand() % 1000);
	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	span.print();
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	std::cout << "\n\e[32mAdding more numbers at once\e[0m\n" << std::endl;

	std::list<int> tmp;
	for (int count=0; count < 5; ++count)
		tmp.push_back(count);

	span.addNumbers(tmp.begin(), tmp.end());

	span.print();

	std::cout << "\n\e[31mGetting an error!!\e[0m\n" << std::endl;

	Span wrong = Span(1);
	try {
		std::cout << "Longest span: " << wrong.longestSpan() << std::endl;
		std::cout << "Shortest span: " << wrong.shortestSpan() << std::endl;}
	catch (std::exception& e){std::cerr << e.what() << std::endl;}
}
