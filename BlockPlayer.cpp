#include "BlockPlayer.h"

void BlockPlayer::Draw(RenderWindow& window) const {
  VertexArray quad(Quads, 4);
  quad[0].position = Vector2f(GetLB().x, GetLB().y);
  quad[1].position = Vector2f(GetRT().x, GetLB().y);
  quad[2].position = Vector2f(GetRT().x, GetRT().y);
  quad[3].position = Vector2f(GetLB().x, GetRT().y);
  for(int i = 0; i < 4; ++i)
    quad[i].color = type_to_color(type);
  window.draw(quad);
}

BlockPlayer::BlockPlayer(const Point &point, const MainBlockType &type_) : Quad(point, type_to_color(type_)),
                                                                           type(type_) {};
Color BlockPlayer::type_to_color(const MainBlockType &type) const {
  switch (type) {
    case MainBlockType::White:return Color::White;
    case MainBlockType::Blue:return Color::Blue;
    case MainBlockType::Green :return Color::Green;
    case MainBlockType::Red:return Color::Red;
    case MainBlockType::Yellow:return Color::Yellow;
  }
}