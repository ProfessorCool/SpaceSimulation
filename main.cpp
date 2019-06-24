#include <SFML/Graphics.hpp>
#include "planet.hpp"
#include "system.hpp"
#include <iostream>
#include "logger.hpp"
int main()
{
	Logger logger;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
	System system(32, 10, 5);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				break;
			}
		}

		window.clear();
		system.drawPlanets(window);
		window.display();
	}

	return 0;
}