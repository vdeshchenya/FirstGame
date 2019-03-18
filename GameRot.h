#pragma once
#include "MainPlayer.h"
#include "Block.h"

using std::deque;
using std::vector;
using std::string;

enum class Process{
  PAUSE,
  PLAYING
};

class {
 public:
  GLuint main_id;
  GLuint main_fon;

  GLuint main_game1;

 public:
  int main_LoadTexture(char *FileName, int i) {
    FILE *F;
    if ((F = fopen(FileName, "rb")) == NULL)
      return 0;
    fseek(F, 18, SEEK_SET);
    fread(&(main_textura.W), 2, 1, F);
    fseek(F, 2, SEEK_CUR);
    fread(&(main_textura.H), 2, 1, F);

    if ((main_textura.Image = (unsigned char *) malloc(sizeof(unsigned char) * 3 * main_textura.W * main_textura.H)) == NULL) {
      fclose(F);
      return 0;
    }
    fseek(F, 30, SEEK_CUR);
    fread(main_textura.Image, 3, main_textura.W * main_textura.H, F);

    glGenTextures(1, &main_id);
    glBindTexture(GL_TEXTURE_2D, main_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gluBuild2DMipmaps(GL_TEXTURE_2D,
                      3,
                      main_textura.W,
                      main_textura.H, /*GL_BGR_EXT*/
                      GL_RGB,
                      GL_UNSIGNED_BYTE,
                      main_textura.Image);
    free(main_textura.Image);
    fclose(F);

    switch (i) {
      case 1:main_fon = main_id;
        break;
      default:break;

    }
    return 1;
  }
 private:
  struct textura_struct {
    int W;
    int H;
    unsigned char *Image;
  } main_textura;

} clas_main_textur;

class Game {
 public:
  Game() = default;
  void Init();
  void Reshape(const int &w, const int &h);
  void Keyboard(unsigned char key, int x, int y);
  void Idle();
  int GetWidth();
  int GetHeight();
 private:
  MainPlayer player;
  int score;
  int lifes;
  unsigned long long int t;

  int Widthc, Heightc;
  int Width, Height;
  int WField, HField;
  int Startx, Starty;
  int T;
  int freqNewBlock;
  int scoreForHit;
  int scoreForStep;

  Process proc;
  deque<Block> blocks;

  void DrawGameStats();
  void DrawPlayer();
  void DrawField();
  void DrawBlocks();
  void GetMove();
  void NewBlock();
  void Contact(Block& block, const Quad& quad);
};

void RenderString(const int& x, const int& y, void *font, const string &string, RGB const &rgb);

void ScoreText(const int& x, const int& y, void *font, RGB const &rgb);

void GameOverText(const int& x, const int& y, void *font, RGB const &rgb);

void DrawHeart(const int &x_, const int& y_);