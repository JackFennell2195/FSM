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
	void setCurrentSprite();
	void processGameEvents(sf::Event&);
	sf::RenderWindow m_window;
	enum CurrentState
	{
		IDLE,
		JUMP,
		HAMMER,
		SHOVEL,
		SWORD
	};
private:
	sf::Sprite m_Sprite;
	sf::Texture m_currentTexture;
	sf::Texture m_hammerTime;
	sf::Texture m_jumpAround;
	sf::Texture m_swordPlay;
	sf::Texture m_shovelling;
	
};