#ifndef __TYPEDETECTOR__
#define __TYPEDETECTOR__

#include <iostream>
#include <cstdlib>

//Class with public virtual destructor only
class Base {public: virtual ~Base();};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base**	generate(int N);
void	identify(Base* p);
void	identify(Base& p);

#endif
