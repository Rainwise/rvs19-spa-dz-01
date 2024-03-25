#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Wolf3D.h"
#include "Bird.h"

sf::Clock clk;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	// Cvijet cvijet(&window);
	Wolf3D wolf(&window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float deltaTime = clk.restart().asSeconds();
		wolf.update(deltaTime);

		window.clear();
		// cvijet.draw();
		wolf.draw();
		window.display();
	}

	return 0;
}