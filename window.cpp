/*********************************************************************
 *                                                                   *
 *                         Window.cpp                                *
 *                                                                   *
 * -Manages everything being drawn to the game window, and calls     *
 *  upon other programs to deal with the logic between the sprites   *
 *                                                                   *
 *********************************************************************/

#include "window.hpp"

//####################################################################
//#  Game Renderer [gameRenderer]                                    #
//#  -> deals with what happens every frame                          #
//####################################################################

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

      // deal with things happening in the scene, like gravity
      manageGameScene(&man);

      // deal with events (like the window getting closed)
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();

	}

      // deal with each player's inputs
      for (int i = 0; i < man.play_siz; i++)
	managePlayerControls(&man, i);
      
      window.clear();

      // draw the platforms to the screen
      for (int i = 0; i < man.plat_siz; i++)
	window.draw(man.platforms[i]->obj);

      // draw the players to the screen
      for (int i = 0; i < man.play_siz; i++)
	man.players[i]->draw();
      
      window.display();


    }


  return 0;
}

//####################################################################
//#  Game Scene Manager [manageGameScene]                            #
//#  -> deals with what's happening with players on the screen       #
//#  -> gravity acting upon players, for instance                    #
//####################################################################

int manageGameScene(struct Manager *man)
{
  // check to see which players are 'grounded'
  for (int i = 0; i < man->play_siz; i++)
    {
      // we assume player is falling until proven
      // otherwise
      man->players[i]->is_falling=true;
      
      for (int j = 0; j < man->plat_siz; j++)
	{
	  // if the player;s foot is intersecting a particular platform AND only the bottom
	  // of the player's foot and the top of the platform are touching
	  if (man->players[i]->footR.getGlobalBounds().intersects(man->platforms[j]->obj.getGlobalBounds()) && (  ( (int)(man->players[i]->footR.getGlobalBounds().top + man->players[i]->footR.getGlobalBounds().height) == (int)man->platforms[j]->obj.getGlobalBounds().top) || ( (int)(man->players[i]->footL.getGlobalBounds().top + man->players[i]->footL.getGlobalBounds().height) == (int)man->platforms[j]->obj.getGlobalBounds().top) ) )
	    man->players[i]->is_falling=false;
	  
	}
      
    }

  // applies gravity on every player in the manager
  for (int i = 0; i < man->play_siz; i++)
    {
      man->players[i]->gravity();
      man->players[i]->move();
    }



  return 1;
}

//####################################################################
//#  Manage Player Controls [managePlayerControls]                   #
//#  -> handles input from the human players                         #
//####################################################################

int managePlayerControls(struct Manager *man, int p)
{

  //Player_1
  if (p == 0)
    {

      //SpaceBar - action
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
	  std::cout << "Test Information\n";
	}

      //Up - jump
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && man->players[p]->is_falling==false)
	man->players[p]->y_acc -= (man->players[p]->Spd / 3);

      //Left - move left
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	man->players[p]->mov = -1;

      //Right - move right
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	man->players[p]->mov = 1;

      //If not Right or Left - don't move
      else
	man->players[p]->mov = 0;
      
    }

  //Player_2
  else if (p == 1)
    {
      //X - action
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
	  std::cout << "Test Information\n";
	}

      //W - jump
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && man->players[p]->is_falling==false)
	man->players[p]->y_acc -= (man->players[p]->Spd / 3);

      //A - move left
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	man->players[p]->mov = -1;

      //D - move right
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	man->players[p]->mov = 1;

      // if not A or D - don't move
      else{
	man->players[p]->x_acc = 0;
	man->players[p]->mov = 0;
      }

    }
  
  return 1;
}
