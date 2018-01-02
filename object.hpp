#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Object
{
public:
  sf::RenderWindow *win;
  sf::Texture tl;
  sf::Sprite obj;

  Object(void);

  void setFile(std::string texturefile);
  void setWindow(sf::RenderWindow *window);
  void setPos(float x, float y);
  
private:
protected:
};

#endif
