#pragma once
#ifndef GMAE__QUAD_H_
#define GMAE__QUAD_H_
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Point.h"

const int cubeSize = 80;

typedef unsigned short byte;

class Quad {
 public:
  Quad() : color(Color::White), LB({0, 0}), RT({1, 1}) {};
  Quad(const Point &point, const Color &color_);
  virtual void SetColor(const Color& color_);
  Color GetColor() const;
  int GetX() const;
  int GetY() const;
  Point GetLB() const;
  Point GetRT() const;
  virtual void Draw(RenderWindow& window) const = 0;
  void Act(const Point &vec);
 private:
  Point LB;
  Point RT;
  Color color;
};

bool IfContact(const Quad &quad1, const Quad &quad2);

#endif //GMAE__QUAD_H_
