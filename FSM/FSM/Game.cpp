#include "Game.h"
#include <iostream>


	
	static double const MS_PER_UPDATE = 10.0;
	Animation fsm;
	Game::Game()
		: m_window(sf::VideoMode(800,800),"FSM Life",sf::Style::Default)
	{
		m_Sprite.setPosition(250, 250);
		idleTexture();

		setUpTextFont();
		
		if (!m_hammerTime.loadFromFile("resources\\IMAGES\\SpinHammer.png"))
		{
			std::string s("Error loading texture");
			throw std::exception(s.c_str());
		}
	
		if (!m_jumpAround.loadFromFile("resources\\IMAGES\\jumping.png"))
		{
			std::string s("Error loading texture");
			throw std::exception(s.c_str());
		}
		

		if (!m_shovelling.loadFromFile("resources\\IMAGES\\shovel.jpg"))
		{
			std::string s("Error loading texture");
			throw std::exception(s.c_str());
		}


		if (!m_swordPlay.loadFromFile("resources\\IMAGES\\sword.jpg"))
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
	void Game::render()
	{
		m_window.clear(sf::Color::White);
		m_window.draw(m_Sprite);
		m_window.draw(m_controls);
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
		if (sf::Event::KeyPressed == event.type)
		{
			
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_window.close();
				break;

			case sf::Keyboard::Up:
				fsm.jumping();
				m_Sprite.setTexture(m_jumpAround);
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				break;

			case sf::Keyboard::Right:
				fsm.swordmanship();
				m_Sprite.setTexture(m_swordPlay);
				
				break;

			case sf::Keyboard::Down:
				fsm.shovelling();
				m_Sprite.setTexture(m_shovelling);
				
				break;

			case sf::Keyboard::Left:
				fsm.hammering();
				m_Sprite.setTexture(m_hammerTime);
				
				break;
				
			default:
				break;

			}
			
		}
		if (sf::Event::KeyReleased == event.type)
		{
			idleTexture();
		}
		
	}

	void Game::idleTexture()
	{
		if (!m_currentTexture.loadFromFile("resources\\IMAGES\\idle.png"))
		{
			std::string s("Error loading texture");
			throw std::exception(s.c_str());
		}
		fsm.idle();
		m_Sprite.setTexture(m_currentTexture);
	}

	void Game::setUpTextFont()
	{
		if (!m_ArialBlackfont.loadFromFile("resources\\FONTS\\ariblk.ttf"))
		{
			std::cout << "problem loading arial black font" << std::endl;
		}
		m_controls.setFillColor(sf::Color::Black);
		m_controls.setCharacterSize(30);
		m_controls.setFont(m_ArialBlackfont);
		m_controls.setString("Up key to jump\nDown key to dig\nLeft key to hammer\nRight key to sword attack");
		m_controls.setPosition(50, 50);
	}
