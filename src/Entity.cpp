#include <iostream>
#include "Entity.hpp"

Entity::Entity(SDL_Texture * tex, int tex_x, int tex_y, int w, int h, int x, int y) {
    this->texture = tex;
 
    srcRect.x = tex_x;
    srcRect.y = tex_y;
    srcRect.w = w;
    srcRect.h = h;

    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;
}

int Entity::Update(void) {
    return 0;
}


