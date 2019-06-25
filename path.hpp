#ifndef PATH_H
#define PATH_H

#include "SFML\Graphics.hpp" 
#include "planet.hpp"
#include <cmath>
#include <array>

float distanceBetween(Planet planet1, Planet planet2);
float getRotation(Planet planet1, Planet planet2);

struct Path
{
	Path() = default;
	Path(const Planet &planet1, const Planet &planet2, float thickness) : planets({ &planet1, &planet2 })
	{
		float length = distanceBetween(planet1, planet2);
		float rotation = getRotation(planet1, planet2);

		path = sf::RectangleShape(sf::Vector2f(length, thickness));
		path.setOrigin(0.f, thickness / 2);
		path.setRotation(rotation);
		path.setPosition(planet1.getXPos(), planet1.getYPos());
	}
	void drawPath(sf::RenderWindow &window)
	{
		window.draw(path);
	}
	const std::array<const Planet*, 2> returnPlanets() const
	{
		return planets;
	}


private:
	sf::RectangleShape path;
	const std::array<const Planet*, 2> planets;
};

#endif