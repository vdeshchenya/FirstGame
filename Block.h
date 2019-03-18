#pragma once
#include "Quad.h"

enum class BlockType {
  Red,
  Green,
  Yellow,
  Blue,
  Black,
  Life,
};

class Block : public Quad {
 public:
  Block(const BlockType &type_, const int &x);
  void Draw() const override;
  void SetType(const BlockType &type);
 private:
  BlockType type;
  RGB TypeToRGB(const BlockType &type) const;
};