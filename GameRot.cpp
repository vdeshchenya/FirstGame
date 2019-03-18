#include "GameRot.h"

//Game
void Game::Init() {
  Startx = 1 + 2 * cubeSize, Starty = 2 * cubeSize;
  lifes = 3;
  score = 0;
  t = 0;
  T = 20; //уменьшается в процессе игры - сложность
  freqNewBlock = 3;
  proc = Process::PAUSE;
  scoreForHit = 15;
  scoreForStep = 1;
  blocks.clear();
  player = MainPlayer({Startx, Starty}, Move::NOTHING);
  Widthc = 5, Heightc = 11;
  WField = 5, HField = 11;
  Width = Widthc * cubeSize + 2, Height = Heightc * cubeSize + 31;
}

void Game::Reshape(const int &w, const int &h) {
  Width = w;
  Height = h;

  if (clas_main_textur.main_LoadTexture((char *) "font.bmp", 1) != 1) { std::cout << "font erorr \n"; };
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, w, 0, h, -1, 1);
}

void Game::Keyboard(unsigned char key, int x, int y) {
#define ESCAPE '\033'
#define Q '\121'
#define q '\161'
#define E '\105'
#define e '\145'
#define A '\101'
#define a '\141'
#define W '\127'
#define w '\167'
#define D '\104'
#define d '\144'
#define S '\123'
#define s '\163'
#define Space '\040'
  switch (key) {
    case ESCAPE: {
      exit(0);
    }
    case Q: {
      player.SetMove(Move::ROTATELEFT);
      break;
    }
    case q: {
      player.SetMove(Move::ROTATELEFT);
      break;
    }
    case E: {
      player.SetMove(Move::ROTATERIGHT);
      break;
    }
    case e: {
      player.SetMove(Move::ROTATERIGHT);
      break;
    }
    case A: {
      player.SetMove(Move::LEFT);
      break;
    }
    case a: {
      player.SetMove(Move::LEFT);
      break;
    }
    case W: {
      player.SetMove(Move::UP);
      break;
    }
    case w: {
      player.SetMove(Move::UP);
      break;
    }
    case D: {
      player.SetMove(Move::RIGHT);
      break;
    }
    case d: {
      player.SetMove(Move::RIGHT);
      break;
    }
    case S: {
      player.SetMove(Move::DOWN);
      break;
    }
    case s: {
      player.SetMove(Move::DOWN);
      break;
    }
    case Space: {
      if (proc == Process::PAUSE)
        proc = Process::PLAYING;
      else
        proc = Process::PAUSE;
    }
    default: break;
  }
}

void Game::Idle() {
  // очистка буфера цвета и глубины
  glClear(GL_COLOR_BUFFER_BIT);
  // обнуление трансформации
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, Width, 0, Height, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  if (proc == Process::PLAYING) {
    if (lifes == 0) {
      for (auto &it : blocks) {
        it.SetColor({0, 0, 0});
      }
      proc = Process::PAUSE;
      DrawField();
      GameOverText((Width - 110) / 2, HField * cubeSize / 2, GLUT_BITMAP_TIMES_ROMAN_24, RGB(255, 255, 255));
      RenderString((Width - 110) / 2 - 15,
                   HField * cubeSize / 2 - 32,
                   GLUT_BITMAP_TIMES_ROMAN_24,
                   "Your",
                   RGB(255, 255, 255));
      ScoreText((Width - 110) / 2 + 45, HField * cubeSize / 2 - 32, GLUT_BITMAP_TIMES_ROMAN_24, RGB(255, 255, 255));
      RenderString(110 + (Width - 110) / 2,
                   HField * cubeSize / 2 - 32,
                   GLUT_BITMAP_TIMES_ROMAN_24,
                   std::to_string(score),
                   RGB(255, 255, 255));
    }

    DrawField();
    DrawPlayer();
    DrawGameStats();
    DrawBlocks();

    if (lifes == 0) {
      for (auto &it : blocks) {
        it.SetType(BlockType::Black);
      }
      proc = Process::PAUSE;
      DrawField();
      GameOverText((Width - 110) / 2, HField * cubeSize / 2, GLUT_BITMAP_TIMES_ROMAN_24, RGB(255, 255, 255));
      RenderString((Width - 110) / 2 - 15,
                   HField * cubeSize / 2 - 32,
                   GLUT_BITMAP_TIMES_ROMAN_24,
                   "Your",
                   RGB(255, 255, 255));
      ScoreText((Width - 110) / 2 + 45, HField * cubeSize / 2 - 32, GLUT_BITMAP_TIMES_ROMAN_24, RGB(255, 255, 255));
      RenderString(110 + (Width - 110) / 2,
                   HField * cubeSize / 2 - 32,
                   GLUT_BITMAP_TIMES_ROMAN_24,
                   std::to_string(score),
                   RGB(255, 255, 255));
    }

    glutSwapBuffers();

    GetMove();
    NewBlock();

    if (!(t % T)) {
      score += scoreForStep;
    }

    if (!(t % (100 * T))) {
      --T;
      t = 1;
    }
    ++t;
  }
}

int Game::GetWidth() { return Width; }

int Game::GetHeight() { return Height; }

void Game::DrawGameStats() {
  ScoreText(1 + Width - 140, Height - 24, GLUT_BITMAP_TIMES_ROMAN_24, RGB(255, 255, 255));
  RenderString(1 + Width - 75, Height - 24, GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(score), RGB(255, 255, 255));
  if (lifes > 0)
    DrawHeart(20, Height - 20);
  if (lifes > 1)
    DrawHeart(50, Height - 20);
  if (lifes > 2)
    DrawHeart(80, Height - 20);
  if (lifes > 3)
    DrawHeart(110, Height - 20);
}

void Game::GetMove() {
  player.DoMove(WField, HField);
}

void Game::DrawField() {
  /*glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, clas_main_textur.main_fon);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex2i(0, 0);

  glTexCoord2f(1.0, 0.0);
  glVertex2i(Width, 0);

  glTexCoord2f(1.0, 1.0);
  glVertex2i(Width, Height);

  glTexCoord2f(0.0, 1.0);
  glVertex2i(0, Height);
  glEnd();
  glDisable(GL_TEXTURE_2D);*/

  glBegin(GL_QUADS);
  glColor3ub(0,0,0);
  glVertex2i(0, 0);

  glVertex2i(Width, 0);

  glVertex2i(Width, Height);

  glVertex2i(0, Height);
  glEnd();

  glBegin(GL_LINES);
  glColor3ub(255, 255, 255);
  glVertex2i(1, 0);
  glVertex2i(1, HField * cubeSize);
  glColor3ub(255, 255, 255);
  glVertex2i(WField * cubeSize + 2, 0);
  glVertex2i(WField * cubeSize + 2, HField * cubeSize);
  glColor3ub(255, 255, 255);
  glVertex2i(0, HField * cubeSize + 1);
  glVertex2i(WField * cubeSize + 2, HField * cubeSize + 1);
  glEnd();
}

void Game::DrawPlayer() {
  player.Draw();
}

void Game::DrawBlocks() {
  glBegin(GL_QUADS);
  for (auto it: blocks) {
    if (it.GetY() < HField * cubeSize)
      it.Draw();
  }
  glEnd();

  if (!(t % T)) {
    for (auto &it: blocks) {
      it.Act({0, -cubeSize});
      if (it.GetY() < 0)
        blocks.pop_front();
    }
  }

  for (const auto &it: player.GetPlayer()) {
    if (IfContact(blocks[0], it)) {
      Contact(blocks[0], it);
    }
  }
}

void Game::NewBlock() {
  if (!(t % (freqNewBlock * T))) {
    srand(time(nullptr));
    int x = rand() % WField;
    int type = rand() % 4;   //Types
    blocks.push_back(Block(static_cast<BlockType>(type), 1 + x * cubeSize));
  }
}

void Game::Contact(Block &block, const Quad &quad) {
  if (quad.GetColor() == block.GetColor()) {
    score += scoreForHit;
  } else {
    --lifes;
  }
  block.SetColor({0, 0, 0});
  blocks.pop_front();
}

//Other
void RenderString(const int &x, const int &y, void *font, const string &string, RGB const &rgb) {
  for (int i = 0; i < string.size(); ++i) {
    int c = string[i];
    glColor3ub(rgb.r, rgb.g, rgb.b);
    glRasterPos2f(x + 13 * i, y);
    glutBitmapCharacter(font, c);
  }
};

void ScoreText(const int &x, const int &y, void *font, RGB const &rgb) {
  string text = "Score:";
  int c = text[0];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x, y);
  glutBitmapCharacter(font, c);
  c = text[1];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 13, y);
  glutBitmapCharacter(font, c);
  c = text[2];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 12 * 2, y);
  glutBitmapCharacter(font, c);
  c = text[3];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 12 * 3, y);
  glutBitmapCharacter(font, c);
  c = text[4];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 12 * 4 - 3, y);
  glutBitmapCharacter(font, c);
  c = text[5];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 12 * 5 - 3, y);
  glutBitmapCharacter(font, c);
}

void GameOverText(const int &x, const int &y, void *font, RGB const &rgb) {
  string text = "Game over!";
  int c = text[0];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x, y);
  glutBitmapCharacter(font, c);
  c = text[1];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 15, y);
  glutBitmapCharacter(font, c);
  c = text[2];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 26, y);
  glutBitmapCharacter(font, c);
  c = text[3];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 45, y);
  glutBitmapCharacter(font, c);
  c = text[4];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 60, y);
  glutBitmapCharacter(font, c);
  c = text[5];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 65, y);
  glutBitmapCharacter(font, c);
  c = text[6];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 75, y);
  glutBitmapCharacter(font, c);
  c = text[7];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 85, y);
  glutBitmapCharacter(font, c);
  c = text[8];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 95, y);
  glutBitmapCharacter(font, c);
  c = text[9];
  glColor3ub(rgb.r, rgb.g, rgb.b);
  glRasterPos2f(x + 103, y);
  glutBitmapCharacter(font, c);
}

void DrawHeart(const int &x_, const int &y_) {
  glBegin(GL_POINTS);
  for (int x = -114; x <= 114; ++x) {
    glPointSize(1);
    double X2 = static_cast<float>(x * x) / 10000;
    float delta = static_cast<float>(cbrt(X2) * cbrt(X2) - 4 * X2 + 4);
    float y1 = static_cast<float>(cbrt(X2) - sqrt(delta)) / 2;
    float y2 = static_cast<float>(cbrt(X2) + sqrt(delta)) / 2;
    glColor3ub(255, 0, 0);
    for (int y = y1 * 10 + y_; y <= y2 * 10 + y_; ++y)
      glVertex2f(x_ + x / 10, y);
  }
  glEnd();
}