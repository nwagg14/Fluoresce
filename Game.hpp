#ifndef _GAME_
#define _GAME_
#include <SDL2/SDL.h>

class Game {
    private:
        SDL_Window   *win;
        SDL_Renderer *ren;

    public:
        int Initialize(void);
        int Loop(void);
        int Render(void);
        int Terminate(void);

        int HandleEvent(SDL_Event *event);      
};

#endif
