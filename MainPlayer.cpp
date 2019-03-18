#include "MainPlayer.h"

MainPlayer::MainPlayer() : move(Move::NOTHING) {
  player.resize(5);
  player[0] = {{cubeSize,cubeSize}, MainBlockType::White};
  player[1] = {{0, cubeSize}, MainBlockType ::Red};
  player[2] = {{cubeSize, 2*cubeSize}, MainBlockType::Green};
  player[3] = {{2*cubeSize, cubeSize}, MainBlockType::Yellow};
  player[4] = {{cubeSize, 0}, MainBlockType::Blue};
}

MainPlayer::MainPlayer(const Point &point, const Move &move) : move(move) {
  player.resize(5);
  player[0] = {point, MainBlockType::White};
  player[1] = {{point.x - cubeSize, point.y}, MainBlockType::Red};
  player[2] = {{point.x, point.y + cubeSize}, MainBlockType::Green};
  player[3] = {{point.x + cubeSize, point.y}, MainBlockType::Yellow};
  player[4] = {{point.x, point.y - cubeSize}, MainBlockType::Blue};
}

void MainPlayer::Act(const Point &vec) {
  for (auto &it: player) {
    it.Act(vec);
  }
}

Move MainPlayer::GetMove() const {
  return move;
}

void MainPlayer::SetMove(const Move& move_) {
  move = move_;
}

void MainPlayer::DoMove(const int& WField, const int& HField) {
  if (move == Move::LEFT) {
    if (player[0].GetX() > 1 + cubeSize)
      Act({-cubeSize, 0});
  }
  if (GetMove() == Move::RIGHT) {
    if (player[0].GetX() < 1 + (WField - 2) * cubeSize)
      Act({cubeSize, 0});
  }
  if (GetMove() == Move::UP) {
    if (player[0].GetY() < (HField - 2) * cubeSize)
      Act({0, cubeSize});
  }
  if (GetMove() == Move::DOWN) {
    if (player[0].GetY() > cubeSize)
      Act({0, -cubeSize});
  }
  if (GetMove() == Move::ROTATELEFT) {
    RGB temp = player[1].GetColor();
    player[1].SetColor(player[2].GetColor());
    player[2].SetColor(player[3].GetColor());
    player[3].SetColor(player[4].GetColor());
    player[4].SetColor(temp);
  }
  if (GetMove() == Move::ROTATERIGHT) {
    RGB temp = player[1].GetColor();
    player[1].SetColor(player[4].GetColor());
    player[4].SetColor(player[3].GetColor());
    player[3].SetColor(player[2].GetColor());
    player[2].SetColor(temp);
  }
  SetMove(Move::NOTHING);
}

void MainPlayer::Draw() const {
  glBegin(GL_QUADS);
  for (const auto& it: player) {
    it.Draw();
  }
  glEnd();
}

vector<BlockPlayer> MainPlayer::GetPlayer() { return player; }