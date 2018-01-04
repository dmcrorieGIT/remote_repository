#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Player
{
  
public:

  float bias[10];
  float anim[10];
  sf::RenderWindow *win;
  float Str, Spd, Int, x, y, x_acc, y_acc;
  bool is_moving, can_moveR, can_moveL, is_falling, hands, feet, lfoot, rfoot;
  sf::Texture heR_t, heL_t, ha_t, bo_t, fo_t;
  sf::Sprite footL, footR, handL, handR, body, head;
  int mov;
  
  Player(sf::RenderWindow *window, int num, int xi, int yi);
  void draw(void);
  void move(void);
  void face(bool right);
  void gravity(void);

  void animPlayer(void);
  
private:
protected:
};

struct Player_Handler
{
  Player  *players[10];

  int size;
};

#endif
