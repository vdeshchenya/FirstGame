#pragma once
#ifndef GMAE__BLOCKPLAYER_H_
#define GMAE__BLOCKPLAYER_H_
#include "Quad.h"

enum class MainBlockType {
  Red,
  Green,
  Yellow,
  Blue,
  White,
};

class BlockPlayer : public Quad {
 public:
  BlockPlayer(const Point &point, const MainBlockType &type);
  void Draw(RenderWindow &window) override;
  void Init();
  MainBlockType GetType() const;
  void SetType(const MainBlockType &type_);
 private:
  MainBlockType type;
};

#endif //GMAE__BLOCKPLAYER_H_
