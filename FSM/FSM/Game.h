//@author Jack Fennell 
//@date 3/11/17
//C00220386
#pragma once

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include <string>
#include <chrono>
#include <thread>
class Game
{
public: 
	Game();
	void run();
	void update(double dt);
	void render();
	void processEvents();
	void processGameEvents(sf::Event&);
	void idleTexture();
	void setUpTextFont();
	sf::RenderWindow m_window;
	
private:
	bool actionTaken;
	sf::Sprite m_Sprite;
	sf::Font m_ArialBlackfont;
	sf::Texture m_currentTexture;
	sf::Texture m_hammerTime;
	sf::Texture m_jumpAround;
	sf::Texture m_swordPlay;
	sf::Texture m_shovelling;
	sf::Text m_controls;
	
};