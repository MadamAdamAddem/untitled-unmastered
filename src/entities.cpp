#include "Entities.hpp"
#include "math.h"

//i don't remember writing this
//runs each frame while dead
void marchToPoint(Entity* entity, int pointX, int pointY)
{

  int xStepSize;
  xStepSize = pointX - entity->getX();

  if(xStepSize > 0)
  {
    xStepSize = 1;
  }
  else if(xStepSize < 0)
  {
    xStepSize = -1;
  }

  int yStepSize;
  yStepSize = pointY - entity->getY();

  if(yStepSize > 0)
    yStepSize = 1;
  else if(yStepSize < 0)
    yStepSize = -1;


  entity->teleport(entity->getX() + xStepSize, entity->getY() + yStepSize);

}

// ------------------------------------------------------------

void Entity::initEntity(adamTexture* newTexture, int xPos, int yPos, int w, int h)
{
  x = xPos;
  y = yPos;
  width = 50;
  height = 50;
  spriteClip = -1;
  animationFrame = 0;
  enType = BASIC;

  texture = newTexture;

  isVisible = true;

  stretchFactor = (float)w / (float)texture->getWidth();

}

void Entity::initGraphic(char path[], int xPos, int yPos, int w, int h, int spriteNum)
{
  x = xPos;
  y = yPos;
  width = w;
  height = h;
  spriteClip = spriteNum;
  animationFrame = 0;
  enType = GRAPHIC;


  texture = new adamTexture;
  texture->loadFromFile(path, gameWindow.getRenderer());



  if(spriteClip == -1)
    stretchFactor = (float)w / (float)texture->getWidth();
  else
    stretchFactor = 1;
}

Entity::Entity()
{
  x = 0;
  y = 0;
  width = 0;
  height = 0;
  spriteClip = -1;
  animationFrame = 0;
  stretchFactor = 1;
  enType = BASIC;
  isVisible = true;
}

Entity::~Entity()
{

}

void Entity::renderEntity(int angle) 
{

  if(!isVisible)
    return;

  switch(enType)
  {
    case PLAYER:
      texture->render(x, y, gameWindow.getRenderer(), stretchFactor);
      return;

    case STICK:
      texture->render(x, y, gameWindow.getRenderer(), stretchFactor, NULL, angle);
      return;

    case WALL_OBSTACLE:
      texture->render(x, y, gameWindow.getRenderer(), stretchFactor, &wallSpriteClips[spriteClip]);
      return;

    case HOLE_OBSTACLE:
      texture->render(x, y, gameWindow.getRenderer(), stretchFactor, &holeSpriteClips[spriteClip]);
      return;

    case BASIC:
    case GRAPHIC:
      texture->render(x, y, gameWindow.getRenderer(), stretchFactor);
      break;

  }

}

// ------------------------------------------------------------

Player::Player(adamTexture* newTexture, int xPos, int yPos, int w, int h, int spriteNum)
{
  x = xPos;
  y = yPos;
  width = w;
  height = h;
  spriteClip = -1;
  animationFrame = 0;

  pressedOn = false;
  distance = -1;
  framesInAir = 0;
  velocityX = 0;
  velocityY = 0;

  collisionBox.x = x+3;
  collisionBox.y = y;
  collisionBox.w = width-3;
  collisionBox.h = height;


  freeFly = false;

  isDead = false;
  holeX = -1;
  holeY = -1;


  texture = newTexture;
}

Player::~Player()
{
}

//how specific, i know
void Player::doMovement()
{
  if(isDead)
  {
    //barely works lmao
    marchToPoint(game.player, holeX - (width/2), holeY + 5);

    if(stretchFactor != 0)
      stretchFactor -= 0.05;


    return;
  }

  //gravity
  if(framesInAir%2 && !freeFly)
    velocityY += 1;

  
  //friction
  if(framesInAir == 0 && !freeFly && velocityY == 0)
  {
    if(velocityX > 0)
      velocityX -= 1;
    else if(velocityX < 0)
      velocityX += 1;
  }
  else
    ++framesInAir;

  if(freeFly)
  {
    SDL_GetMouseState(&mouse.x, &mouse.y);
    x = mouse.x;
    y = mouse.y;
    collisionBox.x = x;
    collisionBox.y = y;
  }
  else
  {
    game.level.doCollision(&collisionBox, &velocityX, &velocityY, &framesInAir);
    x = collisionBox.x;
    y = collisionBox.y;
  }




  



}

//only runs when mouse button is pressed
bool Player::isMouseInHitbox(int mouseX, int mouseY)
{
  //5 pixel padding
  pressedOn = (mouseX >= x-5 && mouseX <= x+25 && mouseY >= y-5 && mouseY <= y+25);
  return pressedOn;
}

void Player::updateDragging()
{
  if(framesInAir != 0)
  {
    return;
  }
    

  //std::cout << "PLAYER UPDATE DRAGGING" << std::endl;
  if(pressedOn)
  {

    int tmpX, tmpY;
    SDL_GetMouseState(&tmpX, &tmpY);

    distance = sqrt(pow((tmpX - x+10), 2) + pow((tmpY - y+10), 2));
    stick.animationFrame = distance / 25;
    if(stick.animationFrame > 15)
      stick.animationFrame = 15;



    float xDistance = ((x-tmpX)+10);
    float yDistance = ((y-tmpY)+10);

    float angle = atan2(xDistance, yDistance) * -180 / M_PI;
    int sign = (angle >= 0) ? -1 : 1;

    //inverts the angle of drag
    //45 -> -135, 90 -> -90, 135 -> -45
    angle = (180 - abs(angle)) * sign;

    stick.isVisible = true;
    stick.angle = angle - 90;


    stick.x = tmpX - stick.width;
    stick.y = tmpY - (stick.height/2);
  }
  else
  {
  
    //"Hey man IDK why they're making us take trig this is a computer degree"
    if(distance != -1)
    {
    
      float xDistance = ((x-mouse.x)+10);
      float yDistance = ((y-mouse.y)+10);

      float angle = atan2(xDistance, yDistance) * -180 / M_PI;
      int sign = (angle >= 0) ? -1 : 1;

      //inverts the angle of drag
      //45 -> -135, 90 -> -90, 135 -> -45
      angle = (180 - abs(angle)) * sign;

      
      yDistance = (1-abs(angle/90)) * -1;

      if(abs(angle) > 90)
        angle = (180 - abs(angle)) * -1;

      xDistance = ((abs(angle/90)) * sign);

      
      xDistance *= 1.5 * stick.animationFrame;
      yDistance *= 1.5 * stick.animationFrame;

      if(xDistance > 10)
        xDistance = 10;
      else if(xDistance < -10)
        xDistance = -10;

      if(yDistance > 10)
        yDistance = 10;
      else if(yDistance < -10) 
        yDistance = -10;
      

      velocityX = xDistance;
      velocityY = yDistance;

      stick.isVisible = false;

      
    }
    
    

    distance = -1;



    if(stick.animationFrame >= 0)
    {

      --stick.animationFrame;
    }
      

    if(stick.animationFrame == -1)
    {
      stick.isVisible = false;
    }
  }
    

}

void Player::renderStick()
{
  if(stick.returnIsVisible())
    stick.renderEntity(stick.angle);
}

void Player::killPlayer(int deathX, int deathY)
{
  isDead = true;
  velocityX = 0;
  velocityY = 0;

  holeX = deathX;
  holeY = deathY;

}
// ------------------------------------------------------------

  //can be initialized with texture or path to png
void Obstacle::initObstacle(adamTexture* newTexture, int clipNum, int xPos, int yPos, int w, int h, float stretch, int obsType)
{
  texture = newTexture;
  customTexture = false;
  
  x = xPos;
  y = yPos;
  width = w;
  height = h;
  spriteClip = clipNum;
  obType = obsType;

  if(obsType < 16)
    obsType = DEATH_HOLE_GENERIC;

  

  switch(obsType)
  {
    case ONE_WAY_LINE:
      collisionBox.x = xPos;
      collisionBox.y = yPos;
      collisionBox.w = xPos + w;
      collisionBox.h = yPos;
      enType = BASIC;
      break;

    case RECTANGLE:
      collisionBox.x = xPos;
      collisionBox.y = yPos;
      collisionBox.w = w;
      collisionBox.h = h;
      enType = WALL_OBSTACLE;
      break;

    case DEATH_HOLE_GENERIC:
      collisionBox.x = xPos;
      collisionBox.y = yPos;
      collisionBox.w = w;
      collisionBox.h = h;
      enType = HOLE_OBSTACLE;
      break;
  }


  stretchFactor = stretch;
  
}

void Obstacle::initObstacle(char path[], int clipNum, int xPos, int yPos, int w, int h, float stretch, int obsType)
{
  texture = new adamTexture;
  texture->loadFromFile(path, gameWindow.getRenderer());
  customTexture = true;
  
  x = xPos;
  y = yPos;
  width = w;
  height = h;
  spriteClip = clipNum;
  obType = obsType;

  if(obsType < 16)
    obsType = DEATH_HOLE_GENERIC;
  

  switch(obsType)
  {
    case ONE_WAY_LINE:
      collisionBox.x = xPos;
      collisionBox.y = yPos;
      collisionBox.w = xPos + w;
      collisionBox.h = yPos;
      enType = BASIC;
      break;

    case RECTANGLE:
      collisionBox.x = xPos;
      collisionBox.y = yPos;
      collisionBox.w = w;
      collisionBox.h = h;
      enType = WALL_OBSTACLE;
      break;

    case DEATH_HOLE_GENERIC:
      collisionBox.x = xPos;
      collisionBox.y = yPos;
      collisionBox.w = w;
      collisionBox.h = h;
      enType = HOLE_OBSTACLE;
      break;
  }


  stretchFactor = stretch;
  
}

Obstacle::Obstacle()
{

}

Obstacle::~Obstacle()
{
  if(customTexture)
    delete texture;
}

// ------------------------------------------------------------

PoolStick::PoolStick()
{
  x = 300;
  y = 300;
  width = 100;
  height = 10;
  enType = STICK;

  isVisible = false;

  texture = new adamTexture();
  texture->loadFromFile("assets/poostick.png", gameWindow.getRenderer());

  if(spriteClip == -1)
    stretchFactor = (float)width / (float)texture->getWidth();
  else
    stretchFactor = 1;

}

PoolStick::~PoolStick()
{
  delete texture;
}

// ------------------------------------------------------------

void Button::initButton(int xPos, int yPos, int w, int h, ButtonType bType)
{
  x = xPos;
  y = yPos;
  width = w;
  height = h;
  pressedOn = false;

  buttonType = bType;
  enType = BASIC;

}

Button::Button()
{

}

Button::~Button()
{

}

void Button::isPressed(int mouseX, int mouseY)
{
  pressedOn = (mouseX >= x && mouseX <= x+width && mouseY >= y && mouseY <= y+width);

  if(buttonType == NEXT_LEVEL && pressedOn == true)
    game.changeLevel(game.getLevel() + 1);
  
  return;
}

// ------------------------------------------------------------

