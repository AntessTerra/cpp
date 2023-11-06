#include <iostream>

class Contact
{
private:
	int			m_index;
	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_darkest_secret;
	int			m_phone_number;

public:
	Contact(int index = 0, std::string first_name = "", std::string last_name = "",
		std::string nickname = "", std::string darkest_secret = "",
		int phone_number = 0)
		: m_index(index), m_first_name(first_name), m_last_name(last_name),
		m_nickname(nickname), m_darkest_secret(darkest_secret),
		m_phone_number(phone_number)
	{
		// std::cout << "Contact created" << std::endl;
	}

	void	setFirstName(std::string first_name)
	{
		m_first_name = first_name;
	}

	std::string	getFirstName()
	{
		return (m_first_name);
	}

	~Contact()
	{
		// std::cout << "Contact destroyed" << std::endl;
	}
};


