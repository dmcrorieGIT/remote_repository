#include <iostream>
#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "player.hpp"


int gameRenderer(void)
{

  sf::RenderWindow window(sf::VideoMode(400,400), "SFML Game");
  Player p1(&window, 1, 100, 100);


  while (window.isOpen())
    {

      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();

	}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	p1.move(-1);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	p1.move(1);

      
      window.clear();
      
      p1.draw();
      
      window.display();


    }


  return 0;
}
