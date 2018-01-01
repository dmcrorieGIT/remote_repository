#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Player
{
  
public:

  float bias[10];
  sf::RenderWindow *win;
  float Str, Spd, Int, x, y;
  bool is_moving;
  sf::Texture heR_t, heL_t, ha_t, bo_t, fo_t;
  sf::Sprite footL, footR, handL, handR, body, head;
  
  Player(sf::RenderWindow *window, int num, int xi, int yi);
  void draw(void);
  void move(float mov);
  void face(bool right);
  
private:
protected:
};

#endif
