#pragma once
#ifndef GMAE_Scene_manager
#define GMAE_Scene_manager

#include <SFML/Graphics.hpp>
#include "Menu_scene.h"
#include "Game_scene.h"
#include "Pause_scene.h"

enum class SceneType {
  GAME,
  OPTION,
  PAUSE,
  MENU
};

class Scene_manager {
 public:
  Scene_manager(const int &width, const int &height, RenderWindow &window);
  void change_scene(const SceneType &new_scene_type, RenderWindow &window);
  void draw(RenderWindow &window, ll &time);
  void keyRelease(Keyboard::Key &code, RenderWindow &window);

 private:
  Pause_scene pause_scene;
  Menu_scene menu_scene;
  Game_scene game_scene;
  SceneType active_scene;
};

#endif //GMAE_Scene_manager