#pragma once
#include "SFML\Graphics.hpp"

//Static color definitions for consistancy

class Colors
{
public:
	Colors() = delete;
	//These are pre-defined by the SFML lib, so these are literally just short-cuts to the SFML definitions
	static sf::Color black;
	static sf::Color white;
	static sf::Color red;
	static sf::Color green;
	static sf::Color blue;
	static sf::Color yellow;
	static sf::Color cyan;
	static sf::Color transparent;
	//These are custom (lol not really custom) colors not defined by name by SFML
	static sf::Color Silver;
	static sf::Color Gray;
	static sf::Color Maroon;
	static sf::Color Navy;
	static sf::Color Gold;
	static sf::Color DarkGreen;
	static sf::Color ForestGreen;
	static sf::Color Teal;
	static sf::Color Aqua;
	static sf::Color Slate;
	static sf::Color Cobalt;
	static sf::Color LightBlue;
	static sf::Color MidnightBlue;
	static sf::Color RoyalBlue;
	static sf::Color BlueViolet;
	static sf::Color Indigo;
	static sf::Color SlateBlue;
	static sf::Color Purple;
	static sf::Color Brown;
	static sf::Color Tan;

};

