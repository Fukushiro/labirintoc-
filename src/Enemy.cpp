#include "Enemy.h"
#include "Mundo.h"
#include <stdlib.h>
#include <time.h>
#include "Game.h"
extern Game* game;
void squad(int x, int y, int w, int h, double scaleX, double scaleY, const std::array<unsigned int, 3> valor);
enum Direcao {
    Right,
    Left,
    Top,
    Down
};
Enemy::Enemy() {
    //ctor
}

Enemy::~Enemy() {
    //dtor
}

Enemy::Enemy(double x, double y, double w, double h, int horizontal, Mundo* mundo) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->speed = 2;
    this->col.start(this->x, this->y, this->w, this->h);
    this->horizontal = horizontal;
    this->mundo = mundo;
    if (horizontal) {
        this->state = Direcao::Left;
    } else {
        this->state = Direcao::Top;
    }
}
int Enemy::colCheck(int direction, double speed) {
    if (this->mundo->col(this->col, direction, speed)) {
        return true;
    }

    if (this->col.x - speed < 0 && direction == 1 || this->col.x + this->col.w + speed > 500 && direction == 0 ||
        (this->col.y + speed > 500 && direction == 2) || (this->col.y - this->h - speed < 0 && direction == 3)) {
        return true;
    }

    return false;
}

void Enemy::trocarSentido() {
    srand(time(NULL));
    if (horizontal) {
        horizontal = false;
        if (game->p1->y > this->y) {
            this->state = Direcao::Top;
            if (this->colCheck(Direcao::Top, this->speed)) {
                this->state = Direcao::Down;
            }
        } else {
            this->state = Direcao::Down;
            if (this->colCheck(Direcao::Down, this->speed)) {
                this->state = Direcao::Top;
            }
        }

    } else {
        horizontal = true;
        if (game->p1->x > this->x) {
            this->state = Direcao::Right;
            if (this->colCheck(Direcao::Right, this->speed)) {
                this->state = Direcao::Left;
            }
        } else {
            this->state = Direcao::Left;
            if (this->colCheck(Direcao::Left, this->speed)) {
                this->state = Direcao::Right;
            }
        }
    }
}

void Enemy::Move() {
    std::cout << "Direcao:" << this->state << "Horizontal:" << this->horizontal << std::endl;
    if (horizontal) {
        if (state == Direcao::Right && !this->colCheck(Direcao::Right, this->speed)) {
            this->x += this->speed;
        } else if (state == Direcao::Right) {
            this->trocarSentido();
            if (state == Direcao::Right)

                this->state = Direcao::Left;
        }

        if (state == Direcao::Left && !this->colCheck(Direcao::Left, this->speed)) {
            this->x -= this->speed;
        } else if (state == Direcao::Left) {
            this->trocarSentido();
            if (state == Direcao::Left)
                this->state = Direcao::Right;
        }
    } else {
        if (state == Direcao::Top && !this->colCheck(Direcao::Top, this->speed)) {
            this->y += this->speed;
        } else if (state == Direcao::Top) {
            this->trocarSentido();
            if (state == Direcao::Top)
                this->state = Direcao::Down;
        }

        if (state == Direcao::Down && !this->colCheck(Direcao::Down, this->speed)) {
            this->y -= this->speed;
        } else if (state == Direcao::Down) {
            this->trocarSentido();
            if (state == Direcao::Down)
                this->state = Direcao::Top;
        }
    }

    col.atualizarPos(this->x, this->y);
}

void Enemy::tick() {
    this->Move();
}

void Enemy::draw() {
    squad(this->x, this->y, this->w, this->h, 1, 1, {255, 0, 0});
}
