#include "Game.hpp"


#define FRICTION 2
#define HBOUNCE_DIVISOR 2.5
#define VBOUNCE_DIVISOR 3


//determines if collision is the result of an X or Y movement
enum VelFault : int
{
  NO_FAULT = 0,
  Y_FAULT = 1,
  X_FAULT = 2,
  XY_FAULT = 3,
};

//if a collision is the 'y fault', it means the y velocity was responsible
//for causing the collision, and is what should be reversed
//1 for y, 2 for x, 3 for both
int determineFault(SDL_Rect* collisionBox, SDL_Rect* collisionBox2, int* velX, int* velY)
{
  //1 for y, 2 for x, 3 for both
  VelFault fault = NO_FAULT;

  //checks if the collision is the x or y velocity's "fault", and does collision accordingly
  collisionBox->x -= *velX;

  //y collision
  if(SDL_HasIntersection(collisionBox, collisionBox2) && *velY != 0)
  {
    fault = Y_FAULT;
  }


  collisionBox->x += *velX;
  collisionBox->y -= *velY;

  //x collision
  if(SDL_HasIntersection(collisionBox, collisionBox2) && *velX != 0)
  {
    //C was written by monkeys on typewriters
    fault = (VelFault)(fault + X_FAULT);
  }

  collisionBox->y += *velY;
  
  return fault;
}

// ------------------------------------------------------------

Game::Game()
{
  printf("GAME OBJECT\n");

  //wall sprite clips initialization
  for(int i=0; i<16; ++i)
  { 
    wallSpriteClips[i] = {(i%4)*25, (i/4)*25, 25, 25};
  }

  //hole sprite clips initialization
  for(int i=0; i<16; ++i)
  { 
    holeSpriteClips[i] = {(i%4)*20-1, (i/4)*20-1, 20, 20};
  }

  currLevel = 0;

  SDL_Renderer* renderer = gameWindow.getRenderer();

  backgroundTexture = new adamTexture;
  wallTexture = new adamTexture;
  holeTexture = new adamTexture;
  winTexture = new adamTexture;
  playerTexture = new adamTexture;
  platformTexture = new adamTexture;

  wallTexture->loadFromFile("assets/blankSheet.png", renderer);
  holeTexture->loadFromFile("assets/holeSheet.png", renderer);
  winTexture->loadFromFile("assets/poolTriangle.png", renderer);
  playerTexture->loadFromFile("assets/ballNew.png", renderer);
  platformTexture->loadFromFile("assets/oneWay.png", renderer);
  
  level.loadTitle();
}

Game::~Game()
{
  delete backgroundTexture;
  delete wallTexture;
  delete winTexture;
  delete playerTexture;
  delete holeTexture;
  delete platformTexture;

  level.clearLevel();
}

void Game::renderGame()
{

  level.renderLevel();
  if(menuOpen)
    settingsMenu.renderMenu();
}

void Game::changeLevel(int levelNum)
{
  currLevel = levelNum;
  level.initializeLevel();
}

// ------------------------------------------------------------

Level::Level()
{
}

Level::~Level()
{
  clearLevel();
}

void Level::renderLevel()
{
  SDL_Renderer* renderer = gameWindow.getRenderer();
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);

  game.backgroundTexture->render(0, 0, renderer, 5);

  for(int i=0; i<numObstacles; ++i)
  {
    obstacleArray[i].renderEntity();
  }

  for(int i=0; i<numEntities; ++i)
  {
    entityArray[i].renderEntity();
  }


  game.player->renderStick();
  game.player->renderEntity(PLAYER);
}

bool Level::doCollisionAdjustment(SDL_Rect* collisionBox, SDL_Rect* collisionBox2, int obsType, int* velX, int* velY, int* framesInAir)
{
  //std::cout << "LEVEL COLLISION ADJUSTMENT" << std::endl;
  //if theres no collision screw off
  if(obsType != ONE_WAY_LINE)
  {
    if(!SDL_HasIntersection(collisionBox, collisionBox2))
      return false;
  }
  else
  {
    if(!SDL_IntersectRectAndLine(collisionBox, &collisionBox2->x, &collisionBox2->y, &collisionBox2->w, &collisionBox2->h))
      return false;
  }
  
  //1 for y, 2 for x, 3 for both
  int fault = determineFault(collisionBox, collisionBox2, velX, velY);
  
  int specificType = 0;

  if(obsType < 16)
  {
    specificType = obsType;
    obsType = DEATH_HOLE_GENERIC;
  }

  switch(obsType)
  {
  case RECTANGLE:
  {

    if(fault == 1)
    {
      if(*velY > 0)
        collisionBox->y = collisionBox2->y - collisionBox->h;
      else
        collisionBox->y = collisionBox2->y + collisionBox2->h;

      if(*velX > 0)
        *velX -= FRICTION;
      else if(*velX < 0)
        *velX += FRICTION; 

      *velY /= -VBOUNCE_DIVISOR;
      *framesInAir = 0;
    }
      
    if(fault == 2)
    {
      if(*velX > 0)
        collisionBox->x = collisionBox2->x - collisionBox->w;
      else
        collisionBox->x = collisionBox2->x + collisionBox2->w;
      *velX /= -HBOUNCE_DIVISOR;
    }
      
    if(fault == 3)
    {
      if(*velY > 0)
        collisionBox->y = collisionBox2->y - collisionBox->h;
      else
        collisionBox->y = collisionBox2->y + collisionBox2->h;

       if(*velX > 0)
        collisionBox->x = collisionBox2->x - collisionBox->w;
      else
        collisionBox->x = collisionBox2->x + collisionBox2->w;


      if(*velX > 0)
        *velX -= FRICTION;
      else if(*velX < 0)
        *velX += FRICTION; 

      *velY /= -VBOUNCE_DIVISOR;
      *velX /= -HBOUNCE_DIVISOR;
      *framesInAir = 0;
    }

    
  }
    break;
  case DEATH_HOLE_GENERIC:
  {
    if(fault == X_FAULT && *velX > 0 && (specificType & DEATH_HOLE_L))
    {
      game.player->killPlayer(collisionBox2->x+(collisionBox2->w/2), collisionBox2->y + (collisionBox2->h/2));
      return true;
    }

    if(fault == X_FAULT && *velX < 0 && (specificType & DEATH_HOLE_R))
    {
      game.player->killPlayer(collisionBox2->x+(collisionBox2->w/2), collisionBox2->y);
      return true;
    }

    if(fault == Y_FAULT && *velY > 0 && (specificType & DEATH_HOLE_U))
    {
      game.player->killPlayer(collisionBox2->x+(collisionBox2->w/2), collisionBox2->y);
      return true;
    }

    if(fault == Y_FAULT && *velY < 0 && (specificType & DEATH_HOLE_D))
    {
      game.player->killPlayer(collisionBox2->x+(collisionBox2->w/2), collisionBox2->y);
      return true;
    }

    if(fault == 1)
    {
      if(*velY > 0)
        collisionBox->y = collisionBox2->y - collisionBox->h;
      else
        collisionBox->y = collisionBox2->y + collisionBox2->h;

      if(*velX > 0)
        *velX -= 1;
      else if(*velX < 0)
        *velX += 1; 

      *velY /= -3;
      *framesInAir = 0;
    }
      
    if(fault == 2)
    {
      if(*velX > 0)
        collisionBox->x = collisionBox2->x - collisionBox->w;
      else
        collisionBox->x = collisionBox2->x + collisionBox2->w;
      *velX /= -3;
    }
      
    if(fault == 3)
    {
      if(*velY > 0)
        collisionBox->y = collisionBox2->y - collisionBox->h;
      else
        collisionBox->y = collisionBox2->y + collisionBox2->h;

       if(*velX > 0)
        collisionBox->x = collisionBox2->x - collisionBox->w;
      else
        collisionBox->x = collisionBox2->x + collisionBox2->w;


      if(*velX > 0)
        *velX -= 1;
      else if(*velX < 0)
        *velX += 1; 

      *velY /= -3;
      *velX /= -3;
      *framesInAir = 0;
    }



  }
    break;
  case ONE_WAY_LINE:
    
    if(collisionBox->x + collisionBox->w - 4 >= collisionBox2->x && collisionBox->x + 4 <= collisionBox2->w)
    {
      
      if(collisionBox->y + collisionBox->h >= collisionBox2->y && collisionBox->y + collisionBox->h - *velY <= collisionBox2->y)
      {
        *velY /= -3;
        collisionBox->y = collisionBox2->y - collisionBox->h;

        if(*velX > 0)
          *velX -= 1;
        else if(*velX < 0)
          *velX += 1;

        *framesInAir = 0;
        return true;
      }
        

    }

    break;
    
  }

  return false;


}

bool Level::doCollision(SDL_Rect* collisionBox, int* velX, int* velY, int* framesInAir)
{
  //std::cout << "LEVEL COLLISION" << std::endl;

  bool isCollision = false;
  
  collisionBox->x += *velX;
  collisionBox->y += *velY;



  if(collisionBox->x <= leftWallX)
  {
    collisionBox->x = leftWallX;
    //isCollision = true;

    *velX /= -HBOUNCE_DIVISOR;
  }
  else if(collisionBox->x+collisionBox->w >= rightWallX)
  {
    collisionBox->x = rightWallX-collisionBox->w;
    //isCollision = true;

    *velX /= -HBOUNCE_DIVISOR;
  }

  if(collisionBox->y <= roofY)
  {
    collisionBox->y = roofY;
    isCollision = true;

    *velY /= -VBOUNCE_DIVISOR;
    *framesInAir = 0;
  }
  else if(collisionBox->y+collisionBox->h >= floorY)
  {
    collisionBox->y = floorY - collisionBox->h;
    isCollision = true;

    *velY /= -VBOUNCE_DIVISOR;
    *framesInAir = 0;
  }


  if(isCollision)
    return true;

  //the collision box can also sometimes be a line segment
  //rather than add a seperate collision object, the x and y variables will be x1 and y1 and width and height will represent x2 and y2
  for(int i=0; i<numObstacles; ++i)
  {
    SDL_Rect collisionBox2 = obstacleArray[i].getCollisionBox();

    bool coll = doCollisionAdjustment(collisionBox, &collisionBox2, obstacleArray[i].getObstacleType(), velX, velY, framesInAir);
    if(coll)
      return true;
  }

  return false;
    
}

void Level::clearLevel()
{
  
  delete [] entityArray;

  delete [] obstacleArray;
  
  delete [] buttonArray;

  

  numEntities = 0;
  numObstacles = 0;
  numButtons = 0;


  leftWallX = 0;
  rightWallX = 0;
  roofY = 0;
  floorY = 0;

  delete game.player;
}

void Level::checkMouseClick()
{
  game.player->isMouseInHitbox(mouse.x, mouse.y);

  for(int i=0; i<numButtons; ++i)
    buttonArray[i].isPressed(mouse.x, mouse.y);
}

bool Level::checkNextLevelCollision()
{
  SDL_Rect entColl = {entityArray[0].getX(), entityArray[0].getY(), entityArray[0].getW(), entityArray[0].getH()};
  if(SDL_HasIntersection(game.player->getCollisionBox(), &entColl))
  {
    game.changeLevel(game.getLevel() + 1);
    return true;
  }

  return false;
}

// ------------------------------------------------------------

Menu::Menu()
{
  SDL_Renderer* renderer = gameWindow.getRenderer();

  overlay = new adamTexture;
  menuTexture = new adamTexture;


  overlay->loadFromFile("assets/overlay.png", renderer);
  menuTexture->loadFromFile("assets/menuText.png", renderer);

  menuX = 100;
  menuY = 120;

}

Menu::~Menu()
{
  delete overlay;
  delete menuTexture;
}

void Menu::renderMenu()
{
  SDL_Renderer* renderer = gameWindow.getRenderer();

  overlay->render(0, 0, renderer, 5);
  menuTexture->render(menuX, menuY, renderer, 3);
}





