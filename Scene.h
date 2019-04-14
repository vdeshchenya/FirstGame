#pragma once
#ifndef GMAE_SCENE_H
#define GMAE_SCENE_H

#include <SFML/Graphics.hpp>
using namespace sf;

typedef unsigned long long int ll;
class Scene {
 public:
  virtual void draw(sf::RenderWindow &window, ll& time) = 0;
 protected:
  Sprite backgroundSprite;
  Texture backgroundTexture;
  Font font;
};


#endif //GMAE_SCENE_H
