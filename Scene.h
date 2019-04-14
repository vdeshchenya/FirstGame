#pragma once
#ifndef GMAE_SCENE_H
#define GMAE_SCENE_H

#include <SFML/Graphics.hpp>
using namespace sf;

const Color mainColor = Color::White;
const Color selectedColor = Color::Red;

void SetSize(RenderWindow& window, const int& width, const int& height);

typedef unsigned long long int ll;
class Scene {
 public:
  Scene(const int& width_, const int& height_) : width(width_), height(height_) {};
  virtual void draw(sf::RenderWindow &window, ll& time) = 0;
  virtual Vector2u getSize() const;
 protected:
  Sprite backgroundSprite;
  Texture backgroundTexture;
  Font font;
  int width, height;
};


#endif //GMAE_SCENE_H
