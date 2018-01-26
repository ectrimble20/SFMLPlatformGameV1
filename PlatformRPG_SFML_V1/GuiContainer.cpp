#include "GuiContainer.h"
#include "ResourceHolder.h"
#include <iostream>


GuiContainer::GuiContainer(sf::Vector2f dimensions, int padding, bool horizontal, GuiStyle style, std::vector<std::pair<std::string, std::string>> entries)
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
	return m_dimensions;
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
	for (int i = 0; i < entities.size(); ++i)
	{
		if (i == entity)
		{
			entities[i].shape.setFillColor(m_style.bodyHighlightColor);
			entities[i].shape.setOutlineColor(m_style.borderHighlightColor);
			entities[i].textObject.setFillColor(m_style.textHighlightColor);
		}
		else
		{
			entities[i].shape.setFillColor(m_style.bodyColor);
			entities[i].shape.setOutlineColor(m_style.borderColor);
			entities[i].textObject.setFillColor(m_style.textColor);
		}
	}
}

//overload the parent function to update the shape/text positions
void GuiContainer::setPosition(sf::Vector2f position)
{
	sf::Transformable::setPosition(position);
	for (auto & entity : entities)
	{
		entity.shape.setPosition(position);
		entity.textObject.setPosition(position);
	}
}

void GuiContainer::move(sf::Vector2f& offset)
{
	sf::Transformable::move(offset);
	for (auto & entity : entities)
	{
		entity.shape.move(offset);
		entity.textObject.move(offset);
	}
}

/*
Text Alignment notes.

Okay, this is so I can remember what I need to calculate when aligning text bounds within their container bounds.

Left Align:
Simple, we only need to calculate for padding and adjust the X axis off of that
TxtX + padding

Center Align:
A little more complex but not terrible, we just need to take width of Text minus width of container, divide by two and adjust X axis to that:
(TxtW - ConW) / 2 = X
Note: If we're padded, it really shouldn't matter for Centered text

Right Align:
The most complex align in implementation, but still not really hard to figure out.
We just need to take the width of the text, subtract the width of the container, and subtract padding and adjust X axis to that.
(TxtW - ConW) - padding = X

*/
void GuiContainer::setEntityTextAlignment(GuiTextAlignment alignment)
{
	sf::Vector2f offset(0.0f, 0.0f);
	float shapeSize;
	float textSize;
	float moveOffset;

	for (auto & entity : entities)
	{
		//make sure we're aligned up with our parent container
		sf::Vector2f origin = getOrigin();
		origin -= offset;
		entity.shape.setOrigin(origin);
		entity.textObject.setOrigin(origin);
		//make sure our position is reset to the relation of the parent container as well
		entity.shape.setPosition(getPosition());
		entity.textObject.setPosition(getPosition());
		//if you don't do this, it moves the text around instead of absolute positioning
		switch (alignment)
		{
		case GuiTextAlignment::LEFT:
			//for our left align, we just need to adjust the X position of the text by the padding
			entity.textObject.move(sf::Vector2f((float)m_padding, 0.0f));
			break;
		case GuiTextAlignment::RIGHT:
			shapeSize = entity.shape.getSize().x;
			textSize = entity.textObject.getGlobalBounds().width;
			moveOffset = (shapeSize - textSize) - (float)m_padding;
			entity.textObject.move(sf::Vector2f(moveOffset, 0.0f));
			break;
		case GuiTextAlignment::CENTER:
			shapeSize = entity.shape.getSize().x;
			textSize = entity.textObject.getGlobalBounds().width;
			moveOffset = (shapeSize - textSize) * 0.5f;
			entity.textObject.move(sf::Vector2f(moveOffset, 0.0f));
			break;
		default:
			//do nothing if we somehow got an option that doesn't exist
			break;
		}
		//adjust our offset
		if (m_isHorizontal) {
			offset.x += m_dimensions.x;
		}
		else {
			offset.y += m_dimensions.y;
		}
	}
}

int GuiContainer::getEntity(sf::Vector2i mousePosition)
{
	if (entities.size() == 0) { return -1; } //have no entities
	if (!m_isVisible) { return -1; } //not currently visible, so not interactive
	for (int i = 0; i < entities.size(); ++i)
	{
		sf::Vector2f point = sf::Vector2f(mousePosition);
		point += entities[i].shape.getOrigin();
		point -= entities[i].shape.getPosition();
		if (point.x < 0 || point.x > entities[i].shape.getScale().x * m_dimensions.x) {
			continue;
		}
		if (point.y < 0 || point.y > entities[i].shape.getScale().y * m_dimensions.y) {
			continue;
		}
		return i;
	}
	return -1; //if all else fails
}

std::string GuiContainer::getAction(const int entity)
{
	//in the event we get a bad entity
	if (entity == -1) {
		return "null";
	}
	return entities[entity].text;
}
