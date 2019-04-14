#include "Scene_manager.h"

void Scene_manager::keyRelease(Keyboard::Key &code, RenderWindow &window) {
  switch (active_scene) {
    case SceneType::MENU: {
      if (code == Keyboard::Enter) {
        int new_scene = menu_scene.GetSelected();
        if (new_scene == 2)
          window.close();
        else {
          if (new_scene == 0)
            change_scene(SceneType::GAME);
          else if (new_scene == 1)
            change_scene(SceneType::OPTION);
        }
      } else
        menu_scene.keyRelease(code);
    }
    case SceneType::GAME: {
      game_scene.keyRelease(code);
    }
  }
}