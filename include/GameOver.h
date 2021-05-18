#define GLUT_DISABLE_ATEXIT_HACK
#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <windows.h>
#include <GL/glut.h>
#include "Mascara.h"
#include <array>
#include <iostream>
class GameOver {
   public:
    double botaoX;
    double botaoY;
    double botaoW;
    double botaoH;
    GameOver();
    virtual ~GameOver();
    void tick();
    void draw();
    void mouse(int button, int state, int x, int y);

   protected:
   private:
};

#endif  // GAMEOVER_H
