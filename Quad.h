#pragma once
#include <GL/glut.h>
#include <cmath>
#include <vector>
#include <string>
#include <deque>
#include <ctime>
#include <random>
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <iostream>
#include "Point.h"

const int cubeSize = 64;

typedef unsigned short byte;

struct RGB {
  RGB(const byte &r_, const byte &g_, const byte &b_) : r(r_), g(g_), b(b_) {};
  RGB() : r(255), g(255), b(255) {};
  bool operator==(const RGB &rhs);
  byte r;
  byte g;
  byte b;
};

class Quad {
 public:
  Quad() : rgb({255, 255, 255}), LB({0, 0}), RT({1, 1}) {};
  Quad(const Point &point, const RGB &rgb);
  virtual void SetColor(const RGB &rgb_);
  RGB GetColor() const;
  int GetX() const;
  int GetY() const;
  Point GetLB() const;
  Point GetRT() const;
  virtual void Draw() const = 0;
  void Act(const Point &vec);
 private:
  Point LB;
  Point RT;
  RGB rgb;
};


bool IfContact(const Quad &quad1, const Quad &quad2);