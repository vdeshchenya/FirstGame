#include "Quad.h"

//RGB
bool RGB::operator==(const RGB &rhs) {
  return ( (this->r == rhs.r) && (this->g == rhs.g) && (this->b == rhs.b));
}

//Quad
Quad::Quad(const Point &point, const RGB &rgb) : LB(point), rgb(rgb) {
  RT = {point.x + cubeSize, point.y + cubeSize};
}

void Quad::SetColor(const RGB &rgb_) { rgb = rgb_; }

RGB Quad::GetColor() const { return rgb; }

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