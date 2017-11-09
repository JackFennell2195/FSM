//@author Jack Fennell 
//@date 3/11/17
//C00220386
#pragma once

class Animation
{
	class State* current;
public:
	Animation();
	void setCurrent(State* s)
	{ 
		current = s; 
	}
	void idle();
	void jumping();
	void swordmanship();
	void shovelling();
	void hammering();
};


