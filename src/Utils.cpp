#include "Utils.hpp"

void PrintError(const std::string &str) {
    printf("%s: %s\n", str.c_str(), SDL_GetError());
}

SDL_Texture *LoadImage(const std::string &filename, SDL_Renderer *ren) {
    SDL_Texture *tex = IMG_LoadTexture(ren, filename.c_str());
    
    if(tex == NULL) PrintError("IMG_LoadTexture");
    return tex;
}
