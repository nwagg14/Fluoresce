#ifndef _FLUR_UTILS_
#define _FLUR_UTILS_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
void PrintError(const std::string &str);
SDL_Texture* LoadImage(const std::string &filename, SDL_Renderer *ren);

#endif
