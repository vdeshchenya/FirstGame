#pragma once
#ifndef GMAE_Scene_manager
#define GMAE_Scene_manager

#include <SFML/Graphics.hpp>
#include "Menu_scene.h"
#include "Game_scene.h"

enum class SceneType {
  GAME,
  OPTION,
  EXIT,
  PAUSE,
  MENU
};

class Scene_manager {
 public:
  Scene_manager(const int &width, const int &height, RenderWindow &window)
      : active_scene(SceneType::GAME), menu_scene(width, height, window), game_scene(width, height, window) {}
  void change_scene(const SceneType &new_scene_type) {
    active_scene = new_scene_type;
  }

  const SceneType &get_sceneType() {
    return active_scene;
  }

  void draw(sf::RenderWindow &window, ll& time) {
    switch (active_scene) {
      case SceneType::MENU: {
        menu_scene.draw(window, time);
        break;
      }
      case SceneType::GAME: {
        game_scene.draw(window, time);
        break;
      }
    }
  }

  void keyRelease(Keyboard::Key &code, RenderWindow &window);

 private:
  Menu_scene menu_scene;
  Game_scene game_scene;
  SceneType active_scene;
};

#endif //GMAE_Scene_manager