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
	

	System(int num, int radius, int gap) 
	{
		planets = generatePlanets(num, radius, gap);
		for (int i = 0; i != num - 1; ++i)	//TEMP PLEASE REMOVE
		{
			for (int i2 = i + 1; i2 != num; ++i2)
				paths.push_back(Path(planets[i], planets[i2], 1));
		}
	} 

	void drawPlanets(sf::RenderWindow &window)
	{
		for (std::vector<Path>::iterator iter = paths.begin(); iter != paths.end(); ++iter)
			iter->drawPath(window);	//TEMP PLEASE REMOVE
		for (std::vector<Planet>::iterator iter = planets.begin(); iter != planets.end(); ++iter)
			window.draw(iter->returnShape());
	}

	

private:
	std::vector<Planet> planets;
	std::vector<Path> paths;	//TEMP PLEASE REMOVE
};

#endif
