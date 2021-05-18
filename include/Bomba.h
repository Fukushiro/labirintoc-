#define GLUT_DISABLE_ATEXIT_HACK
#ifndef BOMBA_H
#define BOMBA_H
//imports
#include <windows.h>
#include <GL/glut.h>
#include <array>
class Mascara;
class Bomba {
   public:
    double x;
    double y;
    double w;
    double h;
    Mascara* col;
    double tempoAtual;
    double tempoNecessario;
    double coolDown;
    unsigned int r, g, b;
    Bomba();
    virtual ~Bomba();
    Bomba(double x, double y, double w, double h);
    void mudarCor();
    void tick();
    void draw();
    void deletar();

   protected:
   private:
};

#endif  // BOMBA_H
