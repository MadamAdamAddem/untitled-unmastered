#pragma once
#include "Rendering.hpp"
#include "Game.hpp"

//Used for rendering
enum EntityType
{
  BASIC = 0,
  WALL_OBSTACLE,
  HOLE_OBSTACLE,
  PLAYER,
  GRAPHIC,
  STICK,

};

//Used for collisioning
enum ObstacleType : int
{
  DEATH_HOLE_L = 1,
  DEATH_HOLE_R = 2,
  DEATH_HOLE_U = 4,
  DEATH_HOLE_D = 8,
  RECTANGLE = 16,
  ONE_WAY_LINE = 17,
  DEATH_HOLE_GENERIC = 18,
  

};

enum ButtonType
{
  NEXT_LEVEL = 0,

};

class Entity
{
public:

  
  Entity();
  ~Entity();

  void initEntity(adamTexture* newTexture, int xPos, int yPos, int w, int h);
  void initGraphic(char path[], int xPos, int yPos, int w, int h, int spriteNum);
  bool checkCollision();

  void teleport(int xPos, int yPos) {x = xPos; y = yPos;}

  int getX() {return x;}
  int getY() {return y;}
  int getW() {return width;}
  int getH() {return height;}

  void renderEntity(int angle = 0);
  bool returnIsVisible() {return isVisible;}
  EntityType getEntityType() {return enType;}
 

protected:

  int x;
  int y;
  int animationFrame;
  int spriteClip;
  int width;
  int height;
  float stretchFactor;

  bool isVisible;

  EntityType enType;
  

  adamTexture* texture;
};

class Obstacle : public Entity
{
public:



  Obstacle();
  ~Obstacle();

  void initObstacle(adamTexture* newTexture, int clipNum, int xPos, int yPos, int w, int h, float stretch = 1.0f, int obsType = RECTANGLE);
  void initObstacle(char path[], int clipNum, int xPos, int yPos, int w, int h, float stretch = 1.0f, int obsType = RECTANGLE);

  SDL_Rect getCollisionBox() {return collisionBox;}
  int getObstacleType() {return obType;}

private:

  bool customTexture;
  SDL_Rect collisionBox;
  int obType;

};

class PoolStick : public Entity
{
friend class Player;
public:
  PoolStick();
  ~PoolStick();



  

private:

  int angle;
};

class Player : public Entity
{

public:
  
  Player(adamTexture* newTexture, int xPos, int yPos, int w, int h, int spriteNum);
  ~Player();

  void doMovement();

  int getFrame() {return animationFrame;}

  bool isPressedOn() {return pressedOn;}

  bool isMouseInHitbox(int mouseX, int mouseY);

  void updateDragging();

  void renderStick();

  void killPlayer(int deathX, int deathY);
  void TOGGLE_FREE_MOVE() {freeFly = !freeFly;}
  
  bool returnIsDead() {return isDead;}
  SDL_Rect* getCollisionBox() {return &collisionBox;}

  
private:

  bool pressedOn;
  int distance;

  int framesInAir;
  int velocityX;
  int velocityY;

  bool freeFly;

  bool isDead;
  int holeX;
  int holeY;


  SDL_Rect collisionBox;
  PoolStick stick;
  

};

class Button : public Entity
{
public:
  Button();
  ~Button();

  void initButton(int xPos, int yPos, int w, int h, ButtonType buttonType);
  void isPressed(int mouseX, int mouseY);




private:

  bool pressedOn;
  ButtonType buttonType;

};

