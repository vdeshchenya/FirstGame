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

BlockPlayer::BlockPlayer(const Point &point, const MainBlockType &type_) : Quad(point, type_to_color(type_)),
                                                                           type(type_) {
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
};

Color BlockPlayer::type_to_color(const MainBlockType &type) const {
  switch (type) {
    case MainBlockType::White:return Color::White;
    case MainBlockType::Blue:return Color::Blue;
    case MainBlockType::Green :return Color::Green;
    case MainBlockType::Red:return Color::Red;
    case MainBlockType::Yellow:return Color::Yellow;
  }
}