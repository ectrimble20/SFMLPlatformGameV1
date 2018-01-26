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
	m_menu_text.setCharacterSize(12);
	m_menu_text.setFillColor(sf::Color(255, 255, 255));
	m_menu_text.setOutlineColor(sf::Color::Black);
	m_menu_text.setOutlineThickness(2.0f);
	m_menu_text.setString("Play Menu:\nSpace - Centers Menu, Return\nMove menu to upper left corner\nC - Center Menu Text\nL - Left Align Menu Text\nR - Right align menu text\nQ - Exit");
	m_menu_text.setPosition(5.0f, 15.0f);

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
				g.setContainerTextCenter("mainMenu");
			}
			if (e.key.code == sf::Keyboard::L)
			{
				g.setContainerTextLeft("mainMenu");
			}
			if (e.key.code == sf::Keyboard::R)
			{
				g.setContainerTextRight("mainMenu");
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
			//ignore main menu if right-click menu is visible
			if (! g.isContainerVisible("rightClickMenu")) {
				g.checkForHover("mainMenu", sf::Mouse::getPosition(game->window));
			}
			else
			{
				if (g.isMouseOver("rightClickMenu", sf::Mouse::getPosition(game->window))) {
					g.checkForHover("rightClickMenu", sf::Mouse::getPosition(game->window));
				}
				else {
					g.toggleContainerShown("rightClickMenu");
				}
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (e.mouseButton.button == sf::Mouse::Button::Left)
			{
				if (!isDragging && g.isMouseOver("mainMenu", sf::Mouse::getPosition(game->window)) ) {
					isDragging = true;
					//set the position on from where the drag was initiated
					lastDragPosition = sf::Vector2f(sf::Mouse::getPosition(game->window));
				}
				//lets see if we can make a button do something
				//okay this isn't working because of the above code that do the thing above, we need to move this
				//into the release code
				/*
				if (!isDragging) {
					std::string action = g.getClickAction("mainMenu", sf::Mouse::getPosition(game->window));
					std::cout << "Click action: " << action << std::endl;
					if (action != "null")
					{
						if (action == "exit")
						{
							game->window.close();
						}
					}
				}
				*/
			}
			if (e.mouseButton.button == sf::Mouse::Button::Right)
			{
				g.setContainerPosition("rightClickMenu", sf::Vector2f(sf::Mouse::getPosition(game->window)));
				g.toggleContainerShown("rightClickMenu");
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (e.mouseButton.button == sf::Mouse::Button::Left)
			{
				if (isDragging) {
					isDragging = false;
				}
				//check for release over an active button
				std::string action = g.getClickAction("mainMenu", sf::Mouse::getPosition(game->window));
				std::cout << "Click action: " << action << std::endl;
				if (action != "null")
				{
					if (action == "exit")
					{
						game->window.close();
					}
				}
			}
		default:
			break;
		}
	}
}

void GameStateMainMenu::handleInput()
{
	if (isDragging)
	{
		sf::Vector2f curMousePos = sf::Vector2f(sf::Mouse::getPosition(game->window));
		sf::Vector2f offset = curMousePos - lastDragPosition;
		lastDragPosition = curMousePos;
		g.moveContainer("mainMenu", offset);
	}
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
