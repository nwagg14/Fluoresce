#include "MenuState.hpp"
MenuState::MenuState(SDL_Window *w, SDL_Renderer *r, TTF_Font *f) {
    
    unsigned int i;
    ren = r;
    win = w;
    font= f;

    currSelection = 0;

                      // r,   g,   b,   a
    selectedColor =   {255, 255, 255, 255};
    unselectedColor = {176, 176, 176, 255};

    // strings that represent menu items
    items.push_back("Start Game");
    items.push_back("High Scores");
    items.push_back("Exit");

    // intialize actual textures for menu items
    for(i = 0; i < items.size(); i++) {
        // make temporary surfaces for each selected/unselected option
        SDL_Surface *tempSelSurface =    TTF_RenderText_Blended(font, items[i].c_str(), selectedColor);
        SDL_Surface *tempUnselSurface =  TTF_RenderText_Blended(font, items[i].c_str(), unselectedColor);

        // convert the surfaces to textures
        SDL_Texture *selectedTex   = SDL_CreateTextureFromSurface(ren, tempSelSurface);
        SDL_Texture *unselectedTex = SDL_CreateTextureFromSurface(ren, tempUnselSurface);

        // free the temperary textures
        //SDL_FreeSurface(tempSelSurface); 
        //SDL_FreeSurface(tempUnselSurface);

        // put our textures in vectors for rendering
        selectedText.push_back(selectedTex);
        unselectedText.push_back(unselectedTex);
    }

} 

void MenuState::terminate() {
    //destroy items
} 
void MenuState::activate() {
    currSelection = 0;
} 

void MenuState::deactivate() {
    // nothing is necessary 
}

FLU_StateName MenuState::update() {
    SDL_Event event;
    while(true){
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: return EXIT;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym){
                        case SDLK_DOWN: currSelection = (currSelection + 1) % selectedText.size(); break;
                        case SDLK_UP:   currSelection = (currSelection == 0) ? 
                                                        selectedText.size() - 1 : currSelection - 1; break;
                        case SDLK_ESCAPE: return EXIT;
                    }
            }
        }

        render();
    }
    return MENU;
}
void MenuState::render() {
    
    int i;
    SDL_RenderClear(this->ren);
    for(i = 0; i < items.size(); i++) {
    int w, h;
    
    SDL_QueryTexture(selectedText[i], NULL, NULL, &w, &h);

    SDL_Rect src  = {0, 0, w, h};
    SDL_Rect dest = {(SCREEN_WIDTH - w)/2, 
                     i * (h + 15) + 100,
                     w, h};

    // render as selected 
    if(i == currSelection) {
        SDL_RenderCopy(ren, selectedText[i], &src, &dest);
    }

    // render as unselected
    else { 
        SDL_RenderCopy(ren, unselectedText[i], &src, &dest);
    }
    }
    SDL_RenderPresent(this->ren);
}
