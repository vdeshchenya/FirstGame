#include <iostream>
#include "Game.h"

void Game::start() {
  window.create(sf::VideoMode(width, height), name);
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
        default:
          break;
      }
    }

    window.clear();

    sceneManager.draw(window, time);
    window.display();

    time += t.asMicroseconds();
  }
}