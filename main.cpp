#define GLUT_DISABLE_ATEXIT_HACK

/*
======== Teste OpenGL ==================
Nairon Neri Silva
Versao 1.0
Programa teste da configuracao do GLUT
Desenha um quadrado vermelho na tela
========================================
*/

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <array>
#include <iostream>
#include <list>
#include <string>

#include "Mascara.h"
#include "Bomba.h"
#include "Score.h"
#include "Parede.h"
#include "Enemy.h"
#include "Mundo.h"
#include "Player.h"
#include "Game.h"
#include "GameOver.h"
#include "Vitoria.h"
//#include "Mundo.h"

enum Direcao {
    Right,
    Left,
    Top,
    Down
};
//estados
enum Estados {
    JogoState,
    GameOverState,
    VitoriaState
};
/*
 0 = jogo
 1 = game over
 2 = vitoria
*/
int state = 0;
//mapa

//prototypes
class Parede;
class Player;
class Bomba;
class Enemy;
class Mundo;
void newGame();
void vencer();
//player spawn place
extern double place[2] = {10, 200};
//listas

//time
extern int tempoUsado = 0;
extern int comeco = 0;
extern double deltaTime = 0;
int oldTime = 0;
extern int newTime = 0;
extern int pontuacao = 0;
extern int pontuacaoMaxima = 0;

void RenderString(float x, float y, void* font, char* string, const std::array<unsigned int, 3> valor) {
    char* c;

    glColor3ub(valor.at(0), valor.at(1), valor.at(2));
    glRasterPos2f(x, y);

    for (char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);  // Updates the position
    }
}

void squad(int x, int y, int w, int h, double scaleX, double scaleY, const std::array<unsigned int, 3> valor) {
    //glColor3f(valor.at(0), valor.at(1), valor.at(2));
    glPushMatrix();
    glColor3ub(valor.at(0), valor.at(1), valor.at(2));
    glTranslated(x, y, 0);
    glScaled(scaleX, scaleY, 1);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(0 + w, 0);
    glVertex2i(0 + w, 0 - h);
    glVertex2i(0, 0 - h);
    glEnd();
    glPopMatrix();
}

//estados do jogo
extern Game* game = new Game();
GameOver gameOver;
Vitoria vitoria;

void newGame() {
    game = new Game();
}

void vencer() {
    pontuacao = game->score->pontos;
    pontuacaoMaxima = game->score->maxPontos;
    tempoUsado = (newTime - comeco);
    state = Estados::VitoriaState;
    newGame();
}

void perder() {
    pontuacao = game->score->pontos;
    pontuacaoMaxima = game->score->maxPontos;
    tempoUsado = (newTime - comeco);
    state = Estados::GameOverState;
    newGame();
}

void resetar() {
    comeco = newTime;
    tempoUsado = 0;
    state = Estados::JogoState;
}
void tick() {
    switch (state) {
        case 0:
            game->tick();
            break;
        case 1:
            gameOver.tick();
            break;
        case 2:
            vitoria.tick();
            break;
        default:
            break;
    }
}

void draw() {
    switch (state) {
        case 0:
            game->draw();
            break;
        case 1:
            gameOver.draw();
            break;
        case 2:
            vitoria.draw();
            break;
        default:
            break;
    }
}
void desenha(void) {
    tick();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    draw();

    glFlush();
}

void key(unsigned char key, int x, int y) {
    // p1.key(key, x, y);
    game->key(key, x, y);
    if (key == 'j') {
        perder();
    }
}

void keyUp(unsigned char key, int x, int y) {
    // p1.keyUp(key, x, y);
    game->keyUp(key, x, y);
}
void specialKeys(int key, int x, int y) {
game->specialKeys(key, x, y);

}

void specialKeysUp(int key, int x, int y){
    game->specialKeysUp(key, x, y);
}
void mouse(int button, int mouseState, int x, int y) {
    // y = 500 - y;

    // if (GLUT_LEFT_BUTTON == button && GLUT_DOWN == state) {
    // }
    if (state == Estados::GameOverState) {
        gameOver.mouse(button, mouseState, x, y);
    } else if (state == Estados::VitoriaState) {
        vitoria.mouse(button, mouseState, x, y);
    }
}

void timer(int) {
    srand(time(NULL));

    glutPostRedisplay();
    newTime = glutGet(GLUT_ELAPSED_TIME);
    deltaTime = newTime - oldTime;
    oldTime = newTime;

    glutTimerFunc(1000 / 60, timer, 0);
}

void init(void) {
    // Configura a cor de fundo como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    timer(0);
}

//Principal
int main(void) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Teste do OpenGL");

    glutDisplayFunc(desenha);
    glutKeyboardFunc(key);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(specialKeys);
    glutSpecialUpFunc(specialKeysUp);
    glutMouseFunc(mouse);

    init();

    glutMainLoop();
}
