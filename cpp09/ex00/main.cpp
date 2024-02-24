#include "MutantStack.hpp"

int main()
{
	std::cout << "\n\e[32mSubject main tests\e[0m\n" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "\n\e[32mExtra main tests\e[0m\n" << std::endl;

	std::cout << "\e[33mPrinting a copy contructor\e[0m" << std::endl;
	MutantStack<int> copy(mstack);
	print(copy);

	std::cout << "\e[33mPrinting a copy and assign constructor\e[0m" << std::endl;
	MutantStack<int> copy2;
	copy2 = mstack;
	print(copy2);

	std::cout << "\e[33mCreating a string MutantStack\e[0m" << std::endl;
	MutantStack<std::string> sstack;
	sstack.push("42");
	sstack.push("is");
	sstack.push("awesome");
	print(sstack);
	return 0;
}
