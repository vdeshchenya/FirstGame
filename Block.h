#pragma once
#include "Quad.h"
#ifndef GMAE__BLOCK_H_
#define GMAE__BLOCK_H_

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
  void Draw(RenderWindow &window) override;
  void SetType(const BlockType &type);
  BlockType GetType();
 private:
  BlockType type;
};

#endif //GMAE__BLOCK_H_
