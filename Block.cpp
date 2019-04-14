#include "Block.h"

int SpaceForTop = 30;
int NewBlockY = -9 * cubeSize + SpaceForTop + 1;

Block::Block(const BlockType &type_, const int &x) : Quad({x, NewBlockY},type_to_color(type_)), type(type_) {}

void Block::Draw(RenderWindow& window) const{
  VertexArray quad(sf::Quads, 4);
  quad[0].position = sf::Vector2f(GetLB().x, GetLB().y);
  quad[1].position = sf::Vector2f(GetRT().x, GetLB().y);
  quad[2].position = sf::Vector2f(GetRT().x, GetRT().y);
  quad[3].position = sf::Vector2f(GetLB().x, GetRT().y);
  for(int i = 0; i < 4; ++i)
    quad[i].color = type_to_color(type);
  window.draw(quad);
}

Color Block::type_to_color(const BlockType &type) const {
  switch (type) {
    case BlockType::Red : { return Color::Red; }
    case BlockType::Green : { return Color::Green; }
    case BlockType::Yellow : { return Color::Yellow; }
    case BlockType::Blue : { return Color::Blue; }
    case BlockType::Black : { return Color::Black; }
    case BlockType::Life : { return {}; }
  }
}

void Block::SetType(const BlockType &type_) {
  type = type_;
}