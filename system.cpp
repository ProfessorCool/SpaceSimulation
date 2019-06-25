#include "system.hpp"
#include <random>
#include <iostream>
#include <array>

bool isWithinXNum(int num1, int num2, int xVal)
{
	if (num1 - num2 <= xVal && num2 - num1 >= -xVal)
		return true;
	else
		return false;

}

bool System::planetsTooClose(int gap)
{
	for (auto planet1 = 0; planet1 != planets.size() - 1; ++planet1)	//Doesn't do radius(xVal) calculations correct, look at other overloaded function
	{
		for (auto planet2 = planet1+1; planet2 != planets.size(); ++planet2)
		{
			if (isWithinXNum(planets[planet1].getXPos(), planets[planet2].getXPos(), planets[planet1].getRadius() + gap) && isWithinXNum(planets[planet1].getYPos(), planets[planet2].getYPos(), planets[planet1].getRadius() + gap))
				return true;
		}
	}
	return false;
}

bool planetsTooClose(Planet planet1, Planet planet2, int gap)
{
	if (isWithinXNum(planet1.getXPos(), planet2.getXPos(), planet1.getRadius() + planet2.getRadius() + gap) && isWithinXNum(planet1.getYPos(), planet2.getYPos(), planet1.getRadius() + planet2.getRadius() + gap))
		return true;
	else
		return false;
}

std::vector<Planet> generatePlanets(int num, int radius, int gap)
{
	std::vector<Planet> planets;
	int numGen = 0;
	auto gen = std::mt19937{ std::random_device{}() };
	auto dist1 = std::uniform_int_distribution<int>{ 0, 50 };
	auto dist2 = std::uniform_int_distribution<int>{ 0, 25 };
	auto dist3 = std::binomial_distribution<int>{ 50, 0.5 };
	auto dist4 = std::binomial_distribution<int>{ 25, 0.5 };
	for (int i = 0; i != num; ++i)
	{
		Planet tempPlanet;
		bool keepIterating = true;
		
		while (keepIterating)
		{
			bool tooClose = false;
			//int xPos = dist1(gen);
			//int yPos = dist2(gen);
			int xPos = (dist3(gen)+dist1(gen))*14 + 100;	//half random, half binomial to center the majority of the planets into the center
			int yPos = (dist4(gen)+dist2(gen))*14 + 100;	//As above
			tempPlanet = Planet(xPos, yPos, sf::Color(200, 200, 200), radius);
			for (int i2 = 0; i2 != i; ++i2)
			{
				if (planetsTooClose(planets[i2], tempPlanet, gap))
				{
					tooClose = true;
					break;
				}
			}
			if (tooClose == false)
				keepIterating = false;
			++numGen;
		}
		planets.push_back(tempPlanet);
	}
	std::cout << numGen;
	return planets;
}
bool System::isAlreadyConnected(const Planet &planet1, const Planet &planet2) const
{
	for (const auto &i : paths)
	{
		if (*i.returnPlanets()[0] == planet1 && *i.returnPlanets()[1] == planet2 || *i.returnPlanets()[1] == planet1 && *i.returnPlanets()[0] == planet2)
			return true;
	}
	return false;
}
void System::generatePaths(int thickness)
{
	//Step 1: connect the planets closest to eachother
	for (int i = 0; i != planets.size(); ++i)
	{
		float smallestDist = 0.f;	//temporay placeholder
		std::array<Planet*, 2> planetsOfSmallest;

		for (int i2 = 0; i2 != planets.size(); ++i2)	
		{
			if (distanceBetween(planets[i], planets[i2]) < smallestDist && i != i2 || static_cast<int>(smallestDist) == 0)	//Check if a value was initialized
			{
				smallestDist = distanceBetween(planets[i], planets[i2]);
				planetsOfSmallest = { &planets[i], &planets[i2] };
			}
		}
		if (!isAlreadyConnected(*planetsOfSmallest[0], *planetsOfSmallest[1]))
		{
			paths.push_back(Path(*planetsOfSmallest[0], *planetsOfSmallest[1], thickness));
		}
	}
	/*for (int i = 0; i != planets.size() - 1; ++i)
	{
		float smallestDist = distanceBetween(planets[i], planets[i + 1]);	//temporay placeholder
		std::array<Planet*, 2> planetsOfSmallest = { &planets[i], &planets[i + 1] };
		for (int i2 = 2; i2 != planets.size(); ++i2)	//Starts at 2 because placeholder took the i=1
		{
			if (distanceBetween(planets[i], planets[i2]) < smallestDist)
			{
				smallestDist = distanceBetween(planets[i], planets[i2]);
				planetsOfSmallest = { &planets[i], &planets[i2] };
			}
		}
		if (!isAlreadyConnected(*planetsOfSmallest[0], *planetsOfSmallest[1]))
		{
			paths.push_back(Path(*planetsOfSmallest[0], *planetsOfSmallest[1], thickness));
		}
	}*/

}