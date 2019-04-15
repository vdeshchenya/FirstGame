#include "Block.h"

int SpaceForTop = 30;
int NewBlockY = -9 * cubeSize + SpaceForTop + 1;

Block::Block(const BlockType &type_, const int &x) : Quad({x, NewBlockY}), type(type_) {
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
      image.loadFromFile("Textures/purple.png");
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

void Block::SetType(const BlockType &type_) {
  type = type_;
}

BlockType Block::GetType() {
  return type;
}