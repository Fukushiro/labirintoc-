#define GLUT_DISABLE_ATEXIT_HACK
#ifndef ENEMY_H
#define ENEMY_H
#include <windows.h>
#include <GL/glut.h>
#include "Mascara.h"
#include "Mundo.h"
class Enemy {
   public:
    int state;
    double x;
    double y;
    double w;
    double h;
    double speed;
    Mascara col;
    int horizontal;
    Mundo* mundo;
    Enemy();
    virtual ~Enemy();
    Enemy(double x, double y, double w, double h, int horizontal, Mundo* mundo);
    int colCheck(int direction, double speed);
    void Move();
    void tick();
    void draw();

   protected:
   private:
};

#endif  // ENEMY_H
