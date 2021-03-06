//@author Jack Fennell 
//@date 3/11/17
//C00220386
#include "Animation.h"
#include "idle.h"

Animation::Animation()
{
	current = new Idle();
}

void Animation::idle()
{
	current->idle(this);
}

void Animation::jumping()
{
	current->jumping(this);
}

void Animation::swordmanship()
{
	current->swordmanship(this);
}

void Animation::shovelling()
{
	current->shovelling(this);
}

void Animation::hammering()
{
	current->hammering(this);
}
