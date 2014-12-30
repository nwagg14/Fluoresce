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

    this->running = PAUSED ;  
     
    // initialize window, return with the value 2 on failure 
    this->win = SDL_CreateWindow("Fluoresce", 100, 100, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(this->win == NULL) return 2;

    // initialize renderer, return with the value 3 on failure
    this->ren = SDL_CreateRenderer(this->win, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(this->ren == NULL) return 3;

    //load textures
    this->grid   = LoadImage("Grid.png", ren);
    this->blocks = LoadImage("Blocks.png", ren);

    // initialize entities
    int i = 0;
    entities.reserve(10);
    for(i = 0; i < 10; i++){
        Entity e = Entity(blocks, 31*(i%2), 0, 31, 31, 32*i, 32*i); 
        entities.push_back(e);
    }
    return 0; 
}

/*  returns 0 on success
 */
int Game::Loop() {
    //this->running = RUNNING;
    while(this->running == RUNNING){

        SDL_Event evnt;
        while(SDL_PollEvent(&evnt)){
            if(evnt.type == SDL_QUIT) {
                running = PAUSED;
            }
            
        }
        Render();

    }
    return 0;
}

int Game::Render() {

    SDL_RenderClear( this->ren);
    for(int i = 0; i < entities.size(); i++) {
        SDL_RenderCopy(this->ren, entities[i].texture, &entities[i].srcRect, &entities[i].destRect);
    }
    SDL_RenderPresent(this->ren);
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
