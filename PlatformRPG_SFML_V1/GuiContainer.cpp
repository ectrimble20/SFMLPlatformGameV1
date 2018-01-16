#include "GuiContainer.h"
#include "ResourceHolder.h"



GuiContainer::GuiContainer(sf::Vector2f dimensions, int padding, bool horizontal, GUIStyle style, std::vector<std::pair<std::string, std::string>> entries)
{
	m_style = style;
	m_dimensions = dimensions;
	m_padding = padding;
	m_isHorizontal = horizontal;
	sf::RectangleShape shape;
	shape.setSize(m_dimensions);
	shape.setFillColor(style.bodyColor);
	shape.setOutlineThickness(-style.borderSize);
	shape.setOutlineColor(style.borderColor);
	for (auto entry : entries)
	{
		sf::Text text;
		text.setString(entry.first);
		text.setFont(ResourceHolder::getFont(style.fontKey));
		text.setFillColor(style.textColor);
		text.setCharacterSize(m_dimensions.y - style.borderSize - m_padding);
		GuiEntity e;
		e.shape = shape;
		e.text = entry.second;
		e.textObject = text;
		entities.push_back(e);
	}
}

GuiContainer::~GuiContainer()
{
}

void GuiContainer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//we only draw if we are visible
	if (m_isVisible) {
		for (auto entity : entities)
		{
			target.draw(entity.shape);
			//entity.textObject.setFont(ResourceHolder::getFont(m_style.fontKey)); //no idea if this is worth anything
			//fec, ugh, the reference to the font doesn't stick with the struct for w/e reason... maybe I did it wrong in the container
			target.draw(entity.textObject);
		}
	}
}

sf::Vector2f GuiContainer::getDimensions()
{
	return sf::Vector2f();
}

void GuiContainer::setDimensions(sf::Vector2f dimensions)
{
	m_dimensions = dimensions;
}

int GuiContainer::getEntity(const sf::Vector2f mousePosition)
{
	if (entities.size() == 0) { return -1; }
	if (!m_isVisible) { return -1; }
	for (int i = 0; i < entities.size(); ++i)
	{
		sf::Vector2f point = mousePosition;
		//add the origin of the entities shape to the point
		point += entities[i].shape.getOrigin();
		//then subtract the position from the shape
		point -= entities[i].shape.getPosition();
		//this will give us two points that will tell us (if the values are within point.x/y) if we're within bounds
		if (point.x < 0 || point.x > entities[i].shape.getScale().x * m_dimensions.x)
		{
			continue;
		}
		if (point.y < 0 || point.y > entities[i].shape.getScale().y * m_dimensions.y)
		{
			continue;
		}
		//if we're still going at this point, we've found something that the mousePosition is over
		return i;
	}
	return -1;
}

void GuiContainer::setEntityText(int entity, std::string text)
{
	if (entity >= entities.size() || entity < 0) return; //outside of our bounds, do nothing
	//update the entities text string
	entities[entity].textObject.setString(text);
}

void GuiContainer::show()
{
	m_isVisible = true;
	sf::Vector2f offset(0.0f, 0.0f);
	for (auto & entity : entities)
	{
		sf::Vector2f origin = getOrigin(); //since this extends transformable :)
		origin -= offset;
		entity.shape.setOrigin(origin);
		entity.textObject.setOrigin(origin);
		//update the position of the entity
		entity.shape.setPosition(getPosition());
		entity.textObject.setPosition(getPosition());
		//handle moving the offset forward on the X or Y axis depending on the horizontal setting
		if (m_isHorizontal) {
			offset.x += m_dimensions.x;
		}
		else {
			offset.y += m_dimensions.y;
		}
	}
}

void GuiContainer::hide()
{
	m_isVisible = false;
}

void GuiContainer::highlight(const int entity)
{
}
