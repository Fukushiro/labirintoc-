#include "Player.h"
extern double deltaTime;
void perder();
enum Direcao {
    Right,
    Left,
    Top,
    Down
};
void squad(int x, int y, int w, int h, double scaleX, double scaleY, const std::array<unsigned int, 3> valor);
Player::Player() {
    //ctor
}

Player::~Player() {
    //dtor
}

Player::Player(double x, double y, double w, double h, Score* score, Mundo* mundo) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->state = 0;
    this->speed = 100;
    this->horizontal = 0;
    this->horizontal = 0;
    this->m1.start(this->x, this->y, this->w, this->h);
    this->score = score;
    this->mundo = mundo;
}
int Player::colEnemy() {
    for (iEnemy = this->mundo->inimigos.begin(); iEnemy != this->mundo->inimigos.end(); iEnemy++) {
        if (this->m1.col((*iEnemy)->col, -1, 0)) {
            perder();
        }
    }
}
int Player::colBomba() {
    for (i = this->score->bombas.begin(); i != this->score->bombas.end(); i++) {
        if (m1.col((*(*i)->col), -1, 0)) {
            (*i)->deletar();
            this->score->bombas.erase(i);
            this->score->addPonto();

            break;
        }
    }
}
int Player::col(int direction, double speed) {
    //colisão com o mundo
    if (this->mundo->col(this->m1, direction, speed)) {
        return true;
    }

    //colisão com bordas da tela
    if (this->m1.x - speed < 0 && direction == 1 || this->m1.x + this->m1.w + speed > 500 && direction == 0 ||
        (this->m1.y + speed > 500 && direction == 2) || (this->m1.y - this->h - speed < 0 && direction == 3)) {
        return true;
    }

    return false;
}

void Player::Move() {
    double customSpeed = this->speed*(deltaTime / 1000);
    //std::cout << this->speed * (deltaTime / 1000) << std::endl;
    if (this->horizontal == 1 && !this->col(Direcao::Right, customSpeed)) {
        this->x += customSpeed;
    } else if (this->horizontal == 2 && !this->col(Direcao::Left, customSpeed)) {
        this->x -= customSpeed;
    }
    if (this->vertical == 1 && !this->col(Direcao::Top, customSpeed)) {
        this->y += customSpeed;
    } else if (this->vertical == 2 && !this->col(Direcao::Down, customSpeed)) {
        this->y -= customSpeed;
    }
    this->m1.atualizarPos(this->x, this->y);
}
void Player::tick() {
    this->colEnemy();
    this->colBomba();
    this->Move();
}
void Player::draw() {
    squad(this->x, this->y, this->w, this->h, 1, 1, {0, 0, 255});
    //this->m1.draw();
}

void Player::key(unsigned char key, int x, int y) {
    if (key == 'd') {
        this->state = 1;
        this->horizontal = 1;
    } else if (key == 'a') {
        this->state = 1;
        this->horizontal = 2;
    }

    if (key == 'w') {
        this->state = 1;
        this->vertical = 1;
    } else if (key == 's') {
        this->state = 1;
        this->vertical = 2;
    }
}

void Player::keyUp(unsigned char key, int x, int y) {
    this->state = 0;
    if (key == 'a' || key == 'd') {
        this->horizontal = 0;
    }
    if (key == 'w' || key == 's') {
        this->vertical = 0;
    }
}
void Player::specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        this->state = 1;
        this->horizontal = 1;
    } else if (key == GLUT_KEY_LEFT) {
        this->state = 1;
        this->horizontal = 2;
    }

    if (key == GLUT_KEY_UP) {
        this->state = 1;
        this->vertical = 1;
    } else if (key == GLUT_KEY_DOWN) {
        this->state = 1;
        this->vertical = 2;
    }
}

void Player::specialKeysUp(int key, int x, int y){
    this->state = 0;
    if (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT) {
        this->horizontal = 0;
    }
    if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) {
        this->vertical = 0;
    }
}
