#pragma once
#include "GuiStruct.h"
#include "SFML\Graphics.hpp"
#include <vector>

//this is going to replace the Gui class, the Gui class will be the actual interaction class
//this will be the data class
enum class GuiTextAlignment {
	LEFT, RIGHT, CENTER
};


class GuiContainer : public sf::Transformable, public sf::Drawable
{
public:
	GuiContainer() = delete; //no default constructor
	GuiContainer(sf::Vector2f dimensions, int padding, bool horizontal, GUIStyle style, std::vector<std::pair<std::string, std::string>> entries);
	~GuiContainer();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//accessors
	sf::Vector2f getDimensions();
	void setDimensions(sf::Vector2f dimensions);
	int getEntity(const sf::Vector2f mousePosition);
	void setEntityText(int entity, std::string text);
	void show();
	void hide();
	void highlight(const int entity);
	virtual void setPosition(sf::Vector2f position);
	void move(sf::Vector2f& adjustment);
	void centerEntityText();
	void setEntityTextAlignment(GuiTextAlignment alignment);
	bool isVisible() const { return m_isVisible; };
	int getEntity(sf::Vector2i mousePosition);
	std::string getAction(const int entity);
private:
	GUIStyle m_style;
	sf::Vector2f m_dimensions;
	bool m_isHorizontal = false; //defaults to a vertical display (stacked)
	bool m_isVisible = false; //hidden by default
	int m_padding = 0; //padding of the element text
	std::vector<GuiEntity> entities;

};

