#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"


class Game
{
public: 
	Game();
	void run();
	void update(double dt);
	void render();
	void processEvents();
	void processGameEvents(sf::Event&);
	sf::RenderWindow m_window;
};