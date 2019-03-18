#include "Block.h"

int NewBlockY = 11*64;

Block::Block(const BlockType &type_, const int &x) : Quad({x, NewBlockY},TypeToRGB(type_)), type(type_) {}

void Block::Draw() const{
  RGB rgb = this->GetColor();
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glVertex2i(this->GetLB().x, this->GetLB().y);
  glVertex2i(this->GetLB().x, this->GetRT().y);
  glVertex2i(this->GetRT().x, this->GetRT().y);
  glVertex2i(this->GetRT().x, this->GetLB().y);
}

RGB Block::TypeToRGB(const BlockType &type) const {
  switch (type) {
    case BlockType::Red : { return {255, 0, 0}; }
    case BlockType::Green : { return {0, 255, 0}; }
    case BlockType::Yellow : { return {255, 255, 0}; }
    case BlockType::Blue : { return {0, 0, 255}; }
    case BlockType::Black : { return {0, 0, 0}; }
    case BlockType::Life : { return {}; }
  }
}

void Block::SetType(const BlockType &type_) {
  type = type_;
}