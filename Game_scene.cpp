#include "Game_scene.h"
#include <string>
#include <vector>
#include <iostream>

Game_scene::Game_scene(const int &width, const int &height, RenderWindow &window) {
  font.loadFromFile("Resources/rita.ttf");
  hearth_image.loadFromFile("Resources/Hearth.png");
  hearth_texture.loadFromImage(hearth_image);
  hearth_sprite.setTexture(hearth_texture);
  backgroundTexture.loadFromFile("Resources/backgroundGame.png");
  backgroundSprite.setTexture(backgroundTexture);
  SpaceForTop = 40;
  Startx = 1 + 2 * cubeSize, Starty = SpaceForTop + cubeSize + 1;
  lifes = 3;
  TimeForNewBlock = 0;
  score = 0;
  t = 0;
  T = 20; //уменьшается в процессе игры - сложность
  freqNewBlock = 3;
  scoreForHit = 15;
  scoreForStep = 1;
  blocks.Start = nullptr;
  player = MainPlayer({Startx, Starty}, Move::NOTHING);
  Widthc = 5, Heightc = 6;
  WField = 5, HField = 6;
  Width = Widthc * cubeSize + 2, Height = Heightc * cubeSize + SpaceForTop + 2;
}

void Game_scene::draw(RenderWindow &window, ll &time) {
  GetMove();
  window.setSize(Vector2u(Width, Height));
  backgroundSprite.setTexture(backgroundTexture);
  window.draw(backgroundSprite);
  DrawField(window);
  DrawPlayer(window);
  DrawBlocks(window);
  DrawGameStats(window);
  if (TimeForNewBlock == 3) {
    NewBlock();
    TimeForNewBlock = 0;
  }
  if (time > 1000000) {
    time = 0;
    TimeForNewBlock += 1;
    if (blocks.Start == nullptr)
      return;
    auto node = blocks.Start;
    while (node->next != nullptr) {
      node->data.Act({0, cubeSize});
      if (node->data.GetY() > Height) {
        if (blocks.Start == node) {
          auto node1 = node->next;
          delete node;
          blocks.Start = node1;
        } else {
          auto node1 = node->prev, node2 = node->next;
          delete node;
          node1->next = node2;
          node2->prev = node1;
        }
      }
      node = node->next;
    }

    node->data.Act({0, cubeSize});
    if (node->data.GetY() > Height) {
      if (blocks.Start == node) {
        auto node1 = node->next;
        delete node;
        blocks.Start = node1;
      } else {
        auto node1 = node->prev, node2 = node->next;
        delete node;
        node1->next = node2;
        node2->prev = node1;
      }
    }
  }
}

void Game_scene::keyRelease(Keyboard::Key &code) {
  switch (code) {
    case Keyboard::Q: {
      player.SetMove(Move::ROTATELEFT);
      break;
    }
    case Keyboard::E: {
      player.SetMove(Move::ROTATERIGHT);
      break;
    }
    case Keyboard::A: {
      player.SetMove(Move::LEFT);
      break;
    }
    case Keyboard::W: {
      player.SetMove(Move::UP);
      break;
    }
    case Keyboard::D: {
      player.SetMove(Move::RIGHT);
      break;
    }
    case Keyboard::S: {
      player.SetMove(Move::DOWN);
      break;
    }
    case Keyboard::F5: {
      NewBlock();
      break;
    }
    default: break;
  }
}

void Game_scene::DrawGameStats(RenderWindow &window) {
  if (lifes >= 1) {
    hearth_sprite.setTexture(hearth_texture);
    hearth_sprite.setPosition(13, 8);
    hearth_sprite.setScale(0.22, 0.22);
    window.draw(hearth_sprite);
  }
  if (lifes >= 2) {
    hearth_sprite.setTexture(hearth_texture);
    hearth_sprite.setPosition(43, 8);
    hearth_sprite.setScale(0.22, 0.22);
    window.draw(hearth_sprite);
  }
  if (lifes >= 3) {
    hearth_sprite.setTexture(hearth_texture);
    hearth_sprite.setPosition(73, 8);
    hearth_sprite.setScale(0.22, 0.22);
    window.draw(hearth_sprite);
  }
  if (lifes >= 4) {
    hearth_sprite.setTexture(hearth_texture);
    hearth_sprite.setPosition(103, 8);
    hearth_sprite.setScale(0.22, 0.22);
    window.draw(hearth_sprite);
  }
}

void Game_scene::GetMove() {
  player.DoMove(WField, HField, SpaceForTop);
}

void Game_scene::DrawField(RenderWindow &window) {
  Vertex line1[] = {
      sf::Vertex(sf::Vector2f(1.f, 0.f)),
      sf::Vertex(sf::Vector2f(1.f, HField * cubeSize + SpaceForTop + 2))
  };
  Vertex line2[] = {
      sf::Vertex(sf::Vector2f(WField * cubeSize + 2, 0.f)),
      sf::Vertex(sf::Vector2f(WField * cubeSize + 2, HField * cubeSize + SpaceForTop + 2))
  };
  Vertex line3[] = {
      sf::Vertex(sf::Vector2f(0.f, HField * cubeSize + SpaceForTop + 1)),
      sf::Vertex(sf::Vector2f(WField * cubeSize + 2, HField * cubeSize + SpaceForTop + 1))
  };
  Vertex line4[] = {
      sf::Vertex(sf::Vector2f(0.f, SpaceForTop)),
      sf::Vertex(sf::Vector2f(WField * cubeSize + 2, SpaceForTop))
  };
  line1[0].color = Color::Black;
  line1[1].color = Color::Black;//left right bot top
  line2[0].color = Color::Black;
  line2[1].color = Color::Black;
  line3[0].color = Color::Black;
  line3[1].color = Color::Black;
  line4[0].color = Color::Black;
  line4[1].color = Color::Black;

  window.draw(line1, 2, Lines);
  window.draw(line2, 2, Lines);
  window.draw(line3, 2, Lines);
  window.draw(line4, 2, Lines);
}

void Game_scene::DrawPlayer(RenderWindow &window) {
  player.Draw(window);
}

void Game_scene::DrawBlocks(RenderWindow &window) {
  if (blocks.Start == nullptr)
    return;
  auto node = blocks.Start;
  while (node->next != nullptr) {
    if (node->data.GetY() > SpaceForTop) {
      node->data.Draw(window);
    }
    node = node->next;
  }

  if (node->data.GetY() > SpaceForTop) {
    node->data.Draw(window);
  }

  for (const auto &it: player.GetPlayer()) {
    node = blocks.Start;
    while (node->next != nullptr) {
      if (IfContact(node->data, it))
        Contact(node, it);
      node = node->next;
    }
    if (IfContact(node->data, it))
      Contact(node, it);
  }
}

void Game_scene::NewBlock() {
  srand(time(nullptr));
  int x = rand() % WField;
  int type = rand() % 4;

  Node *new_node = new Node(static_cast<BlockType>(type), 1 + x * cubeSize);
  if (blocks.Start == nullptr) {
    blocks.Start = new_node;
  } else {
    auto node = blocks.Start;
    while (node->next != nullptr)
      node = node->next;
    node->next = new_node;
    new_node->prev = node;
  }
}

void Game_scene::Contact(Node *block, const BlockPlayer &quad) {
  if (quad.GetColor() == block->data.GetColor()) {
    score += scoreForHit;
  } else {
    --lifes;
  }
  if (blocks.Start == block) {
    auto node = block->next;
    delete block;
    blocks.Start = node;
  } else {
    auto node1 = block->prev, node2 = block->next;
    delete block;
    node1->next = node2;
    node2->prev = node1;
  }
}