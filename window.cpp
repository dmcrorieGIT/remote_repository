#include "window.hpp"


int gameRenderer(void)
{

  // Create the 'Player Handler', which tracks all of the player
  // objects currently on the screen
  struct Manager man; man.play_siz=0; man.plat_siz=0;
  // Creates the game window
  sf::RenderWindow window(sf::VideoMode(500,500), "SFML Game");

  // Creates player 1 and adds it to the player manager
  Player p1(&window, 1, 100, 100);
  man.players[man.play_siz] = &p1;
  man.play_siz++;

  // also creates player 2 and adds it to player manager
  Player p2(&window, 2, 250, 100);
  man.players[man.play_siz] = &p2;
  man.play_siz++;

  // initialize the first platform
  Object platform1;
  platform1.setFile("Images/Platforms/Generic_Platform.png");
  platform1.setWindow(&window);
  platform1.obj.setScale(4,1);
  platform1.obj.setPosition(100, 280);
  man.platforms[man.plat_siz] = &platform1;
  man.plat_siz++;

  // initialize the second platform
  Object platform2;
  platform2.setFile("Images/Platforms/Generic_Platform.png");
  platform2.setWindow(&window);
  platform2.obj.setScale(3,1);
  platform2.obj.setPosition(50, 400);
  man.platforms[man.plat_siz] = &platform2;
  man.plat_siz++;
  
  while (window.isOpen())
    {

      // check to see which players are 'grounded'
      for (int i = 0; i < man.play_siz; i++)
	{
	  // we assume player is falling until proven
	  // otherwise
	  man.players[i]->is_falling=true;
	  
	  for (int j = 0; j < man.plat_siz; j++)
	    {
	      // if the player;s foot is intersecting a particular platform AND only the bottom
	      // of the player's foot and the top of the platform are touching
	      if (man.players[i]->footR.getGlobalBounds().intersects(man.platforms[j]->obj.getGlobalBounds()) && ( (int)(man.players[i]->footR.getGlobalBounds().top + man.players[i]->footR.getGlobalBounds().height) == (int)man.platforms[j]->obj.getGlobalBounds().top))
		man.players[i]->is_falling=false;

	    }

	}
      
      for (int i = 0; i < man.play_siz; i++)
	{
	  man.players[i]->gravity();
	  man.players[i]->move();
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
	man.players[0]->y_acc -= (p1.Spd / 3);
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	man.players[0]->mov = -1;

      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	man.players[0]->mov = 1;

      else{
	man.players[0]->x_acc = 0;
	man.players[0]->mov = 0;
      }
	
      
      window.clear();

      for (int i = 0; i < man.plat_siz; i++)
	window.draw(man.platforms[i]->obj);

      for (int i = 0; i < man.play_siz; i++)
	man.players[i]->draw();
      
      window.display();


    }


  return 0;
}
