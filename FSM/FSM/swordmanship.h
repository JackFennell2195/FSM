#include "State.h"

class Swordmanship :public State
{
public:
	Swordmanship() {};
	~Swordmanship() {};
	void idle(Animation* a);
};
