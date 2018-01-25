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

	guiSystem.emplace("rightClickMenu", GuiContainer(sf::Vector2f(196, 16), 2, true, buttonStyle,
		{
			std::make_pair("Flatten",         "grass"),
			std::make_pair("Forest",        "forest"),
			std::make_pair("Residential Zone",   "residential"),
			std::make_pair("Commercial Zone",    "commercial"),
			std::make_pair("Industrial Zone",    "industrial"),
			std::make_pair("Road",          "road")
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
	guiSystem.at("mainMenu").centerEntityText();
	//guiSystem.at("rightClickMenu").show();//I might just be retarded, yep, I'm retarded

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
		guiSystem.at(containerName).centerEntityText();
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

std::string Gui::getClickAction(std::string containerName, sf::Vector2i mouseClickPosition)
{
	return std::string();
}

