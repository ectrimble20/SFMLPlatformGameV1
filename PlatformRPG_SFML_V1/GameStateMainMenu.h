#pragma once
#include <string>
#include "SFML\Graphics.hpp"
#include "Game.h"
#include "Gui.h"

class GameStateMainMenu : public GameState
{
public:
	GameStateMainMenu() = delete;
	GameStateMainMenu(Game * game);
	~GameStateMainMenu();
	virtual void draw(const float deltaTime);
	virtual void update(const float deltaTime);
	virtual void handleInput();
private:
	sf::Text m_menu_text;
	sf::Sprite m_menu_background;
	Gui g;
	void centerMenu();
};

