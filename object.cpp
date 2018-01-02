#include "object.hpp"

Object::Object(void)
{
  
  obj.setPosition(100, 100);

}

void Object::setFile(std::string texturefile)
{
  if (!(tl.loadFromFile(texturefile)))
    tl.loadFromFile("Images/Other/Warning.png");

  obj.setTexture(tl);

  return;
}

void Object::setWindow(sf::RenderWindow *window)
{

  win = window;

  return;
}

void Object::setPos(float x, float y)
{
  obj.setPosition(x, y);

  return;
}
