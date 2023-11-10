#include "Zombie.hpp"

int main(void)
{
	randomChump("FILIP");

	Zombie *z = newZombie("ANDEI");
	z->announce();
	delete z;
}
