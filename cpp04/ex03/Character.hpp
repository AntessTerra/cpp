#ifndef __CHARACTER__
#define __CHARACTER__

#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	std::string	_name;
	AMateria	*_inv[4];
public:
	Character(std::string name);
	Character(const Character& ch);
	~Character();
	Character& operator = (const Character& ch);

	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
