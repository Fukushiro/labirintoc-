#define GLUT_DISABLE_ATEXIT_HACK
#ifndef SCORE_H
#define SCORE_H
#include <windows.h>
#include <GL/glut.h>
#include "Bomba.h"

#include <string.h>
#include <list>
class Score {
   public:
    int pontos;
    int maxPontos;
    std::list<Bomba*> bombas;
    std::list<Bomba*>::iterator it;
    Score();
    virtual ~Score();
    void addPonto();
    void addBomba(double x, double y, double w, double h);
    void tickBombas();
    void tick();
    void drawBombas();
    void drawPontuacao();
    void drawTimer();
    void draw();

   protected:
   private:
};

#endif  // SCORE_H
