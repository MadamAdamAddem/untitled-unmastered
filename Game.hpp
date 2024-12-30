#pragma once
#include "Rendering.hpp"
#include "Entities.hpp"

typedef struct Mouse
{

  int x;
  int y;
  bool isPressed = false;

}Mouse;

//i'd marry extern if i could
extern Mouse mouse;

enum ObstacleType : int;
class Player;
class Entity;
class Obstacle;
class Button;


class Menu
{
public:
  Menu();
  ~Menu();

  void renderMenu();

  int getX() {return menuX;}
  int getY() {return menuY;}



private:

  adamTexture* overlay;
  adamTexture* menuTexture;

  int menuX;
  int menuY;

};

class Level
{
public:
  Level();
  ~Level();

  void renderLevel();

  bool doCollision(SDL_Rect* collisionBox, int* velX, int* velY, int* framesInAir);
  bool checkNextLevelCollision();

  void clearLevel();

  void initializeLevel();

  void checkMouseClick();

  void loadTitle();
  void loadFirst();
  void loadSecond();
  void loadThird();
  void loadFourth();
  void loadFifth();
  void loadSixth();
  void loadSeventh();
  void loadEigth();
  void loadNinth();

  
private:

  bool doCollisionAdjustment(SDL_Rect* collisionBox, SDL_Rect* collisionBox2, int obsType, int* velX, int* velY, int* framesInAir);



  //first instance in array always used for the win area
  Entity* entityArray;

  Obstacle* obstacleArray;
  Button* buttonArray;

  int numEntities;
  int numObstacles;
  int numButtons;

  int leftWallX;
  int rightWallX;
  int roofY;
  int floorY;

};

class Game
{
public:

  Game();
  ~Game();
  
  void renderGame();
  

  void changeLevel(int levelNum);

  int getLevel() {return currLevel;}
  bool getMenuState() {return menuOpen;}
  void toggleMenu() {menuOpen = !menuOpen;}
  
  

  Player* player;
  Level level;

  adamTexture* backgroundTexture;
  adamTexture* wallTexture;
  adamTexture* winTexture;
  adamTexture* playerTexture;
  adamTexture* holeTexture;
  adamTexture* platformTexture;

private:

  Menu settingsMenu;
  bool menuOpen;

  int currLevel;
  
};


extern Game game;