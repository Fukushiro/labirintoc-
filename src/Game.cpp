#include "Game.h"
extern double place[2];
Game::~Game() {
    //dtor
}

Game::Game() {
    score = new Score();

    mundo = new Mundo(500, 500, 10, score);
    p1 = new Player(place[0], place[1], 12.5, 12.5, score, mundo);
}

void Game::tick() {
    this->score->tick();
    this->mundo->tick();
    this->p1->tick();
}
void Game::draw() {
    this->mundo->draw();
    this->p1->draw();
    this->score->draw();
}

void Game::key(unsigned char key, int x, int y) {
    this->p1->key(key, x, y);
}
void Game::keyUp(unsigned char key, int x, int y) {
    this->p1->keyUp(key, x, y);
}