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
	void setContainerPosition(std::string containerName, sf::Vector2f position);
	void moveContainer(std::string containerName, sf::Vector2f offset);
	void setContainerTextCenter(std::string containerName);
	sf::Vector2f getContainerSize(std::string containerName);
	void setContainerShow(std::string containerName);
	void setContainerHide(std::string containerName);
	void toggleContainerShown(std::string containerName);
	void checkForHover(std::string containerName, sf::Vector2i mousePosition);
	std::string getClickAction(std::string containerName, sf::Vector2i mouseClickPosition);
};

