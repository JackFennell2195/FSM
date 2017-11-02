#include "Animation.h"
#include <iostream>

class State
{
public:
	virtual void idle(Animation* a)
	{
		std::cout << "State::Idling" << std::endl;
	}
	virtual void jumping(Animation* a)
	{
		std::cout << "State::Jumping" << std::endl;
	}
	virtual void swordmanship(Animation* a)
	{
		std::cout << "State::Swordmanship" << std::endl;
	}
	virtual void shovelling(Animation* a)
	{
		std::cout << "State::Shovelling" << std::endl;
	}
	virtual void hammering(Animation* a)
	{
		std::cout << "State::Hammering" << std::endl;
	}
};