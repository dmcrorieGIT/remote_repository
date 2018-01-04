#include "animations.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>


void animPlayer(bool move)
{

  if (move)
    {
      player->anim[0]=0; player->anim[1]=0;
      player->anim[2]=0; player->anim[3]=0;
      player->anim[4]=0; player->anim[5]=0;
      player->anim[6]=0; player->anim[7]=0;
      player->anim[8]=0; player->anim[9]=0;
    }
  else
    {
      player->anim[0]=0; player->anim[1]=0;
      player->anim[2]=0; player->anim[3]=0;
      player->anim[4]=0; player->anim[5]=0;
      player->anim[6]=0; player->anim[7]=0;
      player->anim[8]=0; player->anim[9]=0;
    }

}
