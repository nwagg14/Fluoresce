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

    // initialize window, return with the value 2 on failure 
    this->win = SDL_CreateWindow("Fluoresce", 100, 100, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(this->win == NULL) return 2;

    // initialize renderer, return with the value 3 on failure
    this->ren = SDL_CreateRenderer(this->win, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(this->ren == NULL) return 3;

    TTF_Init();

    font = TTF_OpenFont("cnr.otf", 16);

    states[MENU] = new MenuState(win, ren, font);
    // initialize states
    /* 
    MENU
    SCORES
    GAME
    END 
    PAUSE
    */

/*
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
*/
    return 0; 
}

/*  returns 0 on success
 */
int Game::Loop() {
    FLU_StateName currentStateName = MENU; 
    FLU_StateName nextStateName    = MENU;
   
    // exit the loop if the next state we want is the exit state 
    while(nextStateName != EXIT){
        
        // switch states if necessary
        if (nextStateName != currentStateName) {
            states[currentStateName]->deactivate();
            states[nextStateName]->activate();
            currentStateName = nextStateName;
        } 

        nextStateName = states[currentStateName]->update();
    }

    return 0;
}

/*
int Game::Render() {

    SDL_RenderClear( this->ren);
    for(int i = 0; i < entities.size(); i++) {
        SDL_RenderCopy(this->ren, entities[i].texture, &entities[i].srcRect, &entities[i].destRect);
    }
    SDL_RenderPresent(this->ren);
    return 0;
}
*/

int Game::Terminate() {

    unsigned int i;
    for(i = 0; i < FLU_NUM_STATES; i++) {
        states[i]->terminate();
    }
    
    SDL_DestroyRenderer(this->ren);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
    return 0;
}
