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

	inline sf::CircleShape returnShape()
	{
		return circle;
	}
	void setColor(int red, int blue, int green)
	{
		circle.setFillColor(sf::Color(red, green, blue));
	}
	sf::Color getColor()
	{
		return circle.getFillColor();
	}
	void setPosition(float x, float y)
	{
		circle.setPosition(x, y);
		xPos = static_cast<int>(x);
		yPos = static_cast<int>(y);
	}
	int getXPos()
	{
		return xPos;
	}
	int getYPos()
	{
		return yPos;
	}
	int getRadius()
	{
		return static_cast<int>(circle.getRadius());
	}
	

private:
	int xPos;
	int yPos;
	sf::CircleShape circle;
};

#endif