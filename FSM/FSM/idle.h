//@author Jack Fennell 
//@date 3/11/17
//C00220386
#include "State.h"


class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void jumping(Animation* a);
	void swordmanship(Animation* a);
	void shovelling(Animation* a);
	void hammering(Animation* a);
};
