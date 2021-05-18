#define GLUT_DISABLE_ATEXIT_HACK
#ifndef PAREDE_H
#define PAREDE_H
#include <windows.h>
#include <GL/glut.h>
#include "Mascara.h"

class Parede {
   public:
    double x;
    double y;
    double scaleX;
    double scaleY;
    Mascara col;
    int colidable;
    Parede();
    virtual ~Parede();
    Parede(double x, double y, double scaleX, double scaleY, int colidable);
    void draw();

   protected:
   private:
};

#endif  // PAREDE_H
