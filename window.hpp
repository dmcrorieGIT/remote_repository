#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "object.hpp"

struct Manager
{
  Player *players[20];
  Object *platforms[10];

  int play_siz;
  int plat_siz;
};


int gameRenderer(void);

#endif
