#include "Game.h"
#include <iostream>


	Animation fsm;
	static double const MS_PER_UPDATE = 10.0;
	
	Game::Game()
		: m_window(sf::VideoMode(800,800),"FSM Life",sf::Style::Default)
	{
		
		if (!m_currentTexture.loadFromFile("resources\\IMAGES\\idle.png"))///FSM/resources/IMAGES/SpinHammer.png
		{
			std::string s("Error loading texture");
			throw std::exception(s.c_str());
		}
		

		if (!m_hammerTime.loadFromFile("resources\\IMAGES\\SpinHammer.png"))///FSM/resources/IMAGES/SpinHammer.png
		{
			std::string s("Error loading texture");
			throw std::exception(s.c_str());
		}
		
	}
	

	void Game::run()
	{
		sf::Clock clock;
		sf::Int32 lag = 0;

		while (m_window.isOpen())
		{
			sf::Time dt = clock.restart();

			lag += dt.asMilliseconds();

			processEvents();

			while (lag > MS_PER_UPDATE)
			{
				update(MS_PER_UPDATE);
				lag -= MS_PER_UPDATE;
			}
			update(MS_PER_UPDATE);

			render();
		}
	}

	void Game::update(double dt)
	{

	}
	void Game::setCurrentSprite()
	{
		m_Sprite.setPosition(200, 200);
		
	}
	void Game::render()
	{
		m_window.clear(sf::Color::White);
		m_window.draw(m_Sprite);
		m_window.display();
	}

	void Game::processEvents()
	{
			sf::Event event;
		
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					m_window.close();
				}
					processGameEvents(event);
			}

	}

	

	void Game::processGameEvents(sf::Event & event)
	{
		if (sf::Event::KeyPressed== event.type)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
				m_window.close();
				break;

				case sf::Keyboard::Up:
				fsm.jumping();
				
				break;
				
				case sf::Keyboard::Down:
				fsm.swordmanship();
				
				break;

				case sf::Keyboard::Left:
				fsm.shovelling();
				
				break;

				case sf::Keyboard::Right:
				fsm.hammering();
				m_Sprite.setTexture(m_hammerTime);
				
				break;

				default:
					break;
				
				}
			}
		
	}
