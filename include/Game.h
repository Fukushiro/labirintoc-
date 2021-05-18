#ifndef GAME_H
#define GAME_H
#include "Score.h"
#include "Mundo.h"
#include "Player.h"
class Game {
   public:
    Score* score;
    Mundo* mundo;
    Player* p1;
    Game();
    virtual ~Game();
    void tick();
    void draw();
    void key(unsigned char key, int x, int y);
    void keyUp(unsigned char key, int x, int y);

   protected:
   private:
};

#endif  // GAME_H
