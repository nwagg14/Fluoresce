#ifndef _FLUR_ENTITY_
#define _FLUR_ENTITY_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity{
    public:
        SDL_Texture * texture;
        SDL_Rect destRect;
        SDL_Rect srcRect;
    
    public:
        Entity(SDL_Texture * tex, int tex_x, int tex_y, int w, int h, int x, int y);
        int Update(void);
};
#endif
