#include "Mascara.h"
enum Direcao {
    Right,
    Left,
    Top,
    Down
};
//prototipo da funcao de desenhar quadrado
void squad(int x, int y, int w, int h, double scaleX, double scaleY, const std::array<unsigned int, 3> valor);

Mascara::Mascara() {
    //ctor
}
//construtor que inicia o objeto com a cordenada
Mascara::Mascara(double x, double y, double w, double h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}
//Altera o valor das cordenadas caso o objeto tenha que ser iniciado sem valor inicial
void Mascara::start(double x, double y, double w, double h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}
//funcao para desenhar mascara
void Mascara::draw() {
    squad(this->x, this->y, this->w, this->h, 1, 1, {0, 255, 0});
}
//atualiza a posicao da mascara
void Mascara::atualizarPos(double x, double y) {
    this->x = x;
    this->y = y;
}
//funcao para checar se um ponto esta dentro da mascara m2
int Mascara::pointInside(double x, double y, Mascara m2) {
    if ((x > m2.x) && (x < m2.x + m2.w)) {
        if (((y > m2.y - m2.h) && (y < m2.y))) {
            return true;
        }
    }
    return false;
}
//detecta colisao com outra mascara passada por parametro
int Mascara::col(Mascara m2, int direction, double speed) {
    /*
                0=direita
                1=esquerda
                2=cima
                3=baixo
            */

    if (direction == Direcao::Right) {
        if (this->pointInside(this->x + this->w + speed, this->y, m2) ||
            this->pointInside(this->x + this->w + speed, this->y - this->h, m2) ||
            this->pointInside(this->x + this->w + speed, this->y - (this->h / 2), m2)) {
            return true;
        }
    } else if (direction == Direcao::Left) {
        if (this->pointInside(this->x - speed, this->y, m2) ||
            this->pointInside(this->x - speed, this->y - this->h, m2) ||
            this->pointInside(this->x - speed, this->y - (this->h / 2), m2)) {
            return true;
        }
    } else if (direction == Direcao::Top) {
        if (this->pointInside(this->x, this->y + speed, m2) ||
            this->pointInside(this->x + this->w, this->y + speed, m2) ||
            this->pointInside(this->x + (this->w / 2), this->y + speed, m2)) {
            return true;
        }
    } else if (direction == Direcao::Down) {
        if (this->pointInside(this->x, this->y - this->w - speed, m2) ||
            this->pointInside(this->x + this->w, this->y - this->w - speed, m2) ||
            this->pointInside(this->x + (this->w / 2), this->y - this->w - speed, m2)) {
            return true;
        }
    } else if (direction == -1) {
        if (this->pointInside(this->x, this->y, m2) ||
            this->pointInside(this->x + this->w, this->y, m2) ||
            this->pointInside(this->x, this->y - this->h, m2) ||
            this->pointInside(this->x + this->w, this->y - this->h, m2) ||
            this->pointInside(this->x + (this->w / 2), this->y, m2) ||
            this->pointInside(this->x, this->y - (this->h / 2), m2) ||
            this->pointInside(this->x + this->w, this->y - (this->h / 2), m2) ||
            this->pointInside(this->x + (this->w / 2), this->y - this->h, m2)) {
            return true;
        }
    }

    return false;
}