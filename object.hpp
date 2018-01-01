#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

class Object
{
public:
  sf::RenderWindow *win;
  sf::Texture tl;
  sf::Sprite obj;

  Object(sf::RenderWindow *window, char *texturefile);
  
private:
protected:
};

#endif
