#ifndef _FLUR_ENTITY_
#define _FLUR_ENTITY_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity{
    private:
        SDL_Texture * texture;
        int texture_x;
        int texture_y;
        int width;
        int height;
        int dest_x;
        int dest_y;
    public:
        Entity(SDL_Texture * tex, int tex_x, int tex_y, int w, int h, int x, int y);
        int Render(void);
        int Update(void);
};
#endif
