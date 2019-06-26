#ifndef PLANET_H
#define PLANET_H

#include <SFML/Graphics.hpp>


struct Planet
{
	Planet() = default;
	Planet(int ixPos, int iyPos, sf::Color color, float radius) : xPos(ixPos), yPos(iyPos)
	{
		circle = sf::CircleShape(radius);
		circle.setFillColor(color);
		circle.setOrigin(radius, radius);	//Radius set at center of circle
		circle.setPosition(ixPos, iyPos);
	}

	bool operator==(const Planet& rhs) const
	{
		return this->xPos == rhs.xPos && this->yPos == rhs.yPos && this->circle.getRadius() == rhs.circle.getRadius() && this->circle.getFillColor() == this->circle.getFillColor();
	}

	inline sf::CircleShape returnShape() const
	{
		return circle;
	}
	void setColor(int red, int blue, int green)
	{
		circle.setFillColor(sf::Color(red, green, blue));
	}
	sf::Color getColor() const
	{
		return circle.getFillColor();
	}
	void setPosition(float x, float y)
	{
		circle.setPosition(x, y);
		xPos = static_cast<int>(x);
		yPos = static_cast<int>(y);
	}
	int getXPos() const
	{
		return xPos;
	}
	int getYPos() const
	{
		return yPos;
	}
	int getRadius() const
	{
		return static_cast<int>(circle.getRadius());
	}
	

private:
	int xPos;
	int yPos;
	sf::CircleShape circle;
};

#endif