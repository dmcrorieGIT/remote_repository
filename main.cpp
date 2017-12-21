#include <iostream>
#include <SFML/Graphics.hpp>

// Initial build of the game code file that we will be working
// off of
int main(void)
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
