#pragma once
#ifndef GMAE__MAINPLAYER_H_
#define GMAE__MAINPLAYER_H_

#include <vector>
#include "BlockPlayer.h"
using std::vector;

enum class Move {
  ROTATELEFT,
  ROTATERIGHT,
  LEFT,
  UP,
  RIGHT,
  DOWN,
  NOTHING
};

struct MainPlayer {
 public:
  MainPlayer();
  MainPlayer(const Point &point, const Move &move);
  void Act(const Point &vec);
  Move GetMove() const;
  void SetMove(const Move &move);
  void DoMove(const int &WField, const int &HField, const int &SpaceForTop);
  void Draw(RenderWindow &window);
  vector<BlockPlayer> GetPlayer();
  void Init();

 private:
  vector<BlockPlayer> player;
  Move move;
};

#endif //GMAE__MAINPLAYER_H_
