#pragma once
#ifndef GMAE_Menu_scene
#define GMAE_Menu_scene

#include "Scene.h"

class Menu_scene : public Scene {
 public:
  Menu_scene(const int &width, const int &height, RenderWindow &window);
  void MoveUp();
  void MoveDown();
  int GetSelected() const;
  void draw(RenderWindow &window, ll &time) override;
  void keyRelease(Keyboard::Key &code);

 private:
  Text text[3];
  int selected;
};

#endif //GMAE_Menu_scene