#include "Vitoria.h"
void RenderString(float x, float y, void* font, char* string, const std::array<unsigned int, 3> valor);
void squad(int x, int y, int w, int h, double scaleX, double scaleY, const std::array<unsigned int, 3> valor);
extern int tempoUsado;
extern int pontuacao;
extern int pontuacaoMaxima;
void resetar();
Vitoria::Vitoria() {
    //ctor
    this->botaoX = 195;
    this->botaoY = 180;
    this->botaoW = 120;
    this->botaoH = 50;
}

Vitoria::~Vitoria() {
    //dtor
}
void Vitoria::tick() {
}
void Vitoria::draw() {
    //RenderString(220, 300, GLUT_BITMAP_TIMES_ROMAN_24, "Vitoria", {0, 255, 0});
    RenderString(220, 300, GLUT_BITMAP_TIMES_ROMAN_24, "Vitoria", {0, 255, 0});
    squad(this->botaoX, this->botaoY, this->botaoW, this->botaoH, 1, 1, {0, 0, 255});
    RenderString(this->botaoX + 7, this->botaoY - 30, GLUT_BITMAP_TIMES_ROMAN_24, "Recomecar", {255, 0, 0});

    char str[50] = "Tempo gasto: ";

    sprintf(str, "%s %i", str, (tempoUsado / 1000));
    RenderString(185, 260, GLUT_BITMAP_TIMES_ROMAN_24, str, {255, 0, 0});

    char str2[50] = "Bombas coletadas: ";

    sprintf(str2, "%s %i/%i", str2, pontuacao, pontuacaoMaxima);
    RenderString(140, 220, GLUT_BITMAP_TIMES_ROMAN_24, str2, {255, 0, 0});
}

void Vitoria::mouse(int button, int state, int x, int y) {
    Mascara m(this->botaoX, this->botaoY, this->botaoW, this->botaoH);
    y = 500 - y;

    if (GLUT_LEFT_BUTTON == button && GLUT_DOWN == state) {
        if (m.pointInside(x, y, m)) {
            resetar();
        }
    }
}