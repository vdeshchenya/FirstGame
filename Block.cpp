#include "Block.h"

int SpaceForTop = 30;
int NewBlockY = -9 * cubeSize + SpaceForTop + 1;

Block::Block(const BlockType &type_, const int &x) : Quad({x, NewBlockY}, type_to_color(type_)), type(type_) {
  switch (type) {
    case BlockType::Green: {
      image.loadFromFile("Textures/green.png");
      break;
    }
    case BlockType::Red: {
      image.loadFromFile("Textures/red.png");
      break;
    }
    case BlockType::Yellow: {
      image.loadFromFile("Textures/yellow.png");
      break;
    }
    case BlockType::Blue: {
      image.loadFromFile("Textures/blue.png");
      break;
    }
    case BlockType::Life: {
      image.loadFromFile("Textures/green.png");
      break;
    }
    case BlockType::Black: {
      image.loadFromFile("Textures/green.png");
      break;
    }
  }
  texture.loadFromImage(image);
  sprite.setTexture(texture);
}

void Block::Draw(RenderWindow &window) {
  sprite.setTexture(texture);
  sprite.setPosition(GetLB().x, GetLB().y);
  sprite.setScale(
      CubeSize.x / sprite.getLocalBounds().width,
      CubeSize.y / sprite.getLocalBounds().height);
  window.draw(sprite);
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