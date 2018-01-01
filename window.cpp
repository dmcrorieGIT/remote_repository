#include <iostream>
#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "player.hpp"


int gameRenderer(void)
{

  sf::RenderWindow window(sf::VideoMode(400,400), "SFML Game");
  Player p1(&window, 1, 100, 300);
  Player p2(&window, 2, 250, 300);

  while (window.isOpen())
    {

      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();

	}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	p1.move(-0.3);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	p1.move(0.3);

      if (p1.body.getGlobalBounds().intersects(p2.body.getGlobalBounds()))
	std::cout << "Collision\n";

      
      window.clear();
      
      p2.draw();

      p1.draw();
      
      window.display();


    }


  return 0;
}
