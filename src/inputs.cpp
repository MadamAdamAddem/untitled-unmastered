#include "Inputs.hpp"



bool handleEvents(SDL_Event* e)
{
  
  if(game.player->isPressedOn())
    SDL_CaptureMouse(SDL_TRUE);


  while(SDL_PollEvent(e) != 0)
  {
    if(e->type == SDL_QUIT)
      return false;


    if(e->type == SDL_MOUSEBUTTONUP)
    {
      mouse.isPressed = false;

      if(game.getMenuState() == false)
      {
        game.player->isMouseInHitbox(-1, -1);
        SDL_GetMouseState(&mouse.x, &mouse.y);
      }

    }


    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
      SDL_GetMouseState(&mouse.x, &mouse.y);
      mouse.isPressed = true;

      if(game.getMenuState() == false)
        game.level.checkMouseClick();

    }

      
    if(e->type == SDL_KEYDOWN)
    {
      if(e->key.keysym.sym == SDLK_ESCAPE)
      {
        game.toggleMenu();
      }


      if(e->key.keysym.sym == SDLK_r)
      {
        game.changeLevel(game.getLevel());
        return true;
      }

      
      if(e->key.keysym.sym == SDLK_y)
      {
        game.changeLevel(0);
        return true;
      }
      if(e->key.keysym.sym == SDLK_u)
      {
        game.changeLevel(1);
        return true;
      }
      if(e->key.keysym.sym == SDLK_i)
      {
        game.changeLevel(2);
        return true;
      }
      if(e->key.keysym.sym == SDLK_o)
      {
        game.changeLevel(3);
        return true;
      }

      if(e->key.keysym.sym == SDLK_p)
      {
        game.changeLevel(game.getLevel() + 1);
        return true;
      }

      if(e->key.keysym.sym == SDLK_q)
      {
        game.player->TOGGLE_FREE_MOVE();
      } 
    }

    
    
  }


  //idk why this is hidden here when it handles most game logic lol
  if(game.getMenuState() == false && game.level.checkNextLevelCollision() == false)
  {
    if(game.player->returnIsDead() == false)
      game.player->updateDragging();

    game.player->doMovement();
    
  }
  
  SDL_CaptureMouse(SDL_FALSE);
  return true;



}
