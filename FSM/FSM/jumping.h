//@author Jack Fennell 
//@date 3/11/17
//C00220386
#include "State.h"

class Jumping :public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a);
};