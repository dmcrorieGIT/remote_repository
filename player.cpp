#include "player.hpp"

  
Player::Player(sf::RenderWindow *window, int num, int xi, int yi)
{
  switch(num){
  case 1:
    heR_t.loadFromFile("Images/Player1_Head_Right.png");
    heL_t.loadFromFile("Images/Player1_Head_Left.png");
    ha_t.loadFromFile("Images/Player1_Hand.png");
    bo_t.loadFromFile("Images/Player1_Body.png");
    fo_t.loadFromFile("Images/Player1_Foot.png");
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

  x = xi; y = yi;
  win = window;
  
  footR.setTexture(fo_t);
  footL.setTexture(fo_t);
  handR.setTexture(ha_t);
  handL.setTexture(ha_t);
  head.setTexture(heR_t);
  body.setTexture(bo_t);

  body.setPosition(x, y);
  head.setPosition(x+7, y-35);
  handR.setPosition(x+8, y+12);
  handL.setPosition(x+6, y+12);
  footR.setPosition(x+6, y+60);
  footL.setPosition(x+18, y+60);
}

void Player::draw(void)
{
  win->draw(handL);
  win->draw(footL);
  win->draw(body);
  win->draw(head);
  win->draw(handR);
  win->draw(footR);
}

void Player::move(int mov)
{
  x += mov;
}
