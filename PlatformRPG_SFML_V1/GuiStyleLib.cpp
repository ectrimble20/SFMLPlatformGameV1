#include "GuiStyleLib.h"

GuiStyleLib GuiStyleLib::s_instance;
bool GuiStyleLib::s_initialized = false;

GuiStyleLib::GuiStyleLib()
{
	//one day I'd like to load this from a configuration type file
	//but until that day, setup any styles we want to use
	GuiStyle buttonStyle;
	buttonStyle.fontKey = "lucon";
	buttonStyle.borderSize = 1.0f;
	buttonStyle.bodyColor = sf::Color(0xc6, 0xc6, 0xc6);
	buttonStyle.borderColor = sf::Color(0x94, 0x94, 0x94);
	buttonStyle.textColor = sf::Color(0x00, 0x00, 0x00);
	buttonStyle.bodyHighlightColor = sf::Color(0x61, 0x61, 0x61);
	buttonStyle.borderHighlightColor = sf::Color(0x94, 0x94, 0x94);
	buttonStyle.textHighlightColor = sf::Color(0x00, 0x00, 0x00);
	m_styles["menuButton"] = buttonStyle;
}


GuiStyleLib::~GuiStyleLib()
{
}

//Static instance accessor
GuiStyleLib * GuiStyleLib::Instance()
{
	if (!GuiStyleLib::s_initialized)
	{
		GuiStyleLib::s_instance = GuiStyleLib();
		GuiStyleLib::s_initialized = true;
	}
	return &GuiStyleLib::s_instance;
}
