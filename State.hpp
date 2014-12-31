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
    public:
        void initialize();
        void activate();
        void deactivate(); 
        void terminate();
 
        virtual FLU_StateName update();
        virtual void render();
        
};

#endif
