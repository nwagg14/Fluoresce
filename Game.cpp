#include "Game.hpp"

// returns empty struct on failure
int Game::Initialize() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    
    this->win = SDL_CreateWindow("Hello World", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    this->ren = SDL_CreateRenderer(this->win, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   
    // return 2 to signify something is wrong is win or ren is null
    // return 0 otherwise to signify success 
    return (this->win == NULL || this->ren == NULL) ? 2 : 0;
}

int Game::Loop() {
    return 0;
}

int Game::Terminate() {
    SDL_DestroyRenderer(this->ren);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
    return 0;
}
