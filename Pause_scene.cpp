#include "Pause_scene.h"

Pause_scene::Pause_scene(const int &width_, const int &height_, RenderWindow &window) : Scene(width_, height_),
                                                                                        selected(0) {
  font.loadFromFile("Fonts/rita.ttf");
  for (int i = 0; i < 3; ++i) {
    text[i].setFont(font);
    text[i].setFillColor(mainColor);
    text[i].setPosition(Vector2f(width / 2.5, height / 4.0 * (i + 1)));
  }
  text[selected].setFillColor(selectedColor);
  text[0].setString("Resume");
  text[1].setString("Options");
  text[2].setString("Menu");
  backgroundTexture.loadFromFile("Backgrounds/Pause.png");
  backgroundSprite.setTexture(backgroundTexture);
}

void Pause_scene::MoveUp() {
  if (selected >= 1) {
    text[selected--].setFillColor(mainColor);
    text[selected].setFillColor(selectedColor);
  }
}

void Pause_scene::MoveDown() {
  if (selected <= 1) {
    text[selected++].setFillColor(mainColor);
    text[selected].setFillColor(selectedColor);
  }
}

int Pause_scene::GetSelected() const { return selected; }

void Pause_scene::draw(RenderWindow &window, ll &time) {
  backgroundSprite.setTexture(backgroundTexture);
  window.draw(backgroundSprite);
  for (auto &it: text) {
    it.setFont(font);
    window.draw(it);
  }
}

void Pause_scene::keyRelease(Keyboard::Key &code) {
  switch (code) {
    case Keyboard::Up: {
      MoveUp();
      break;
    }
    case Keyboard::W: {
      MoveUp();
      break;
    }
    case Keyboard::Down: {
      MoveDown();
      break;
    }
    case Keyboard::S: {
      MoveDown();
      break;
    }
    default:break;
  }
}