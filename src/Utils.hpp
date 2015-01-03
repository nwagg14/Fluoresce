#ifndef _FLUR_UTILS_
#define _FLUR_UTILS_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
                                      // r,   g,   b,   a
const SDL_Color SelectedTextColor   = {255, 255, 255, 255};
const SDL_Color UnselectedTextColor = {176, 176, 176, 255};

void PrintError(const std::string &str);
SDL_Texture* LoadImage(const std::string &filename, SDL_Renderer *ren);

#endif
