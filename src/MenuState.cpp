#include "MenuState.hpp"
MenuState::MenuState(SDL_Window *w, SDL_Renderer *r, TTF_Font *f) {
    
    unsigned int i;
    Text *tempText;
    ren = r;
    win = w;
    font= f;

    currSelection = 0;

                      // r,   g,   b,   a
    selectedColor =   {255, 255, 255, 255};
    unselectedColor = {176, 176, 176, 255};

    // strings that represent menu items
    tempText = new Text(font, "Start Game", ren);
    items.push_back(tempText);
    
    tempText = new Text(font, "High Scores", ren);
    items.push_back(tempText);
    
    tempText = new Text(font, "Exit", ren);
    items.push_back(tempText);

    for(i = 0; i < items.size(); i++) {
        items[i]->setPosition(SCREEN_WIDTH/2, 50 + 20*i);
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
                        case SDLK_DOWN: currSelection = (currSelection + 1) % items.size(); break;
                        case SDLK_UP:   currSelection = (currSelection == 0) ? 
                                                        items.size() - 1 : currSelection - 1; break;
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


    // render as selected 
    if(i == currSelection) {
        items[i]->render(true);
    }

    // render as unselected
    else { 
        items[i]->render(false);
    }
    }
    SDL_RenderPresent(this->ren);
}
