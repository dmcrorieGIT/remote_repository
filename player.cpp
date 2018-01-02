#include "player.hpp"


Player::Player(sf::RenderWindow *window, int num, int xi, int yi)
{
  switch(num){
  case 1:
    heR_t.loadFromFile("Images/Player/Player1_Head_Right.png");
    heL_t.loadFromFile("Images/Player/Player1_Head_Left.png");
    ha_t.loadFromFile("Images/Player/Player1_Hand.png");
    bo_t.loadFromFile("Images/Player/Player1_Body.png");
    fo_t.loadFromFile("Images/Player/Player1_Foot.png");
    break;

 case 2:
   heR_t.loadFromFile("Images/Player/Player2_Head_Right.png");
   heL_t.loadFromFile("Images/Player/Player2_Head_Left.png");
   ha_t.loadFromFile("Images/Player/Player2_Hand.png");
   bo_t.loadFromFile("Images/Player/Player2_Body.png");
   fo_t.loadFromFile("Images/Player/Player2_Foot.png");
   break;

 default:
   exit(-1);
  }

  Spd = 0.3;
  mov = 0;
  
  x_acc = 0.0;
  y_acc = 0.0;
  is_falling=false;
  x = xi; y = yi;
  win = window;
  face(true);
  
  footR.setTexture(fo_t);
  footL.setTexture(fo_t);
  handR.setTexture(ha_t);
  handL.setTexture(ha_t);
  head.setTexture(heR_t);
  body.setTexture(bo_t);

  body.setPosition(x, y);
  head.setPosition(x+bias[0], y+bias[1]);
  handR.setPosition(x+bias[2], y+bias[3]);
  handL.setPosition(x+bias[4], y+bias[5]);
  footR.setPosition(x+bias[6], y+bias[7]);
  footL.setPosition(x+bias[8], y+bias[9]);
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

void Player::move(void)
{
  
  if (mov < 0)
    {face(false); x_acc += -0.005;}
  else if (mov > 0)
    {face(true); x_acc += 0.005;}

  if (x_acc > Spd)
    x_acc = Spd;
  else if (x_acc < (Spd*-1))
    x_acc = (Spd*-1);
  x += x_acc;

  if (y_acc > 1)
    y_acc = 1;
  y += y_acc;
  
  body.setPosition(x, y);
  head.setPosition(x+bias[0], y+bias[1]);
  handR.setPosition(x+bias[2], y+bias[3]);
  handL.setPosition(x+bias[4], y+bias[5]);
  footR.setPosition(x+bias[6], y+bias[7]);
  footL.setPosition(x+bias[8], y+bias[9]);
}

void Player::face(bool right)
{
  if (right)
    {
      head.setTexture(heR_t);
      bias[0] = 7; bias[1] = -35;   //head
      bias[2] = 8; bias[3] = 12;
      bias[4] = 6; bias[5] = 12;
      bias[6] = 6; bias[7] = 60;
      bias[8] = 18; bias[9] = 60;
    }
  else
    {
      head.setTexture(heL_t);
      bias[0] = 0; bias[1] = -35;   //head
      bias[2] = 8; bias[3] = 12;
      bias[4] = 6; bias[5] = 12;
      bias[6] = 6; bias[7] = 60;
      bias[8] = 18; bias[9] = 60;
    }

}

void Player::gravity(void)
{
  if (is_falling)
    y_acc += 0.001;
  else if (y_acc > 0)
    y_acc = 0;
}
