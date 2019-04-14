#pragma once
#ifndef GMAE_Game
#define GMAE_Game

#include "Scene_manager.h"
#include <string>

class Game {
 private:
  RenderWindow window;
  const std::string name;
  int width, height;
  Scene_manager sceneManager;

 public:
  Game(const std::string &name_, const int &width_, const int &height_) : name(name_), width(width_), height(height_), sceneManager(width_, height_, window) {}

  void start();
};

#endif