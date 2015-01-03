#ifndef _FLUR_TEXT_ 
#define _FLUR_TEXT_ 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Utils.hpp"
#include "Entity.hpp"

class Text {

    private:
        SDL_Rect    srcRect;
        SDL_Rect    desRect;
        SDL_Texture *selectedTex;    
        SDL_Texture *unselectedTex;

        SDL_Renderer *ren;

    public:
        Text(TTF_Font *font, char *str, SDL_Renderer *ren);
        ~Text();
        void render(bool selected);
        void setPosition(int x, int y);


};

#endif
