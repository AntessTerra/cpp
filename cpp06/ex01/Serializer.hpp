#ifndef __SERIALIZER__
#define __SERIALIZER__

#include <iostream>
#include <stdint.h>

struct Data{
	std::string name;
	int			id;
};

//Static class with private constructor and static methods
class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& ser);
	~Serializer();
	Serializer& operator = (const Serializer& ser);
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif
