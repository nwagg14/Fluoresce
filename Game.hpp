#ifndef _FLUR_GAME_
#define _FLUR_GAME_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

enum FLU_GameState {
    PAUSED,
    RUNNING,
};

enum FLU_CellState {
    EMPTY,
    TYPEA,
    TYPEB
};

class Game {
    private:
        SDL_Window   *win;
        SDL_Renderer *ren;
        bool running;

    public:
        int Initialize(void);
        int Loop(void);
        int Render(void);
        int Terminate(void);

        int HandleEvent(SDL_Event *event);      
};

void PrintError(const std::string &str);
SDL_Texture* LoadImage(const std::string &filename, SDL_Renderer *ren);

#endif
