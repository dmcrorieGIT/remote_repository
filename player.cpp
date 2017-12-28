#include "player.hpp"

  
Player::Player(int num)
{
  switch(num){
  case 1:
    heR_t.loadFromFile("Images/Player1_Head_Right.png");
    heL_t.loadFromFile("Images/Player1_Head_Left.png");
    ha_t.loadFromFile("Images/Player1_Hand.png");
    bo_t.loadFromFile("Images/Player1_Body.png");
    break;

 case 2:
   heR_t.loadFromFile("Images/Player2_Head_Right.png");
   heL_t.loadFromFile("Images/Player2_Head_Left.png");
   ha_t.loadFromFile("Images/Player2_Hand.png");
   bo_t.loadFromFile("Images/Player2_Body.png");
   break;

 default:
   exit(-1);
  }
}
