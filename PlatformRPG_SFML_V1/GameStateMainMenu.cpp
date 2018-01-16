#include "GameStateMainMenu.h"
#include "ResourceHolder.h"



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
				//ummm I guess just do something?
				m_menu_text.setString("You pressed space like a champ!");
			}
			break;
		default:
			break;
		}
	}
}

void GameStateMainMenu::handleInput()
{
}
