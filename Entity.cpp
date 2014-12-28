#include <iostream>
#include "Entity.hpp"

Entity::Entity(SDL_Texture * tex, int tex_x, int tex_y, int w, int h, int x, int y) {
    this->texture = tex;
    this->texture_x = tex_x;
    this->texture_y = tex_y;
    this->width = w;
    this->height = h;
    this->dest_x = x;
    this->dest_y = y;
}


