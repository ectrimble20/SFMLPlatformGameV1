#include "Gui.h"
#include "ResourceHolder.h"


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
	guiSystem.at("rightClickMenu").show();//I might just be retarded, yep, I'm retarded

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

