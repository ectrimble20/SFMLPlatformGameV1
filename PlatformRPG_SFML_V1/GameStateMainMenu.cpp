#include "GameStateMainMenu.h"
#include "ResourceHolder.h"
#include <iostream> //yay debug


GameStateMainMenu::GameStateMainMenu(Game * game)
{
	this->game = game;
	game->window.setTitle("GameState: Main Menu");

	//this is all filler below this, need to get other stuff in place
	m_menu_background.setTexture(ResourceHolder::getTexture("background1"));
	m_menu_background.setPosition(0.0f, 0.0f);

	m_menu_text.setFont(ResourceHolder::getFont("lucon"));
	m_menu_text.setCharacterSize(24);
	m_menu_text.setFillColor(sf::Color(255, 255, 255));
	m_menu_text.setOutlineColor(sf::Color::Black);
	m_menu_text.setOutlineThickness(2.0f);
	m_menu_text.setString("Main Menu:  Hit Space To Continue");
	m_menu_text.setPosition(200.0f, 100.0f);

	//why u no work >:(
	sf::Vector2f menuPosition(200.0f, 100.0f);
	g.setContainerPosition("mainMenu", menuPosition);
}


GameStateMainMenu::~GameStateMainMenu()
{
}

void GameStateMainMenu::draw(const float deltaTime)
{
	game->window.draw(m_menu_background);
	game->window.draw(m_menu_text);
	g.draw(game->window); //see if this bullshit even remotely works.
}

void GameStateMainMenu::update(const float deltaTime)
{
	sf::Event e;
	while (game->window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;
		case sf::Event::KeyPressed:
			if (e.key.code == sf::Keyboard::Space)
			{
				centerMenu();
			}
			if (e.key.code == sf::Keyboard::Return)
			{
				sf::Vector2f menuPosition(0.0f, 0.0f);
				g.setContainerPosition("mainMenu", menuPosition);
			}
			if (e.key.code == sf::Keyboard::C)
			{
				//see if I can get this fucker to work
				g.setContainerTextCenter("mainMenu");
			}
			if (e.key.code == sf::Keyboard::M)
			{
				g.toggleContainerShown("mainMenu");
			}
			if (e.key.code == sf::Keyboard::Q)
			{
				game->window.close();
			}
			break;
		case sf::Event::MouseMoved:
			g.checkForHover("mainMenu", sf::Mouse::getPosition(game->window));
			break;
		default:
			break;
		}
	}
}

void GameStateMainMenu::handleInput()
{
}

void GameStateMainMenu::centerMenu()
{
	//top padding
	float topPadding = 150.0f;
	sf::Vector2f menuSize = g.getContainerSize("mainMenu");
	//make sure we got a valid size
	if (menuSize != sf::Vector2f(0.0f, 0.0f))
	{
		float boxWidth = menuSize.x;
		float winWidth = (float)game->window.getSize().x;
		//okay, we need to take half the window width, and subtract half the box width to get our x position
		float xPos = (winWidth * 0.5f) - (boxWidth * 0.5f);
		std::cout << "centerMenu: X position is " << xPos << ", derrived from box/win widths " << boxWidth << " " << winWidth << std::endl;
		g.setContainerPosition("mainMenu", sf::Vector2f(xPos, topPadding));
	}
	else
	{
		std::cout << "centerMenu: Got a 0,0 position from getContainerSize" << std::endl;
	}
}