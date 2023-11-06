#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	m_contacts[7];

public:
	PhoneBook()
	{
		// std::cout << "Contact created" << std::endl;
	}

	void	addContact()
	{
		int	i = 0;
		while (m_contacts[i].getFirstName().compare(""))
		{
			i++;
		}
		std::cout << i << std::endl;
	}

	void	print(int n)
	{
		if (n < 8 && n >= 0)
			std::cout << "Contact name " << m_contacts[n].getFirstName() << std::endl;
		else
			std::cout << "OUT OF ARRAY!!!" << std::endl;
	}

	~PhoneBook()
	{
		// std::cout << "Contact destroyed" << std::endl;
	}
};
