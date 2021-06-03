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
//incrementa o numero de pontos que o player obteve e checa se o player ganhou
void Score::addPonto() {
    this->pontos++;
    if (this->pontos >= this->maxPontos) {
        vencer();
    }
}
//adiciona nova bomba no mapa
void Score::addBomba(double x, double y, double w, double h) {
    this->bombas.push_front(new Bomba(x, y, w, h));
    this->maxPontos++;
}
//roda a logica das bombas
void Score::tickBombas() {
    for (it = this->bombas.begin(); it != this->bombas.end(); it++) {
        (*it)->tick();
    }
}
//roda a logica do score
void Score::tick() {
    this->tickBombas();
}
//desenha bombas da lista
void Score::drawBombas() {
    for (it = this->bombas.begin(); it != this->bombas.end(); it++) {
        (*it)->draw();
    }
}
//desenha a pontuacao atual e maxima do player
void Score::drawPontuacao() {
    //RenderString
    char str[50] = "Pontuacao: ";

    sprintf(str, "%s %i/%i", str, this->pontos, this->maxPontos);
    RenderString(320, 470, GLUT_BITMAP_TIMES_ROMAN_24, str, {0, 255, 0});
}
//desenha na tela o tempo que passou des de o começo da fase
void Score::drawTimer() {
    char str[50] = "Tempo: ";

    sprintf(str, "%s %i", str, ((newTime - comeco) / 1000));
    RenderString(320, 450, GLUT_BITMAP_TIMES_ROMAN_24, str, {0, 255, 0});
}
//desenha tudo do score
void Score::draw() {
    this->drawBombas();
    this->drawPontuacao();
    this->drawTimer();
}
