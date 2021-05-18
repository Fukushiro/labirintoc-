#ifndef MUNDO_H
#define MUNDO_H
#include <list>
#include <vector>
#include <iostream>
#include "Parede.h"
#include "Score.h"
#include "Pos.h"
class Enemy;
class Mundo {
   public:
    double w;
    double h;
    int numeroBombas = 2;
    std::list<Parede> lista;
    std::list<Parede>::iterator it;

    std::list<Enemy*> inimigos;
    std::list<Enemy*>::iterator itEnemy;

    std::vector<Pos*> posicoesBombas;
    std::vector<Pos*>::iterator posicoesBombasIterator;
    Score* score;
    /*
        6=local inicial do player
        0=vazio
        1=parede
        2=parede sem colisão
        4=inimigoHorizontal
        5 = inimigoVertical
        */
    int mundo[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 2, 1, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                         {0, 0, 0, 0, 0, 3, 3, 0, 0, 0},
                         {0, 0, 0, 6, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0, 5, 0, 1, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}};

    int mundo2[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                          {1, 0, 3, 1, 1, 1, 1, 1, 1, 1},
                          {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                          {1, 0, 0, 0, 3, 3, 0, 3, 0, 0},
                          {6, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                          {0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                          {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    int mundo3[10][10] = {{5, 1, 1, 1, 6, 1, 0, 4, 0, 5},
                          {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
                          {0, 0, 0, 0, 4, 0, 0, 1, 0, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    Mundo();
    virtual ~Mundo();
    Mundo(double w, double h, int numeroBombas, Score* score);

    int col(Mascara m2, int direction, double speed);
    void draw();
    void tick();

   protected:
   private:
};

#endif  // MUNDO_H
