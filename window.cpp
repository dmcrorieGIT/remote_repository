#include <iostream>
#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "player.hpp"

int gameRenderer(void)
{
  sf::RenderWindow window(sf::VideoMode(200,200), "SFML Game");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
    {

      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();

	}

      
      window.clear();
      window.draw(shape);
      window.display();


    }


  return 0;
}