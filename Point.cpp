#include "Point.h"
void Point::Act(const Point &vec) {
  x += vec.x;
  y += vec.y;
}