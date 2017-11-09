//@author Jack Fennell 
//@date 3/11/17
//C00220386
#include <SFML\Graphics.hpp>
#include "State.h"

class Hammering :public State
{
public:
	Hammering() {};
	~Hammering() {};
	void idle(Animation* a);
	
};