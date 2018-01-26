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
	GuiStyle GetStyle(std::string key);
private:
	GuiStyle m_empty; //empty "default" struct
	std::map<std::string, GuiStyle> m_styles;
	static GuiStyleLib s_instance;
	static bool s_initialized;
};

