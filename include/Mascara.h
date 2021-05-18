#define GLUT_DISABLE_ATEXIT_HACK
#ifndef MASCARA_H
#define MASCARA_H

#include <windows.h>
#include <GL/glut.h>

#include <array>

class Mascara {
   public:
    double x;
    double y;
    double w;
    double h;
    Mascara();
    Mascara(double x, double y, double w, double h);
    void start(double x, double y, double w, double h);
    void draw();
    void atualizarPos(double x, double y);
    int pointInside(double x, double y, Mascara m2);
    int col(Mascara m2, int direction, double speed);

   protected:
   private:
};

#endif  // MASCARA_H
