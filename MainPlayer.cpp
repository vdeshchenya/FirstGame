#include "MainPlayer.h"

MainPlayer::MainPlayer() : move(Move::NOTHING) {
  player.clear();
  player.push_back({{cubeSize, cubeSize}, MainBlockType::White});
  player.push_back({{0, cubeSize}, MainBlockType::Red});
  player.push_back({{cubeSize, 2 * cubeSize}, MainBlockType::Green});
  player.push_back({{2 * cubeSize, cubeSize}, MainBlockType::Yellow});
  player.push_back({{cubeSize, 0}, MainBlockType::Blue});
}

MainPlayer::MainPlayer(const Point &point, const Move &move) : move(move) {
  player.clear();
  player.push_back({point, MainBlockType::White});
  player.push_back({{point.x - cubeSize, point.y}, MainBlockType::Red});
  player.push_back({{point.x, point.y + cubeSize}, MainBlockType::Green});
  player.push_back({{point.x + cubeSize, point.y}, MainBlockType::Yellow});
  player.push_back({{point.x, point.y - cubeSize}, MainBlockType::Blue});
}

void MainPlayer::Act(const Point &vec) {
  for (auto &it: player) {
    it.Act(vec);
  }
}

Move MainPlayer::GetMove() const {
  return move;
}

void MainPlayer::SetMove(const Move &move_) {
  move = move_;
}

void MainPlayer::DoMove(const int &WField, const int &HField, const int &SpaceForTop) {
  if (move == Move::LEFT) {
    if (player[0].GetX() > 1 + cubeSize)
      Act({-cubeSize, 0});
  }
  if (GetMove() == Move::RIGHT) {
    if (player[0].GetX() < 1 + (WField - 2) * cubeSize)
      Act({cubeSize, 0});
  }
  if (GetMove() == Move::UP) {
    if (player[0].GetY() > cubeSize + SpaceForTop + 60)
      Act({0, -cubeSize});
  }
  if (GetMove() == Move::DOWN) {
    if (player[0].GetY() < (HField - 2) * cubeSize)
      Act({0, cubeSize});
  }
  if (GetMove() == Move::ROTATERIGHT) {
    auto temp = player[1].GetType();
    player[1].SetType(player[2].GetType());
    player[2].SetType(player[3].GetType());
    player[3].SetType(player[4].GetType());
    player[4].SetType(temp);
  }
  if (GetMove() == Move::ROTATELEFT) {
    auto temp = player[1].GetType();
    player[1].SetType(player[4].GetType());
    player[4].SetType(player[3].GetType());
    player[3].SetType(player[2].GetType());
    player[2].SetType(temp);
  }
  SetMove(Move::NOTHING);
}

void MainPlayer::Draw(RenderWindow &window) {
  for (auto &it: player) {
    it.Draw(window);
  }
}

vector<BlockPlayer> MainPlayer::GetPlayer() { return player; }

void MainPlayer::Init() {
  player[0].Init();
}