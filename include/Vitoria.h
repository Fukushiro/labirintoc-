#define GLUT_DISABLE_ATEXIT_HACK
#ifndef VITORIA_H
#define VITORIA_H
#include <windows.h>
#include <GL/glut.h>
#include "Mascara.h"
#include <array>
#include <iostream>
class Vitoria {
   public:
    double botaoX;
    double botaoY;
    double botaoW;
    double botaoH;
    Vitoria();
    virtual ~Vitoria();
    void mouse(int button, int state, int x, int y);
    void tick();
    void draw();

   protected:
   private:
};

#endif  // VITORIA_H
