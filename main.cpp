#include <iostream>
#include "Game.hpp"

int main(int argc, char *argv[]){

    Game game = *(new Game());
   
    if(game.Initialize() > 0){
        printf("Error: The game wasn't initialized properly\n");
        game.Terminate();
        return 1;
    }   
    
    // the window and renderer was initialized properly. Start our game loop! 
    game.Loop();
    game.Terminate();

    return 0;
}
