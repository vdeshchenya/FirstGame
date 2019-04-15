#include <iostream>
#include "Game.h"

Game::Game(const std::string &name_, const int &width_, const int &height_)
    : name(name_), width(width_), height(height_), sceneManager(width_, height_, window) {};

void Game::start() {
  window.create(VideoMode(width, height), name);
  Clock clock;
  unsigned long long int time = 0;

  while (window.isOpen()) {
    Time t = clock.restart();
    Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {
        case Event::Closed: {
          window.close();
          break;
        }
        case Event::KeyReleased: {
          sceneManager.keyRelease(event.key.code, window);
          break;
        }
        case Event::Resized: {
          FloatRect visibleArea(0, 0, event.size.width, event.size.height);
          window.setView(View(visibleArea));
          break;
        }
        default:break;
      }
    }

    window.clear();

    sceneManager.draw(window, time);
    window.display();

    time += t.asMicroseconds();
  }
}