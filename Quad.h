#pragma once
#ifndef GMAE__QUAD_H_
#define GMAE__QUAD_H_
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Point.h"

const int cubeSize = 80;
const Vector2f CubeSize(cubeSize, cubeSize);

typedef unsigned short byte;

class Quad {
 public:
  Quad(const Point &point);
  int GetX() const;
  int GetY() const;
  Point GetLB() const;
  Point GetRT() const;
  virtual void Draw(RenderWindow &window) = 0;
  void Act(const Point &vec);
 private:
  Point LB;
  Point RT;
 protected:
  Image image;
  Texture texture;
  Sprite sprite;
};

bool IfContact(const Quad &quad1, const Quad &quad2);

#endif //GMAE__QUAD_H_
