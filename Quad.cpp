#include "Quad.h"

//Quad
Quad::Quad(const Point &point, const Color &color_) : LB(point), RT({point.x + cubeSize, point.y + cubeSize}), color(color_) {}

void Quad::SetColor(const Color &color_) { color = color_; }

Color Quad::GetColor() const { return color; }

int Quad::GetX() const { return LB.x; }

int Quad::GetY() const { return LB.y; }

Point Quad::GetLB() const { return LB; }

Point Quad::GetRT() const { return RT; }

void Quad::Act(const Point &vec) {
  LB.Act(vec);
  RT.Act(vec);
}

bool IfContact(const Quad &quad1, const Quad &quad2) {
  return ((quad1.GetY() == quad2.GetY()) && (quad1.GetX() == quad2.GetX()));
};