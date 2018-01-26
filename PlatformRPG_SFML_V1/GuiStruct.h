#pragma once
#include "SFML\Graphics.hpp"
#include <string>


//Data structures related to the GUI

struct GuiStyle
{
	sf::Color bodyColor;
	sf::Color bodyHighlightColor;
	sf::Color borderColor;
	sf::Color borderHighlightColor;
	sf::Color textColor;
	sf::Color textHighlightColor;
	std::string fontKey;
	float borderSize = 1.0f; //set a default here
};

struct GuiEntity
{
	sf::RectangleShape shape;
	std::string text;
	sf::Text textObject;
};