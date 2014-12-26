#include <iostream>
#include "Game.hpp"

/* returns 0 on success
 *         1 if SDL failed to init
 *         2 if the window or renderer 
 *           couldn't be created
 */
int Game::Initialize() {

    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        PrintError("SDL_Init Error");
        return 1;
    }

    this->running = false;  
     
    // initialize window and renderer 
    this->win = SDL_CreateWindow("Hello World", 100, 100, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    this->ren = SDL_CreateRenderer(this->win, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   
    // return 2 to signify something is wrong is win or ren is null
    // return 0 otherwise to signify success 
    return (this->win == NULL || this->ren == NULL) ? 2 : 0;
}

/*  returns 0 on success
 */
int Game::Loop() {
    this->running = true;
    while(this->running){

    }
    return 0;
}

int Game::Render() {
    return 0;
}

int Game::HandleEvent(SDL_Event *event) {
    return 0;
}

int Game::Terminate() {
    SDL_DestroyRenderer(this->ren);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
    return 0;
}

void PrintError(const std::string &str) {
    printf("%s: %s\n", str.c_str(), SDL_GetError());
}

SDL_Texture *LoadImage(const std::string &filename, SDL_Renderer *ren) {
    SDL_Texture *tex = IMG_LoadTexture(ren, filename.c_str());
    
    if(tex == NULL) PrintError("IMG_LoadTexture");
    return tex;
}
