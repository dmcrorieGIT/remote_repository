#include <iostream>
#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "player.hpp"
#include "object.hpp"


int gameRenderer(void)
{

  struct Player_Handler ph; ph.size=0;
  sf::RenderWindow window(sf::VideoMode(500,500), "SFML Game");
  
  Player p1(&window, 1, 100, 100);
  ph.players[ph.size] = &p1;
  ph.size++;

  Player p2(&window, 2, 250, 100);
  ph.players[ph.size] = &p2;
  ph.size++;
  
  Object platform[10];
  platform[0].setFile("Images/Platforms/Generic_Platform.png");
  platform[0].setWindow(&window);
  platform[0].obj.setScale(4,1);
  platform[0].obj.setPosition(100, 280);

  platform[1].setFile("Images/Platforms/Generic_Platform.png");
  platform[1].setWindow(&window);
  platform[1].obj.setScale(3,1);
  platform[1].obj.setPosition(50, 400);
  
  while (window.isOpen())
    {

      // check to see if players are 'grounded'
      for (int i = 0; i < ph.size; i++)
	{
	  // we assume player is falling until proven
	  // otherwise
	  ph.players[i]->is_falling=true;
	  
	  for (int j = 0; j < 2; j++)
	    {
	      if (ph.players[i]->footR.getGlobalBounds().intersects(platform[j].obj.getGlobalBounds()) && ( (int)(ph.players[i]->footR.getGlobalBounds().top + ph.players[i]->footR.getGlobalBounds().height) == (int)platform[j].obj.getGlobalBounds().top))
		ph.players[i]->is_falling=false;

	    }

	}
      
      for (int i = 0; i < ph.size; i++)
	{
	  ph.players[i]->gravity();
	  ph.players[i]->move();
	}
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();

	}

      //test
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
	  std::cout << "Test Information\n";
	}
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && p1.is_falling==false)
	p1.y_acc -= (p1.Spd / 3);
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	p1.mov = -1;

      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	p1.mov = 1;

      else{
	p1.x_acc = 0;
	p1.mov = 0;
      }
	
      
      window.clear();

      window.draw(platform[0].obj);
      window.draw(platform[1].obj);
      
      p2.draw();

      p1.draw();
      
      window.display();


    }


  return 0;
}
