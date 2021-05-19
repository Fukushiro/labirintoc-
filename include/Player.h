#define GLUT_DISABLE_ATEXIT_HACK
#ifndef PLAYER_H
#define PLAYER_H
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include "Bomba.h"
#include "Score.h"
#include "Mundo.h"
#include "Enemy.h"
class Player {
   public:
    /*
            0=parado
            1=mover
        */
    int state;
    /*
            0=parado
            1=direita
            2=esquerda
        */
    int horizontal;
    /*
            0=parado
            1=cima
            2=baixo
        */
    int vertical;
    double x;
    double y;
    double w;
    double h;
    double speed;
    Mascara m1;
    std::list<Bomba*>::iterator i;
    std::list<Enemy*>::iterator iEnemy;
    Score* score;
    Mundo* mundo;
    Player();
    virtual ~Player();
    Player(double x, double y, double w, double h, Score* score, Mundo* mundo);
    int colBomba();
    int colEnemy();
    int col(int direction, double speed);
    void Move();
    void tick();
    void draw();
    void key(unsigned char key, int x, int y);
    void keyUp(unsigned char key, int x, int y);

   protected:
   private:
};

#endif  // PLAYER_H
