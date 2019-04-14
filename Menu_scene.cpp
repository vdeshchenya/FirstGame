#include "Menu_scene.h"

const Color mainColor = Color::White;
const Color selectedColor = Color::Red;

Menu_scene::Menu_scene(const int &width, const int &height, RenderWindow& window) : selected(0) {
  font.loadFromFile("Resources/rita.ttf");
  for (int i = 0; i < 3; ++i) {
    text[i].setFont(font);
    text[i].setFillColor(mainColor);
    text[i].setPosition(Vector2f(width / 2.0, height / 4.0 * (i + 1)));
  }
  text[selected].setFillColor(selectedColor);
  text[0].setString("Play");
  text[1].setString("Options");
  text[2].setString("Exit");
  backgroundTexture.loadFromFile("Resources/backgroundMenu.png");
  backgroundSprite.setTexture(backgroundTexture);
}

void Menu_scene::MoveUp() {
  if (selected >= 1) {
    text[selected--].setFillColor(mainColor);
    text[selected].setFillColor(selectedColor);
  }
}

void Menu_scene::MoveDown() {
  if (selected <= 1) {
    text[selected++].setFillColor(mainColor);
    text[selected].setFillColor(selectedColor);
  }
}

void Menu_scene::draw(sf::RenderWindow &window, ll& time) {
  backgroundSprite.setTexture(backgroundTexture);
  window.draw(backgroundSprite);
  for (auto &it: text) {
    it.setFont(font);
    window.draw(it);
  }
}

void Menu_scene::keyRelease(Keyboard::Key &code) {
  switch (code) {
    case Keyboard::Up:MoveUp();
      break;
    case Keyboard::Down:MoveDown();
      break;
  }
}