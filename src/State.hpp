#ifndef _FLUR_STATE_
#define _FLUR_STATE_
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

enum FLU_StateName{
    MENU = 0,
    SCORES,
    GAME,
    END, 
    PAUSE,
    EXIT        // the exit state isn't implemented by a state class
};              // instead, Loop() begins the exit proceedure when
                // the EXIT state is next

const int FLU_NUM_STATES = 1; // since EXIT isn't really a state...

class State {
    protected:
        SDL_Window   *win;
        SDL_Renderer *ren;
        TTF_Font     *font;
    public:
        virtual ~State() {}
        
        // called by Game's Initialize and Terminate
        
        // should allocate any necessary memory and initialize it  
//        virtual void initialize(SDL_Window *w, SDL_Renderer *r) = 0;   
        virtual void terminate() = 0;   // should free all memory associated with this state
        
        virtual void activate() = 0;    // called once before looping in update
        virtual void deactivate() = 0;  // called before transitioning to the next state
 
        virtual FLU_StateName update() = 0;
        virtual void render() = 0;
        
};

#endif
