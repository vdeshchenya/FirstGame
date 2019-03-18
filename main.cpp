#include "GameRot.h"
Game game;

void Reshape(int w, int h) {
  game.Reshape(w, h);
}

void Keyboard(unsigned char key, int x, int y) {
  game.Keyboard(key, x, y);
}

void Idle() {
  game.Idle();
}

void Timer(int value) {
  glutPostRedisplay(); // Redraw windows
  glutTimerFunc(100, Timer, 0); // Setup next timer
}

int main(int argc, char **argv) {
  game.Init();

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(game.GetWidth(), game.GetHeight());
  glutCreateWindow("Help!");

  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 600, 0, 450);

  glutDisplayFunc(Idle);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);

  glutTimerFunc(40, Timer, 0);

  glutMainLoop();
  return 0;
}