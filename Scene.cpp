#include "Scene.h"

void SetSize(RenderWindow& window, const int& width, const int& height) {
  window.setSize(Vector2u(width, height));
  FloatRect visibleArea(0, 0, width, height);
  window.setView(View(visibleArea));
}

Vector2u Scene::getSize() const {
  return Vector2u(width, height);
}