#include "GuiStyleLib.h"
#include "Colors.h"

GuiStyleLib GuiStyleLib::s_instance;
bool GuiStyleLib::s_initialized = false;

GuiStyleLib::GuiStyleLib()
{
	//set default in case something fails
	m_empty.fontKey = "lucon";
	m_empty.borderSize = 0.0f;
	m_empty.bodyColor = Colors::Gray;
	m_empty.borderColor = Colors::white;
	m_empty.textColor = Colors::white;
	m_empty.bodyHighlightColor = Colors::Gray;
	m_empty.borderHighlightColor = Colors::white;
	m_empty.textHighlightColor = Colors::white;

	//one day I'd like to load this from a configuration type file
	//but until that day, setup any styles we want to use
	GuiStyle buttonStyle;
	buttonStyle.fontKey = "lucon";
	buttonStyle.borderSize = 1.0f;
	buttonStyle.bodyColor = Colors::Cobalt;
	buttonStyle.borderColor = Colors::Gold;
	buttonStyle.textColor = Colors::white;
	buttonStyle.bodyHighlightColor = Colors::Navy;
	buttonStyle.borderHighlightColor = Colors::Gold;
	buttonStyle.textHighlightColor = Colors::white;
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

GuiStyle GuiStyleLib::GetStyle(std::string key)
{
	if (m_styles.find(key) != m_styles.end())
	{
		return m_styles.at(key);
	}
	return m_empty;
}
