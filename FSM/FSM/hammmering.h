#include <SFML\Graphics.hpp>
#include "State.h"

class Hammering :public State
{
public:
	Hammering() {};
	~Hammering() {};
	void idle(Animation* a);
	
};