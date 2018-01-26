#include "Gui.h"
#include "ResourceHolder.h"
#include <iostream> //ugh debug again


Gui::Gui()
{
	GUIStyle buttonStyle;
	buttonStyle.fontKey = "lucon";
	buttonStyle.borderSize = 1.0f;
	buttonStyle.bodyColor = sf::Color(0xc6, 0xc6, 0xc6);
	buttonStyle.borderColor = sf::Color(0x94, 0x94, 0x94);
	buttonStyle.textColor = sf::Color(0x00, 0x00, 0x00);
	buttonStyle.bodyHighlightColor = sf::Color(0x61, 0x61, 0x61);
	buttonStyle.borderHighlightColor = sf::Color(0x94, 0x94, 0x94);
	buttonStyle.textHighlightColor = sf::Color(0x00, 0x00, 0x00);

	//GuiStyle(sf::Font* font, float borderSize,
	//sf::Color bodyCol, sf::Color borderCol, sf::Color textCol,
		//sf::Color bodyHighlightCol, sf::Color borderHighlightCol, sf::Color textHighlightCol)

	guiSystem.emplace("rightClickMenu", GuiContainer(sf::Vector2f(128, 16), 2, false, buttonStyle,
		{
			std::make_pair("Right Click 1",         "grass"),
			std::make_pair("Right Click 2",        "forest"),
			std::make_pair("Right Click 3",   "residential"),
			std::make_pair("Right Click 4",    "commercial"),
			std::make_pair("Right Click 5",    "industrial"),
			std::make_pair("Right Click 6",          "road")
		})
	);
	guiSystem.emplace("mainMenu", GuiContainer(sf::Vector2f(384, 48), 8, false, buttonStyle,
		{
			std::make_pair("Start New Game", "new_game"),
			std::make_pair("Load Game", "load_game"),
			std::make_pair("Options", "options"),
			std::make_pair("Credits", "credits"),
			std::make_pair("Exit Game", "exit")
		}));
	guiSystem.at("mainMenu").show();
}


Gui::~Gui()
{
}

void Gui::draw(sf::RenderWindow& window)
{
	for (auto e : guiSystem)
	{
		window.draw(e.second);
	}
}

void Gui::setContainerPosition(std::string containerName, sf::Vector2f position)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		guiSystem.at(containerName).setPosition(position);
	}
}

void Gui::moveContainer(std::string containerName, sf::Vector2f offset)
{
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		guiSystem.at(containerName).move(offset);
	}
}

void Gui::setContainerTextCenter(std::string containerName)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		guiSystem.at(containerName).setEntityTextAlignment(GuiTextAlignment::CENTER);
	}
}

void Gui::setContainerTextRight(std::string containerName)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		guiSystem.at(containerName).setEntityTextAlignment(GuiTextAlignment::RIGHT);
	}
}

void Gui::setContainerTextLeft(std::string containerName)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		guiSystem.at(containerName).setEntityTextAlignment(GuiTextAlignment::LEFT);
	}
}

sf::Vector2f Gui::getContainerSize(std::string containerName)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		return guiSystem.at(containerName).getDimensions();
	}
	else
	{
		return sf::Vector2f(0.0f, 0.0f);
	}
}

void Gui::setContainerShow(std::string containerName)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		guiSystem.at(containerName).show();
	}
}

void Gui::setContainerHide(std::string containerName)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		guiSystem.at(containerName).hide();
	}
}

void Gui::toggleContainerShown(std::string containerName)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		if (guiSystem.at(containerName).isVisible()) {
			guiSystem.at(containerName).hide();
		}
		else
		{
			guiSystem.at(containerName).show();
		}
	}
}

void Gui::checkForHover(std::string containerName, sf::Vector2i mousePosition)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		guiSystem.at(containerName).highlight(guiSystem.at(containerName).getEntity(mousePosition));		
	}
}

bool Gui::isMouseOver(std::string containerName, sf::Vector2i mousePosition)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		//note: make sure it's >= 0, -1 is the "not found" indicator
		if (guiSystem.at(containerName).getEntity(mousePosition) >= 0)
		{
			return true;
		}
	}
	return false;
}

bool Gui::isContainerVisible(std::string containerName)
{
	//sanity check
	if (guiSystem.find(containerName) != guiSystem.end())
	{
		return guiSystem.at(containerName).isVisible();
	}
	return false;
}

std::string Gui::getClickAction(std::string containerName, sf::Vector2i mouseClickPosition)
{
	return std::string();
}

