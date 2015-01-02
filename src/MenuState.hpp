#ifndef _FLUR_MENUSTATE_
#define _FLUR_MENUSTATE_
#include "State.hpp"
#include "Game.hpp"
#include <string>

class MenuState : public State {
    private:
        std::vector<std::string> items;
        int currSelection;
        SDL_Color selectedColor;
        SDL_Color unselectedColor;

        std::vector<SDL_Texture*> selectedText;
        std::vector<SDL_Texture*> unselectedText;
    
    public:
        MenuState(SDL_Window *w, SDL_Renderer *r, TTF_Font *f);
        ~MenuState() {}
        // called by Game's Initialize and Terminate
        //void initialize(SDL_Window *w, SDL_Renderer *r);   
        void terminate();   // should free all memory associated with this state
        
        void activate();    // called once before looping in update
        void deactivate();  // called before transitioning to the next state
 
        FLU_StateName update();
        void render();
        
};

#endif
