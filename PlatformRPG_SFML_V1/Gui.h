#pragma once
#include <map>
#include <string>
#include "GuiContainer.h" //gives us access to all the GUI Components
#include "SFML\Graphics.hpp"

/*
The Gui object is actually a list of GuiEntites that have a GuiStyle applied to them.

They can be presented horizontally or vertically and will scale to the largest text entity.
*/

class Gui
{
public:
	Gui();
	~Gui();
	std::map<std::string, GuiContainer> guiSystem; //just testing this out atm
	void draw(sf::RenderWindow& window);
};

