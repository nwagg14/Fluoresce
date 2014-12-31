#ifndef _FLUR_STATE_
#define _FLUR_STATE_
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum FLU_StateName{
    MENU = 0,
    SCORES,
    GAME,
    END, 
    PAUSE,
    EXIT        // the exit state isn't implemented by a state class
};              // instead, Loop() begins the exit proceedure when
                // the EXIT state is next

const int FLU_NUM_STATES = 5; // since EXIT isn't really a state...

class State {
    protected:
        SDL_Window   *win;
        SDL_Renderer *ren;
    public:

        
        // called by Game's Initialize and Terminate
        
        // should allocate any necessary memory and initialize it  
        virtual void initialize(SDL_Window *w, SDL_Renderer *r);   
        virtual void terminate();   // should free all memory associated with this state
        
        virtual void activate();    // called once before looping in update
        virtual void deactivate();  // called before transitioning to the next state
 
        virtual FLU_StateName update();
        virtual void render();
        
};

#endif
