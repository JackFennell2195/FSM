//@author Jack Fennell 
//@date 3/11/17
//C00220386
#include "State.h"

class Shovelling :public State
{
public:
	Shovelling() {};
	~Shovelling() {};
	void idle(Animation* a);
};
