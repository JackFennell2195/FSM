#include "Game.h"
#include <iostream>


	Animation fsm;
	static double const MS_PER_UPDATE = 10.0;
	
	Game::Game()
		: m_window(sf::VideoMode(800,800),"FSM Life",sf::Style::Default)
	{
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

	void Game::render()
	{
		m_window.clear(sf::Color(0, 0, 0, 0));
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
				if (event.type == sf::Event::KeyPressed)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						{
							fsm.jumping();
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
						{
							fsm.swordmanship();
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
						{
							fsm.shovelling();
						}
	
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
						{
							fsm.hammering();
						}
					}
				processGameEvents(event);
			}

	}

	void Game::processGameEvents(sf::Event &)
	{
	}
