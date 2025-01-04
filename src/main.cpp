#include "Rendering.hpp"
#include "Game.hpp"
#include "Inputs.hpp"



GameWindow gameWindow;
Game game;
Mouse mouse;



int main()
{
  Uint32 frameTime;
  SDL_Event e;
  

  while(handleEvents(&e))
  {
    
    frameTime = SDL_GetTicks();

  
    

    game.renderGame();
    SDL_RenderPresent(gameWindow.getRenderer());





    frameTime = SDL_GetTicks() - frameTime;

    if(frameTime < 16)
    {
      SDL_Delay(16 - frameTime);
    }

  }

  return 0;
}