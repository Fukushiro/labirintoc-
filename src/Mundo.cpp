#include "Mundo.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
const int width = 20;
const int height = 20;
extern double place[2];
void copiarMatriz(int matriz[height][width], int matrizCopiada[height][width]) {
    int x, y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            matriz[y][x] = matrizCopiada[y][x];
        }
    }
}
enum Direcao {
    Right,
    Left,
    Top,
    Down
};

Mundo::Mundo() {
    //ctor
}

Mundo::~Mundo() {
    //dtor
}

Mundo::Mundo(double w, double h, int numeroBombas, Score* score) {
    int x, y;
    this->w = w;
    this->h = h;
    copiarMatriz(this->mundo, this->mundo2);
    this->score = score;
    this->numeroBombas = numeroBombas;

    double tileSizeX = 500 / width;
    double tileSizeY = 500 / height;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (mundo[y][x] == 1) {
                this->lista.push_front(Parede(x * tileSizeX, 500 - (tileSizeY * y), tileSizeX / 10, tileSizeY / 10, true));
            } else if (mundo[y][x] == 2) {
                this->lista.push_front(Parede(x * tileSizeX, 500 - (tileSizeY * y), 2.5, 2.5, false));
            } else if (mundo[y][x] == 3) {
                //this->score->addBomba(x * tileSizeX + 14, 500 - (tileSizeY * y) - 14, tileSizeX / 2, tileSizeY / 2);

            } else if (mundo[y][x] == 4) {
                this->inimigos.push_front(new Enemy(x * tileSizeX + (tileSizeX / 3), 500 - (tileSizeY * y) - (tileSizeY / 3), tileSizeX / 2, tileSizeY / 2, true, this));
            } else if (mundo[y][x] == 5) {
                this->inimigos.push_front(new Enemy(x * tileSizeX + (tileSizeX / 3), 500 - (tileSizeY * y) - (tileSizeY / 3), tileSizeX / 2, tileSizeY / 2, false, this));
            } else if (mundo[y][x] == 6) {
                place[0] = x * tileSizeX;
                place[1] = 500 - (tileSizeY * y);
            } else if (mundo[y][x] == 0) {
                posicoesBombas.push_back(new Pos(x, y));
            }
        }
    }
    int i;
    srand(time(NULL));
    for (i = 0; i < this->numeroBombas; i++) {
        int pos = rand() % this->posicoesBombas.size();
        Pos* posObj = this->posicoesBombas[pos];
        this->score->addBomba(posObj->x * tileSizeX + 14, 500 - (tileSizeY * posObj->y) - 14, tileSizeX / 2, tileSizeY / 2);
        this->posicoesBombas.erase(this->posicoesBombas.begin() + pos);
    }
    // for (this->posicoesBombasIterator = this->posicoesBombas.begin(); this->posicoesBombasIterator != this->posicoesBombas.end(); this->posicoesBombasIterator++) {
    // }

    // for (it = this->lista.begin(); it != this->lista.end(); it++) {
    //     //std::cout << it->x << "\n";
    // }
}

int Mundo::col(Mascara m2, int direction, double speed) {
    for (it = this->lista.begin(); it != this->lista.end(); it++) {
        if (it->colidable) {
            if (m2.col(it->col, direction, speed)) {
                return true;
            }
        }
    }
    return false;
}

void Mundo::draw() {
    for (it = this->lista.begin(); it != this->lista.end(); it++) {
        it->draw();
    }

    for (itEnemy = this->inimigos.begin(); itEnemy != this->inimigos.end(); itEnemy++) {
        (*itEnemy)->draw();
    }
}

void Mundo::tick() {
    for (itEnemy = this->inimigos.begin(); itEnemy != this->inimigos.end(); itEnemy++) {
        (*itEnemy)->tick();
    }
}
