#include "utils.h"
#include "game.h"
#include <SDL2/SDL.h>
#include <stdio.h>

// ====== Wrapper functions here ======

void scc(int code){
    if(code < 0){
        SDL_Log("SDL Error: %s", SDL_GetError());
        exit(1);
    }
    return;
}

void *scp(void *ptr){
    if(ptr == NULL){
        SDL_Log("SDL Error: %s", SDL_GetError());
        exit(1);
    }
    return ptr;
}


// ====== General functions here ======

float get_delta_time(Game* game){
    while(!SDL_TICKS_PASSED(SDL_GetTicks(), game->ticks_count + 16));

    float delta_time = (SDL_GetTicks() - game->ticks_count) / 1000.0f;

    printf("FPS: %f\n", 1.0f / delta_time);

    game->ticks_count = SDL_GetTicks();

    if (delta_time > 0.05f)
        delta_time = 0.05f;
    
    return delta_time;
}
