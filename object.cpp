#include "object.hpp"

Object::Object(sf::RenderWindow *window, char *texturefile)
{
  win = window;
  
  if (!(tl.loadFromFile(texturefile)))
    exit(EXIT_FAILURE);

  obj.setTexture(tl);
  obj.setPosition(100, 100);

}
