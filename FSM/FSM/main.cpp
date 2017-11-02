#include "Animation.h"
#include <iostream>

int main() 
{
		Animation fsm; int i = 0;
		while (true)
		{
				if (i == 0)
				{
						fsm.jumping();
						std::this_thread::sleep_for(std::chrono::milliseconds dura(1000));
						i = 1;
				}
				else 
				{
						fsm.swordmanship();
						std::this_thread::sleep_for(std::chrono::milliseconds dura(1000));
						i = 0;
				}
		}
}