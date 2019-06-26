#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "planet.hpp"
#include "path.hpp"
#include <SFML/Window.hpp>

bool isWithinXNum(int num1, int num2, int xVal);
std::vector<Planet> generatePlanets(int num, int radius, int gap);
bool planetsTooClose(Planet planet1, Planet planet2, int gap);

struct System
{
	bool planetsTooClose(int gap);
	void generatePaths(int thickness);
	//std::vector<Planet> connectedPlanets(Planet planet);

	System(int num, int radius, int gap) 
	{
		planets = generatePlanets(num, radius, gap);
		generatePaths(2);
	} 
	void drawPaths(sf::RenderWindow &window)
	{
		for (std::vector<Path>::iterator iter = paths.begin(); iter != paths.end(); ++iter)
			iter->drawPath(window);
	}
	void drawPlanets(sf::RenderWindow &window)
	{
		for (std::vector<Planet>::iterator iter = planets.begin(); iter != planets.end(); ++iter)
			window.draw(iter->returnShape());
	}
	void drawPlanetIndexNo(sf::RenderWindow &window)
	{
		sf::Font font;
		font.loadFromFile("design.scifi.ALIEN5.ttf");

		sf::Text index;
		index.setFont(font);
		index.setCharacterSize(20);
		index.setFillColor(sf::Color::Red);
		index.setStyle(sf::Text::Bold);

		for (int i = 0; i != planets.size(); ++i)
		{
			index.setString(std::to_string(i));
			index.setPosition(planets[i].getXPos() - planets[i].getRadius()/2, planets[i].getYPos() - planets[i].getRadius());
			window.draw(index);
		}
	}
	bool isAlreadyConnected(const Planet &planet1, const Planet &planet2) const;
	

	

private:
	std::vector<Planet> planets;
	std::vector<Path> paths;
};

#endif
