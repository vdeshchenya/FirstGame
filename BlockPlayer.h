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
  BlockPlayer() = default;
  BlockPlayer(const Point &point, const MainBlockType &type);
  void Draw(RenderWindow& window) const override;
  MainBlockType GetType() { return type; }
  Color GetColor() const {return type_to_color(type);}
  void SetType(const MainBlockType& type_) { type = type_; }
 private:
  MainBlockType type;
  Color type_to_color(const MainBlockType& type) const;
};

#endif //GMAE__BLOCKPLAYER_H_
