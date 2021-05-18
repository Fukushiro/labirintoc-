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
    this->g = 0;
    this->b = 0;
}

void Bomba::mudarCor() {
    if (this->r == 255) {
        this->g = 255;
        this->r = 0;
    } else if (this->g == 255) {
        this->b = 255;
        this->g = 0;
    } else if (this->b == 255) {
        this->r = 255;
        this->b = 0;
    }
}

void Bomba::tick() {
    double tempoEmSeg = newTime / 1000;
    if (tempoEmSeg - tempoAtual >= coolDown) {
        mudarCor();
        tempoAtual = tempoEmSeg;
    }
}

void Bomba::draw() {
    squad(this->x, this->y, this->w, this->h, 1, 1, {this->r, this->g, this->b});
}

void Bomba::deletar() {
    delete this;
}