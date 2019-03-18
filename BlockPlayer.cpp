#include "BlockPlayer.h"

GLAPI void GLAPIENTRY glColor3ub( GLubyte red, GLubyte green, GLubyte blue );

void BlockPlayer::Draw() const {
  RGB rgb = this->GetColor();
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glVertex2i(this->GetLB().x, this->GetLB().y);
  glVertex2i(this->GetLB().x, this->GetRT().y);
  glVertex2i(this->GetRT().x, this->GetRT().y);
  glVertex2i(this->GetRT().x, this->GetLB().y);
}

BlockPlayer::BlockPlayer(const Point &point, const MainBlockType &type) : Quad(point, MTypeToRGB(type)) {}

RGB BlockPlayer::MTypeToRGB(const MainBlockType &type) const {
  switch (type) {
    case MainBlockType::Red : { return {255, 0, 0}; }
    case MainBlockType::Green : { return {0, 255, 0}; }
    case MainBlockType::Yellow : { return {255, 255, 0}; }
    case MainBlockType::Blue : { return {0, 0, 255}; }
    case MainBlockType::White : { return {255, 255, 255}; }
  }
}