#include "Scene_manager.h"

Scene_manager::Scene_manager(const int &width, const int &height, RenderWindow &window) : active_scene(SceneType::MENU),
                                                                                          menu_scene(width,
                                                                                                     height,
                                                                                                     window),
                                                                                          pause_scene(width,
                                                                                                      height,
                                                                                                      window),
                                                                                          game_scene(width,
                                                                                                     height,
                                                                                                     window) {};

void Scene_manager::keyRelease(Keyboard::Key &code, RenderWindow &window) {
  switch (active_scene) {
    case SceneType::MENU: {
      if (code == Keyboard::Enter || code == Keyboard::Space) {
        int new_scene = menu_scene.GetSelected();
        if (new_scene == 2)
          window.close();
        else {
          if (new_scene == 0)
            change_scene(SceneType::GAME, window);
          else if (new_scene == 1)
            change_scene(SceneType::OPTION, window);
        }
      } else
        menu_scene.keyRelease(code);
    }
    case SceneType::GAME: {
      if (code == Keyboard::Space || code == Keyboard::Escape) {
        change_scene(SceneType::PAUSE, window);
      }
      game_scene.keyRelease(code);
    }
    case SceneType::PAUSE: {
      if (code == Keyboard::Enter || code == Keyboard::Space) {
        int new_scene = pause_scene.GetSelected();
        switch (new_scene) {
          case 0: {
            change_scene(SceneType::GAME, window);
            break;
          }
          case 1: {
            change_scene(SceneType::OPTION, window);
            break;
          }
          case 2: {
            change_scene(SceneType::MENU, window);
            break;
          }
          default:break;
        }
      } else
        pause_scene.keyRelease(code);
    }
    default:break;
  }
}

void Scene_manager::draw(RenderWindow &window, ll &time) {
  switch (active_scene) {
    case SceneType::MENU: {
      menu_scene.draw(window, time);
      break;
    }
    case SceneType::GAME: {
      game_scene.draw(window, time);
      break;
    }
    case SceneType::PAUSE: {
      pause_scene.draw(window, time);
      break;
    }
    default:break;
  }
}

void Scene_manager::change_scene(const SceneType &new_scene_type, RenderWindow &window) {
  active_scene = new_scene_type;
  if (active_scene == SceneType::GAME)
    SetSize(window, game_scene.getSize().x, game_scene.getSize().y);
  else if (active_scene == SceneType::PAUSE)
    pause_scene = Pause_scene(window.getSize().x, window.getSize().y, window);
  else if (active_scene == SceneType::MENU)
    SetSize(window, menu_scene.getSize().x, menu_scene.getSize().y);
}