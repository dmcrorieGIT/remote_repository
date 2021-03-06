#include "player.hpp"

//##############################################################
// Player Constructor, taking in the window, player number,    #
// x-coordinate, and y-coordinate                              #
//##############################################################
Player::Player(sf::RenderWindow *window, int num, int xi, int yi)
{
  // find out which player model the user wants
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

   // if the user entered an invalid choice, then exit
 default:
   exit(-1);
  }

  // Set initial attributes
  Spd = 0.5;

  // initialize movement & position info
  mov = 0;
  x_acc = 0.0;
  y_acc = 0.0;
  is_moving=false;
  is_falling=false;
  x = xi; y = yi;
  win = window;
  face(true);
  hands=true; feet=true; lfoot=false; rfoot=true;

  // set sprite textures to the user preferences
  footR.setTexture(fo_t);
  footL.setTexture(fo_t);
  handR.setTexture(ha_t);
  handL.setTexture(ha_t);
  head.setTexture(heR_t);
  body.setTexture(bo_t);

  // set the sprite positions
  body.setPosition(x, y);
  head.setPosition(x+bias[0], y+bias[1]);
  handR.setPosition(x+bias[2], y+bias[3]);
  handL.setPosition(x+bias[4], y+bias[5]);
  footR.setPosition(x+bias[6], y+bias[7]);
  footL.setPosition(x+bias[8], y+bias[9]);
}


//#############################################
// Player::draw                               #
// -> draws all the players body parts to the #
//    window                                  #
//#############################################
void Player::draw(void)
{
  win->draw(handL);
  win->draw(footL);
  win->draw(body);
  win->draw(head);
  win->draw(handR);
  win->draw(footR);
}

//#############################################
// Player::move                               #
// -> moves the player according to mov,      #
//    x_acc, and y_acc values                 #
//#############################################
void Player::move(void)
{

  // if mov is negative, then player is accelerating
  // to the left; face player left as well
  if (mov < 0)
    {face(false); is_moving=false; x_acc += -0.005;}

  // if move is positive, then player is accelerating
  // to the right; face player right as well
  else if (mov > 0)
    {face(true); is_moving=false; x_acc += 0.005;}

  else
    {is_moving=false; x_acc=0;}

  // if player's acceleration is greater than his
  // speed, his acceleration is equal to his Spd
  if (x_acc > Spd)
    x_acc = Spd;
  else if (x_acc < (Spd*-1))
    x_acc = (Spd*-1);
  x += x_acc;

  // if player's fall speed is greater than 1, then
  // his fall speed is equal to 1
  if (y_acc > 1)
    y_acc = 1;
  y += y_acc;

  animPlayer();
  if (anim[7] < 0 || anim[9] < 0)
    std::cout << "Less than zero!!\n";

  // set the players body parts to their new
  // positions  
  body.setPosition(x, y);
  head.setPosition(x+bias[0]+anim[0], y+bias[1]+anim[1]);
  handR.setPosition(x+bias[2]+anim[2], y+bias[3]+anim[3]);
  handL.setPosition(x+bias[4]+anim[4], y+bias[5]+anim[5]);
  footR.setPosition(x+bias[6]+anim[6], y+bias[7]-anim[7]);
  footL.setPosition(x+bias[8]+anim[8], y+bias[9]-anim[9]);
  
}

//#############################################
// Player::face                               #
// -> orients the position and textures of    #
//    the player to face either right or left #
//#############################################
void Player::face(bool right)
{
  
  // face the player and all his parts to the right
  if (right)
    {
      head.setTexture(heR_t);
      bias[0] = 7; bias[1] = -35;   //head
      bias[2] = 8; bias[3] = 12;    //R-hand
      bias[4] = 6; bias[5] = 12;    //L-hand
      bias[6] = 6; bias[7] = 60;    //R-foot
      bias[8] = 18; bias[9] = 60;   //L-foot
    }

  // face the player and all his parts to the left
  else
    {
      head.setTexture(heL_t);
      bias[0] = 0; bias[1] = -35;   //head
      bias[2] = 8; bias[3] = 12;    //R-hand
      bias[4] = 6; bias[5] = 12;    //L-hand
      bias[6] = 6; bias[7] = 60;    //R-foot
      bias[8] = 18; bias[9] = 60;   //L-foot
    }

}

//#############################################
// Player::gravity                            #
// -> if the player is falling, adds gravity  #
//    to the players y acceleration           #
//#############################################
void Player::gravity(void)
{
  if (is_falling)
    y_acc += 0.001;
  else if (y_acc > 0)
    y_acc = 0;
}


void Player::animPlayer(void)
{

  if (is_moving)
    {

      // leave head alone
      anim[0]=0; anim[1]=0;

      // handle hands
      if (anim[2] <= -2)
	hands=true;
      else if (anim[2] >= 2)
	hands=false;

      // handle the feet
      if (rfoot)
	{
	  if (anim[7] <= 0)
	    {feet = true; rfoot=false; anim[7]=0;}
	  else if (anim[7] >= 2)
	    feet = false;
	}
      else if (!rfoot)
	{
	  if (anim[9] <= 0)
	    {feet = true; rfoot=true; anim[9]=0;}
	  else if (anim[9] >= 2)
	    feet = false;
	}
      // shuffle right & left hand
      if (hands)
	{anim[2]+=0.04; anim[4]-=0.04;}
      else
	{anim[2]-=0.04; anim[4]+=0.04;}

      // shuffle right & left foot
      if (feet)
	{
	  if (rfoot)
	    anim[7] += 0.02;
	  else if (!rfoot)
	    anim[9] += 0.02;
	}
      else if (!feet)
	{
	  if (rfoot)
	    anim[7] -= 0.02;
	  else if (!rfoot)
	    anim[9] -= 0.02;
	}

      // make sure feet do not go 'below the ground'
      if (anim[7] < 0)
	anim[7] = 0;
      if (anim[9] < 0)
	anim[9] = 0;
      
    }
  else
    {
      hands=true; feet=true; rfoot=true; 
      anim[0]=0; anim[1]=0;
      anim[2]=0; anim[3]=0;
      anim[4]=0; anim[5]=0;
      anim[6]=0; anim[7]=0;
      anim[8]=0; anim[9]=0;
    }

}
