#pragma once
#ifndef GMAE__PAUSE_SCENE_H_
#define GMAE__PAUSE_SCENE_H_
#include "Scene.h"

class Pause_scene :public Scene {
 public:
  Pause_scene(const int &width, const int &height, RenderWindow &window);
  ~Pause_scene() = default;
  void MoveUp();
  void MoveDown();
  int GetSelected() const { return selected; }
  void draw(sf::RenderWindow &window, ll& time) override;
  void keyRelease(Keyboard::Key &code);
 private:
  Text text[3];
  int selected;
};

#endif //GMAE__PAUSE_SCENE_H_
