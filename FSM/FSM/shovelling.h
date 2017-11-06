#include "State.h"

class Shovelling :public State
{
public:
	Shovelling() {};
	~Shovelling() {};
	void idle(Animation* a);
};
