#pragma once
#include <string>
#include <map>
#include "GuiStruct.h"

class GuiStyleLib
{
public:
	GuiStyleLib();
	~GuiStyleLib();
	static GuiStyleLib * Instance();
private:
	std::map<std::string, GuiStyle> m_styles;
	static GuiStyleLib s_instance;
	static bool s_initialized;
};

