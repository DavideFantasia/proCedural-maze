#include "game.h"

int main(void){
    Game* game = inizialize();
    if(game) run_loop(game);

    shutdown(game);
    return 0;
}
