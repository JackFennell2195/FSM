//@author Jack Fennell 
//@date 3/11/17
//C00220386
#include "idle.h"
#include <iostream>

void Idle::jumping(Animation * a)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Idle::swordmanship(Animation * a)
{
	std::cout << "Swordmanship" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Idle::shovelling(Animation * a)
{
	std::cout << "Shovelling" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Idle::hammering(Animation * a)
{
	std::cout << "Hammering" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
