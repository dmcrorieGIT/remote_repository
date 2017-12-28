#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Player
{
  
public:

  float Str, Spd, Int;
  bool is_moving;
  sf::Texture heR_t, heL_t, ha_t, bo_t;
  sf::Sprite footL, footR, handL, handR, Body, Head;
  
  Player(int num);
  
private:
protected:
};

#endif
