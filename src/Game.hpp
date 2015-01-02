#ifndef _FLUR_GAME_
#define _FLUR_GAME_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils.hpp"
#include "State.hpp"
#include "MenuState.hpp"
#include "Entity.hpp"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480


class Game {
    private:
        SDL_Window   *win;
        SDL_Renderer *ren;
        TTF_Font     *font;
        
        State *states[FLU_NUM_STATES];

/*      SDL_Texture* grid; 
        SDL_Texture* blocks;
        std::vector<Entity> entities;
*/
    public:
        
        int Initialize(void);   // start up SDL, initialize states
        int Loop(void);         // calls update on the currentState
        int Terminate(void);    // call terminate on each state

        int HandleEvent(SDL_Event *event);      
};

#endif
