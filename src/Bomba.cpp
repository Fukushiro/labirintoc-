#include "Bomba.h"
#include "Mascara.h"
extern int newTime;
void squad(int x, int y, int w, int h, double scaleX, double scaleY, const std::array<unsigned int, 3> valor);

Bomba::Bomba() {
    //ctor
}

Bomba::~Bomba() {
    //dtor
}

Bomba::Bomba(double x, double y, double w, double h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->col = new Mascara(x, y, w, h);
    this->tempoAtual = 0;
    this->coolDown = 1;
    this->r = 255;
    this->g = 102;
    this->b = 0;
}
//muda a cor da bomba
void Bomba::mudarCor() {
    if (this->r == 255 && this->g == 102 && this->b == 0) {
        this->g = 92;
        this->r = 230;
        this->b = 0;
    } else if (this->r == 230 && this->g == 92 && this->b == 0) {
         this->r = 179;
        this->g = 71;
        this->b = 0;
    } else if (this->r == 179 && this->g == 71 && this->b == 0) {
        this->r = 255;
        this->g = 102;
        this->b = 0;
    }
}
//logica executada a cada tick
void Bomba::tick() {
    double tempoEmSeg = newTime / 1000;
    if (tempoEmSeg - tempoAtual >= coolDown) {
        mudarCor();
        tempoAtual = tempoEmSeg;
    }
}
//funcao para desenhar a bomba
void Bomba::draw() {
    squad(this->x, this->y, this->w, this->h, 1, 1, {this->r, this->g, this->b});
}
//remover a bomba
void Bomba::deletar() {
    delete this;
}
