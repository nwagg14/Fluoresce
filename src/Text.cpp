#include "Text.hpp"

Text::Text(TTF_Font *font, char *str, SDL_Renderer *rend) {
   
    ren = rend; 
    // create temperary surfaces
    SDL_Surface *tempSelSurface =    TTF_RenderText_Blended(font, str, SelectedTextColor);
    SDL_Surface *tempUnselSurface =  TTF_RenderText_Blended(font, str, UnselectedTextColor);
        
    // convert the surfaces to textures
    selectedTex   = SDL_CreateTextureFromSurface(ren, tempSelSurface);
    unselectedTex = SDL_CreateTextureFromSurface(ren, tempUnselSurface);

    // free the temperary surfaces
    SDL_FreeSurface(tempSelSurface); 
    SDL_FreeSurface(tempUnselSurface);

    // initialize Rects
    int w, h;
    SDL_QueryTexture(selectedTex, NULL, NULL, &w, &h);
    srcRect = {0, 0, w, h};
    desRect = {0, 0, w, h};
}

Text::~Text() {
    SDL_DestroyTexture(selectedTex);
    SDL_DestroyTexture(unselectedTex);
}

void Text::render(bool selected) {
    if (selected)
        SDL_RenderCopy(ren, selectedTex, &srcRect, &desRect);
    else 
        SDL_RenderCopy(ren, unselectedTex, &srcRect, &desRect);
}

// places text on screen with the center at (x,y)
void Text::setPosition(int x, int y) {
    int w, h;
    SDL_QueryTexture(selectedTex, NULL, NULL, &w, &h);
    
    desRect = {x - w/2, y - h/2, w, h};
}
