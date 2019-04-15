#include "BlockPlayer.h"

std::map<MainBlockType, Texture> textures;

void BlockPlayer::Draw(RenderWindow &window) {
  sprite.setTexture(textures[type]);
  sprite.setPosition(GetLB().x, GetLB().y);
  sprite.setScale(
      CubeSize.x / sprite.getLocalBounds().width,
      CubeSize.y / sprite.getLocalBounds().height);
  window.draw(sprite);
}

BlockPlayer::BlockPlayer(const Point &point, const MainBlockType &type_) : Quad(point),
                                                                           type(type_) {};

void BlockPlayer::Init() {
  image.loadFromFile("Textures/green.png");
  texture.loadFromImage(image);
  textures[MainBlockType::Green] = texture;

  image.loadFromFile("Textures/red.png");
  texture.loadFromImage(image);
  textures[MainBlockType::Red] = texture;

  image.loadFromFile("Textures/blue.png");
  texture.loadFromImage(image);
  textures[MainBlockType::Blue] = texture;

  image.loadFromFile("Textures/yellow.png");
  texture.loadFromImage(image);
  textures[MainBlockType::Yellow] = texture;

  image.loadFromFile("Textures/white.png");
  texture.loadFromImage(image);
  textures[MainBlockType::White] = texture;
}

void BlockPlayer::SetType(const MainBlockType &type_) {
  type = type_;
}

MainBlockType BlockPlayer::GetType() const {
  return type;
}