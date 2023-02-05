#include <SDL2/SDL.h>
#include <stdbool.h>

#ifndef GAME_H
#define GAME_H

/**
 * @struct Game
 * @brief Struct that define all main object to manage the game
 * @var window
 * Pointer to sdl window element
 * @var renderer
 * Pointer to sdl renderer element
 * @var is_running
 * Boolean variable that define if game has running
 * @var ticks_count
 * Time spent from last check
*/
typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer; 
    bool is_running;
    Uint32 ticks_count;
} Game;


Game* inizialize();
void run_loop(Game* game);
void shutdown(Game* game);

void process_input(Game *game);
void update_game(Game* game);
void generate_output(Game* game);


#endif
