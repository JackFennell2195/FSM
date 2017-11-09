//@author Jack Fennell 
//@date 3/11/17
//C00220386
#include "State.h"

class Swordmanship :public State
{
public:
	Swordmanship() {};
	~Swordmanship() {};
	void idle(Animation* a);
};
