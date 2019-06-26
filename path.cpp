#include "path.hpp"

const double pi() { return std::atan(1) * 4; };

float distanceBetween(Planet planet1, Planet planet2)
{
	return std::sqrt(pow(planet1.getXPos() - planet2.getXPos(), 2) + pow(planet1.getYPos() - planet2.getYPos(), 2));
}
float getRotation(Planet planet1, Planet planet2)
{
	float xDist = planet2.getXPos() - planet1.getXPos();
	float yDist = planet2.getYPos() - planet1.getYPos();
	/*
	if (planet1.getXPos() < planet2.getXPos() && planet1.getYPos() < planet2.getYPos())	//For these, imagine planet1 is origin of unit circle, and planet2 is on edge. in this case, planet2 is in quad1
	{
		return -static_cast<float>(atan(yDist / xDist) * (180 / pi())) + 360.f;
	}
	else if (planet1.getXPos() < planet2.getXPos() && planet1.getYPos() > planet2.getYPos())	//planet2 is in quadrant 4
	{
		return -static_cast<float>(atan(yDist / xDist) * (180 / pi()));
	}
	else if (planet1.getXPos() > planet2.getXPos() && planet1.getYPos() > planet2.getYPos())	//planet2 is in quadrant 3
	{
		return -static_cast<float>(atan(yDist / xDist) * (180 / pi()) + 180.f);
	}
	else if (planet1.getXPos() > planet2.getXPos() && planet1.getYPos() < planet2.getYPos())	//planet2 is in quadrant 2
	{
		return -static_cast<float>(atan(yDist / xDist) * (180 / pi()) + 180.f);
	}
	I made a silly mistake. In our coordinate system, y=0 is the top, and higher y values are lower on the screen, so i have to change this. This above is for a real coordinate plane, but not ours.
	*/
	if (planet1.getYPos() == planet2.getYPos())
	{
		if (planet1.getXPos() < planet2.getXPos())
			return 0.f;
		else
			return 180.f;
	}
	else if (planet1.getXPos() == planet2.getXPos())
	{
		if (planet1.getYPos() < planet2.getYPos())
			return 90.f;
		else
			return 270.f;
	}
	else if (planet1.getXPos() < planet2.getXPos() && planet1.getYPos() < planet2.getYPos())	//planet2 is in quadrant 2
	{
		return static_cast<float>(atan(yDist / xDist) * (180 / pi()));	//Made a change
	}
	else if (planet1.getXPos() < planet2.getXPos() && planet1.getYPos() > planet2.getYPos())	//planet2 is in quadrant 1
	{
		return static_cast<float>(atan(yDist / xDist) * (180 / pi())) + 360.f;
	}
	else if (planet1.getXPos() > planet2.getXPos() && planet1.getYPos() > planet2.getYPos())	//planet2 is in quadrant 2
	{
		return static_cast<float>(atan(yDist / xDist) * (180 / pi()) + 180.f);
	}
	else if (planet1.getXPos() > planet2.getXPos() && planet1.getYPos() < planet2.getYPos())	//planet2 is in quadrant 3
	{
		return static_cast<float>(atan(yDist / xDist) * (180 / pi()) + 180.f);
	}

	
		
}
bool Path::linksPlanet(const Planet &planet) const
{
	if (planet == *planets[0] || planet == *planets[1])
		return true;
	else
		return false;
}
const Planet *Path::returnOtherLinkedPlanet(const Planet &planet) const	//MUST CHECK THAT THEY ARE ALREADY LINKED
{
	if (planet == *planets[0])
		return planets[1];
	else
		return planets[0];
}