#include "game.h"
#include "utils.h"
#include "globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Game* inizialize() {
    scc(SDL_Init(SDL_INIT_VIDEO));
    SDL_Window* window = (SDL_Window*)scp(SDL_CreateWindow("Game Pro-Cedural",
                                                           SCREEN_X_POS,
                                                           SCREEN_Y_POS,
                                                           SCREEN_WIDTH,
                                                           SCREEN_HEIGTH,
                                                           SDL_WINDOW_RESIZABLE));

    SDL_Renderer* renderer = (SDL_Renderer*)scp(SDL_CreateRenderer(window, 
                                                                   -1, 
                                                                   SDL_RENDERER_ACCELERATED));
    int flag = IMG_INIT_PNG;
    int init_status = IMG_Init(flag);

    if((init_status & flag) != flag){
        SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
        exit(1);
    }

    Game* game = (Game*)malloc(sizeof(Game));
    game->is_running = true;
    game->renderer = renderer;
    game->window = window;
    game->ticks_count = SDL_GetTicks();

    return game;
}

void run_loop(Game* game){
    while (game->is_running){
        process_input(game);
        update_game(game);
        generate_output(game);
    }
}

void shutdown(Game* game){
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    IMG_Quit();
    free(game);
}

void process_input(Game* game){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            game->is_running = false;
            break;
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) 
        game->is_running = false;
}

void update_game(Game* game){
    float delta_time = get_delta_time(game);

    /* Update game here */
}

void generate_output(Game* game){
    SDL_SetRenderDrawColor(game->renderer, HEX_COLOR(BACKGROUND_COLOR));
    SDL_RenderClear(game->renderer);
    SDL_RenderPresent(game->renderer);
}
