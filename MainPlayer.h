#pragma once
#include "Quad.h"
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
  void SetMove(const Move& move);
  void DoMove(const int& WField, const int& HField);
  void Draw() const;
  vector<BlockPlayer> GetPlayer();
 private:
  Move move;
  vector<BlockPlayer> player;
};