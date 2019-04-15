#pragma once
#ifndef GMAE_GAME_SCENE_H
#define GMAE_GAME_SCENE_H
#include "Scene.h"
#include "MainPlayer.h"
#include "List.h"

class Game_scene : public Scene {
 public:
  Game_scene(const int &width_, const int &height, RenderWindow &window);

  void draw(RenderWindow &window, ll &time) override;
  void keyRelease(Keyboard::Key &code);

 private:
  MainPlayer player;
  int score;
  int lifes;

  unsigned long long int t;

  Texture hearth_texture;
  Sprite hearth_sprite;
  Image hearth_image;
  Texture textGameOver_texture;
  Sprite textGameOver_sprite;
  Image textGameOver_image;
  int SpaceForTop;
  int WField, HField;
  int TimeForNewBlock;
  double K;
  int scoreForHit;
  Text text;
  int scoreForStep;
  List blocks;

  void DrawGameStats(RenderWindow &window);
  void DrawPlayer(RenderWindow &window);
  void DrawField(RenderWindow &texture);
  void DrawBlocks(RenderWindow &window);
  void GetMove();
  void NewBlock();
  void Contact(Node *block, const BlockPlayer &quad);
};

#endif //GMAE_GAME_SCENE_H
