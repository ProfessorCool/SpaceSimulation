#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "planet.hpp"
#include <SFML/Window.hpp>

bool isWithinXNum(int num1, int num2, int xVal);
std::vector<Planet> generatePlanets(int num, int radius, int gap);
bool planetsTooClose(Planet planet1, Planet planet2, int gap);

struct System
{
	bool planetsTooClose(int gap);
	

	System(int num, int radius, int gap) 
	{
		planets = generatePlanets(num, radius, gap);
	} 

	void drawPlanets(sf::RenderWindow &window)
	{
		for (std::vector<Planet>::iterator iter = planets.begin(); iter != planets.end(); ++iter)
			window.draw(iter->returnShape());
	}

	

private:
	std::vector<Planet> planets;
};

#endif
