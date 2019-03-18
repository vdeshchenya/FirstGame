#pragma once
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
  void Draw() const override;
 private:
  RGB MTypeToRGB(const MainBlockType &type) const;
};