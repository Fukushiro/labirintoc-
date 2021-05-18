#include "Score.h"
void RenderString(float x, float y, void* font, char* string, const std::array<unsigned int, 3> valor);
void vencer();
void perder();
extern int comeco;
extern int newTime;
extern int tempoUsado;
extern int deltaTime;
Score::Score() {
    //ctor
    this->pontos = 0;
    this->maxPontos = 0;
}

Score::~Score() {
    //dtor
}

void Score::addPonto() {
    this->pontos++;
    if (this->pontos >= this->maxPontos) {
        vencer();
    }
}

void Score::addBomba(double x, double y, double w, double h) {
    this->bombas.push_front(new Bomba(x, y, w, h));
    this->maxPontos++;
}

void Score::tickBombas() {
    for (it = this->bombas.begin(); it != this->bombas.end(); it++) {
        (*it)->tick();
    }
}

void Score::tick() {
    this->tickBombas();
}

void Score::drawBombas() {
    for (it = this->bombas.begin(); it != this->bombas.end(); it++) {
        (*it)->draw();
    }
}

void Score::drawPontuacao() {
    //RenderString
    char str[50] = "Pontuacao: ";

    sprintf(str, "%s %i/%i", str, this->pontos, this->maxPontos);
    RenderString(320, 470, GLUT_BITMAP_TIMES_ROMAN_24, str, {0, 255, 0});
}

void Score::drawTimer() {
    char str[50] = "Tempo: ";

    sprintf(str, "%s %i", str, ((newTime - comeco) / 1000));
    RenderString(320, 450, GLUT_BITMAP_TIMES_ROMAN_24, str, {0, 255, 0});
}

void Score::draw() {
    this->drawBombas();
    this->drawPontuacao();
    this->drawTimer();
}
