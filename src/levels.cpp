#include "Game.hpp"
#include "Entities.hpp"


void Level::loadTitle()
{
  const int nObs = 1;
  const int nEnt = 3;
  const int nBut = 1;

  game.backgroundTexture->loadFromFile("assets/backgrounds/mainMenu.png", gameWindow.getRenderer());

  leftWallX = 45;
  rightWallX = 760;
  roofY = 45;
  floorY = 555;


  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  obstacleArray[0].initObstacle("assets/playButton.png", -1, 348, 400, 104, 112, 4, ONE_WAY_LINE);


  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, -50, -50, 50, 50);
  entityArray[1].initGraphic("assets/titleNoEyes.png", 172, 100, 485, 155, -1);
  entityArray[2].initGraphic("assets/clickMe.png", 350, 380, 100, 20, -1);



  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(348, 400, 104, 112, NEXT_LEVEL);
  

  game.player = new Player(game.playerTexture, 300, floorY-20, 20, 20, -1);

  
  
}



//bronze world

void Level::loadFirst()
{

  game.backgroundTexture->loadFromFile("assets/backgrounds/oakBronze.png", gameWindow.getRenderer());
  game.wallTexture->loadFromFile("assets/bronzeSheet.png", gameWindow.getRenderer());
  

  leftWallX = 30;
  rightWallX = 770;
  roofY = 30;
  floorY = 570;

  const int nObs = 32;
  const int nEnt = 2;
  const int nBut = 1;


  {
  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];

  //bottom row
  obstacleArray[0].initObstacle(game.wallTexture, 12, 200, 500, 35, 35, 1.41);
  obstacleArray[1].initObstacle(game.wallTexture, 1, 235, 500, 35, 35, 1.41);
  obstacleArray[2].initObstacle(game.wallTexture, 1, 270, 500, 35, 35, 1.41);
  obstacleArray[3].initObstacle(game.wallTexture, 1, 305, 500, 35, 35, 1.41);
  obstacleArray[4].initObstacle(game.wallTexture, 1, 340, 500, 35, 35, 1.41);
  obstacleArray[5].initObstacle(game.wallTexture, 1, 375, 500, 35, 35, 1.41);
  obstacleArray[6].initObstacle(game.wallTexture, 1, 410, 500, 35, 35, 1.41);
  obstacleArray[7].initObstacle(game.wallTexture, 1, 445, 500, 35, 35, 1.41);
  obstacleArray[8].initObstacle(game.wallTexture, 1, 480, 500, 35, 35, 1.41);
  obstacleArray[9].initObstacle(game.wallTexture, 1, 515, 500, 35, 35, 1.41);
  obstacleArray[10].initObstacle(game.wallTexture, 1, 550, 500, 35, 35, 1.41);
  obstacleArray[11].initObstacle(game.wallTexture, 13, 585, 500, 35, 35, 1.41);


  //right platform
  obstacleArray[12].initObstacle(game.wallTexture, 12, 625, 415, 35, 35, 1.41);
  obstacleArray[13].initObstacle(game.wallTexture, 1, 660, 415, 35, 35, 1.41);
  obstacleArray[14].initObstacle(game.wallTexture, 1, 695, 415, 35, 35, 1.41);
  obstacleArray[15].initObstacle(game.wallTexture, 13, 730, 415, 35, 35, 1.41);

  obstacleArray[16].initObstacle(game.wallTexture, 12, 200, 330, 35, 35, 1.41);
  obstacleArray[17].initObstacle(game.wallTexture, 1, 235, 330, 35, 35, 1.41);
  obstacleArray[18].initObstacle(game.wallTexture, 1, 270, 330, 35, 35, 1.41);
  obstacleArray[19].initObstacle(game.wallTexture, 1, 305, 330, 35, 35, 1.41);
  obstacleArray[20].initObstacle(game.wallTexture, 1, 340, 330, 35, 35, 1.41);
  obstacleArray[21].initObstacle(game.wallTexture, 1, 375, 330, 35, 35, 1.41);
  obstacleArray[22].initObstacle(game.wallTexture, 1, 410, 330, 35, 35, 1.41);
  obstacleArray[23].initObstacle(game.wallTexture, 1, 445, 330, 35, 35, 1.41);
  obstacleArray[24].initObstacle(game.wallTexture, 1, 480, 330, 35, 35, 1.41);
  obstacleArray[25].initObstacle(game.wallTexture, 1, 515, 330, 35, 35, 1.41);
  obstacleArray[26].initObstacle(game.wallTexture, 1, 550, 330, 35, 35, 1.41);
  obstacleArray[27].initObstacle(game.wallTexture, 13, 585, 330, 35, 35, 1.41);

  obstacleArray[28].initObstacle(game.wallTexture, 12, 35, 245, 35, 35, 1.41);
  obstacleArray[29].initObstacle(game.wallTexture, 1, 70, 245, 35, 35, 1.41);
  obstacleArray[30].initObstacle(game.wallTexture, 1, 105, 245, 35, 35, 1.41);
  obstacleArray[31].initObstacle(game.wallTexture, 13, 140, 245, 35, 35, 1.41);
  }

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, 70, 185, 50, 50);
  entityArray[1].initGraphic("assets/pressEsc.png", 310, 400, 200, 80, -1);


  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);


  game.player = new Player(game.playerTexture, 100, floorY-20, 20, 20, -1);

}

void Level::loadSecond()
{

  game.backgroundTexture->loadFromFile("assets/backgrounds/oakBronze.png", gameWindow.getRenderer());
  game.wallTexture->loadFromFile("assets/bronzeSheet.png", gameWindow.getRenderer());
  

  leftWallX = 30;
  rightWallX = 770;
  roofY = 30;
  floorY = 570;

  const int nObs = 28;
  const int nEnt = 1;
  const int nBut = 1;

  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  {
  

  //mouth
  obstacleArray[0].initObstacle(game.wallTexture, 12, 190, 510, 35, 35, 1.41);
  obstacleArray[1].initObstacle(game.wallTexture, 1, 225, 510, 35, 35, 1.41);
  obstacleArray[2].initObstacle(game.wallTexture, 1, 260, 510, 35, 35, 1.41);
  obstacleArray[3].initObstacle(game.wallTexture, 1, 295, 510, 35, 35, 1.41);
  obstacleArray[4].initObstacle(game.wallTexture, 1, 330, 510, 35, 35, 1.41);
  obstacleArray[5].initObstacle(game.wallTexture, 1, 365, 510, 35, 35, 1.41);
  obstacleArray[6].initObstacle(game.wallTexture, 1, 400, 510, 35, 35, 1.41);
  obstacleArray[7].initObstacle(game.wallTexture, 1, 435, 510, 35, 35, 1.41);
  obstacleArray[8].initObstacle(game.wallTexture, 1, 470, 510, 35, 35, 1.41);
  obstacleArray[9].initObstacle(game.wallTexture, 1, 505, 510, 35, 35, 1.41);
  obstacleArray[10].initObstacle(game.wallTexture, 1, 540, 510, 35, 35, 1.41);
  obstacleArray[11].initObstacle(game.wallTexture, 13, 575, 510, 35, 35, 1.41);


  //nose holes
  obstacleArray[12].initObstacle(game.holeTexture, 14, 330, 450, 24, 60, 3, DEATH_HOLE_L);
  obstacleArray[13].initObstacle(game.holeTexture, 10, 445, 450, 24, 60, 3, DEATH_HOLE_R);

  //nose
  obstacleArray[14].initObstacle(game.wallTexture, 12, 330, 420, 35, 35, 1.41);
  obstacleArray[15].initObstacle(game.wallTexture, 1, 365, 420, 35, 35, 1.41);
  obstacleArray[16].initObstacle(game.wallTexture, 1, 400, 420, 35, 35, 1.41);
  obstacleArray[17].initObstacle(game.wallTexture, 13, 435, 420, 35, 35, 1.41);


  //Left eye
  obstacleArray[18].initObstacle(game.wallTexture, 12, 190, 325, 35, 35, 1.41);
  obstacleArray[19].initObstacle(game.wallTexture, 1, 225, 325, 35, 35, 1.41);
  obstacleArray[20].initObstacle(game.wallTexture, 1, 260, 325, 35, 35, 1.41);
  obstacleArray[21].initObstacle(game.wallTexture, 13, 295, 325, 35, 35, 1.41);

  //Right eye
  obstacleArray[22].initObstacle(game.wallTexture, 12, 470, 330, 35, 35, 1.41);
  obstacleArray[23].initObstacle(game.wallTexture, 1, 505, 330, 35, 35, 1.41);
  obstacleArray[24].initObstacle(game.wallTexture, 1, 540, 330, 35, 35, 1.41);
  obstacleArray[25].initObstacle(game.wallTexture, 13, 575, 330, 35, 35, 1.41);

  //unibrow
  obstacleArray[26].initObstacle(game.wallTexture, 12, 365, 250, 35, 35, 1.41);
  obstacleArray[27].initObstacle(game.wallTexture, 13, 400, 250, 35, 35, 1.41);


  }

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, 375, 185, 50, 50);


  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);


  game.player = new Player(game.playerTexture, 100, floorY-20, 20, 20, -1);

}

void Level::loadThird()
{
  game.backgroundTexture->loadFromFile("assets/backgrounds/oakBronze.png", gameWindow.getRenderer()); 
  game.wallTexture->loadFromFile("assets/bronzeSheet.png", gameWindow.getRenderer());
  
  leftWallX = 30;
  rightWallX = 770;
  roofY = 30;
  floorY = 570;

  const int nObs = 23;
  const int nEnt = 1;
  const int nBut = 1;

  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  {
    //entrance holes (ayo?)
    obstacleArray[0].initObstacle(game.holeTexture, 11, 317, 375, 48, 120, 6.0F, DEATH_HOLE_U | DEATH_HOLE_L | DEATH_HOLE_R);
    obstacleArray[1].initObstacle(game.holeTexture, 11, 435, 375, 48, 120, 6.0F, DEATH_HOLE_U | DEATH_HOLE_L | DEATH_HOLE_R);

    //entrance oneways
    obstacleArray[2].initObstacle(game.platformTexture, -1, 365, 380, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[3].initObstacle(game.platformTexture, -1, 365, 435, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[4].initObstacle(game.platformTexture, -1, 365, 490, 70, 17, 1.75F, ONE_WAY_LINE);

    //side platforms
    obstacleArray[5].initObstacle(game.wallTexture, 12, 175, 345, 35, 35, 1.41);
    obstacleArray[6].initObstacle(game.wallTexture, 1, 210, 345, 35, 35, 1.41);
    obstacleArray[7].initObstacle(game.wallTexture, 13, 245, 345, 35, 35, 1.41);
    
    obstacleArray[8].initObstacle(game.wallTexture, 12, 520, 345, 35, 35, 1.41);
    obstacleArray[9].initObstacle(game.wallTexture, 1, 555, 345, 35, 35, 1.41);
    obstacleArray[10].initObstacle(game.wallTexture, 13, 590, 345, 35, 35, 1.41);

    //high side platforms
    obstacleArray[11].initObstacle(game.wallTexture, 12, 70, 260, 35, 35, 1.41);
    obstacleArray[12].initObstacle(game.wallTexture, 13, 105, 260, 35, 35, 1.41);

    obstacleArray[13].initObstacle(game.wallTexture, 12, 660, 260, 35, 35, 1.41);
    obstacleArray[14].initObstacle(game.wallTexture, 13, 695, 260, 35, 35, 1.41);

    //top holes
    obstacleArray[15].initObstacle(game.holeTexture, 9, 370, 136, 35, 87, 4.375F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);
    obstacleArray[16].initObstacle(game.holeTexture, 9, 395, 136, 35, 87, 4.375F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);

    //top platforms
    obstacleArray[17].initObstacle(game.wallTexture, 12, 295, 220, 35, 35, 1.41);
    obstacleArray[18].initObstacle(game.wallTexture, 1, 330, 220, 35, 35, 1.41);
    obstacleArray[19].initObstacle(game.wallTexture, 1, 365, 220, 35, 35, 1.41);
    obstacleArray[20].initObstacle(game.wallTexture, 1, 400, 220, 35, 35, 1.41);
    obstacleArray[21].initObstacle(game.wallTexture, 1, 435, 220, 35, 35, 1.41);
    obstacleArray[22].initObstacle(game.wallTexture, 13, 470, 220, 35, 35, 1.41);

    


  }

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, 375, 50, 50, 50);

  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);

  game.player = new Player(game.playerTexture, 100, floorY-20, 20, 20, -1);

}



//silver world

void Level::loadFourth()
{
  game.backgroundTexture->loadFromFile("assets/backgrounds/oakSilver.png", gameWindow.getRenderer()); 
  game.wallTexture->loadFromFile("assets/silverSheet.png", gameWindow.getRenderer());
  
  leftWallX = 30;
  rightWallX = 770;
  roofY = 30;
  floorY = 570;

  const int nObs = 18;
  const int nEnt = 1;
  const int nBut = 1;


  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  {
    obstacleArray[0].initObstacle(game.wallTexture, 12, 35, 515, 35, 35, 1.41);
    obstacleArray[1].initObstacle(game.wallTexture, 1, 70, 515, 35, 35, 1.41);
    obstacleArray[2].initObstacle(game.wallTexture, 13, 105, 515, 35, 35, 1.41);


    obstacleArray[3].initObstacle(game.wallTexture, 12, 345, 465, 35, 35, 1.41);
    obstacleArray[4].initObstacle(game.wallTexture, 1, 380, 465, 35, 35, 1.41);
    obstacleArray[5].initObstacle(game.wallTexture, 13, 415, 465, 35, 35, 1.41);

 
    obstacleArray[6].initObstacle(game.wallTexture, 12, 660, 415, 35, 35, 1.41);
    obstacleArray[7].initObstacle(game.wallTexture, 1, 695, 415, 35, 35, 1.41);
    obstacleArray[8].initObstacle(game.wallTexture, 13, 730, 415, 35, 35, 1.41);


    obstacleArray[9].initObstacle(game.wallTexture, 12, 345, 365, 35, 35, 1.41);
    obstacleArray[10].initObstacle(game.wallTexture, 1, 380, 365, 35, 35, 1.41);
    obstacleArray[11].initObstacle(game.wallTexture, 13, 415, 365, 35, 35, 1.41);


    obstacleArray[12].initObstacle(game.wallTexture, 12, 35, 315, 35, 35, 1.41);
    obstacleArray[13].initObstacle(game.wallTexture, 1, 70, 315, 35, 35, 1.41);
    obstacleArray[14].initObstacle(game.wallTexture, 13, 105, 315, 35, 35, 1.41);

    obstacleArray[15].initObstacle(game.wallTexture, 12, 345, 265, 35, 35, 1.41);
    obstacleArray[16].initObstacle(game.wallTexture, 1, 380, 265, 35, 35, 1.41);
    obstacleArray[17].initObstacle(game.wallTexture, 13, 415, 265, 35, 35, 1.41);
  }

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, 690, 185, 50, 50);


  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);

  game.player = new Player(game.playerTexture, 100, 515-20, 20, 20, -1);

}

void Level::loadFifth()
{
  game.backgroundTexture->loadFromFile("assets/backgrounds/oakSilver.png", gameWindow.getRenderer()); 
  game.wallTexture->loadFromFile("assets/silverSheet.png", gameWindow.getRenderer());
  
  leftWallX = 30;
  rightWallX = 770;
  roofY = 30;
  floorY = 570;

  const int nObs = 29;
  const int nEnt = 1;
  const int nBut = 1;


  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  {
    //death pit
    obstacleArray[0].initObstacle(game.holeTexture, 1, 35, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[1].initObstacle(game.holeTexture, 2, 95, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[2].initObstacle(game.holeTexture, 2, 155, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[3].initObstacle(game.holeTexture, 2, 215, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[4].initObstacle(game.holeTexture, 2, 275, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[5].initObstacle(game.holeTexture, 2, 335, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[6].initObstacle(game.holeTexture, 2, 395, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[7].initObstacle(game.holeTexture, 2, 455, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[8].initObstacle(game.holeTexture, 2, 515, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[9].initObstacle(game.holeTexture, 2, 575, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[10].initObstacle(game.holeTexture, 2, 635, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[11].initObstacle(game.holeTexture, 2, 645, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[12].initObstacle(game.holeTexture, 3, 705, 546, 60, 24, 3.0F, DEATH_HOLE_U);

    //left platform walls
    obstacleArray[13].initObstacle(game.holeTexture, 9, 65, 443, 24, 60, 3.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);
    obstacleArray[14].initObstacle(game.holeTexture, 9, 146, 443, 24, 60, 3.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);

    //left platform
    obstacleArray[15].initObstacle(game.wallTexture, 12, 65, 500, 35, 35, 1.41);
    obstacleArray[16].initObstacle(game.wallTexture, 1, 100, 500, 35, 35, 1.41);
    obstacleArray[17].initObstacle(game.wallTexture, 13, 135, 500, 35, 35, 1.41);

    //
    obstacleArray[18].initObstacle(game.holeTexture, 9, 230, 403, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);
    obstacleArray[19].initObstacle(game.holeTexture, 9, 247, 403, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);

    obstacleArray[20].initObstacle(game.holeTexture, 9, 330, 363, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);
    obstacleArray[21].initObstacle(game.holeTexture, 9, 347, 363, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);

    obstacleArray[22].initObstacle(game.holeTexture, 9, 430, 323, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);
    obstacleArray[23].initObstacle(game.holeTexture, 9, 447, 323, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);

    obstacleArray[24].initObstacle(game.holeTexture, 9, 530, 283, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);
    obstacleArray[25].initObstacle(game.holeTexture, 9, 547, 283, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);

    obstacleArray[26].initObstacle(game.holeTexture, 9, 630, 243, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);
    obstacleArray[27].initObstacle(game.holeTexture, 9, 647, 243, 32, 80, 4.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_D);

    obstacleArray[28].initObstacle(game.platformTexture, -1, 695, 173, 70, 17, 1.75F, ONE_WAY_LINE);



  }

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, 707, 60, 50, 50);


  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);

  game.player = new Player(game.playerTexture, 105, 480, 20, 20, -1);

}

void Level::loadSixth()
{
  
  game.backgroundTexture->loadFromFile("assets/backgrounds/oakSilver.png", gameWindow.getRenderer()); 
  game.wallTexture->loadFromFile("assets/silverSheet.png", gameWindow.getRenderer());
  
  leftWallX = 30;
  rightWallX = 770;
  roofY = 30;
  floorY = 570;

  const int nObs = 70;
  const int nEnt = 1;
  const int nBut = 1;


  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  {  
  //bottom floor
  obstacleArray[0].initObstacle(game.wallTexture, 12, 205, 510, 35, 35, 1.41F);
  obstacleArray[1].initObstacle(game.wallTexture, 1, 240, 510, 35, 35, 1.41F);
  obstacleArray[2].initObstacle(game.wallTexture, 1, 275, 510, 35, 35, 1.41F);
  obstacleArray[3].initObstacle(game.wallTexture, 1, 310, 510, 35, 35, 1.41F);
  obstacleArray[4].initObstacle(game.wallTexture, 1, 345, 510, 35, 35, 1.41F);
  obstacleArray[5].initObstacle(game.wallTexture, 1, 380, 510, 35, 35, 1.41F);
  obstacleArray[6].initObstacle(game.wallTexture, 1, 415, 510, 35, 35, 1.41F);
  obstacleArray[7].initObstacle(game.wallTexture, 1, 450, 510, 35, 35, 1.41F);
  obstacleArray[8].initObstacle(game.wallTexture, 1, 485, 510, 35, 35, 1.41F);
  obstacleArray[9].initObstacle(game.wallTexture, 1, 520, 510, 35, 35, 1.41F);
  obstacleArray[10].initObstacle(game.wallTexture, 1, 555, 510, 35, 35, 1.41F);
  obstacleArray[11].initObstacle(game.wallTexture, 1, 590, 510, 35, 35, 1.41F);
  obstacleArray[12].initObstacle(game.wallTexture, 1, 625, 510, 35, 35, 1.41F);
  obstacleArray[13].initObstacle(game.wallTexture, 1, 660, 510, 35, 35, 1.41F);
  obstacleArray[14].initObstacle(game.wallTexture, 1, 695, 510, 35, 35, 1.41F);
  obstacleArray[15].initObstacle(game.wallTexture, 10, 730, 510, 35, 35, 1.41F);

   //right wall
  obstacleArray[16].initObstacle(game.wallTexture, 6, 730, 475, 35, 35, 1.41F);
  obstacleArray[17].initObstacle(game.wallTexture, 6, 730, 440, 35, 35, 1.41F);
  obstacleArray[18].initObstacle(game.wallTexture, 6, 730, 405, 35, 35, 1.41F);
  obstacleArray[19].initObstacle(game.wallTexture, 6, 730, 370, 35, 35, 1.41F);

  obstacleArray[20].initObstacle(game.wallTexture, 6, 730, 335, 35, 35, 1.41F);

  obstacleArray[21].initObstacle(game.wallTexture, 6, 730, 300, 35, 35, 1.41F);
  obstacleArray[22].initObstacle(game.wallTexture, 6, 730, 265, 35, 35, 1.41F);
  obstacleArray[23].initObstacle(game.wallTexture, 6, 730, 230, 35, 35, 1.41F);
  obstacleArray[24].initObstacle(game.wallTexture, 6, 730, 195, 35, 35, 1.41F);

  //roof
  obstacleArray[25].initObstacle(game.wallTexture, 12, 205, 160, 35, 35, 1.41F);
  obstacleArray[26].initObstacle(game.wallTexture, 1, 240, 160, 35, 35, 1.41F);
  obstacleArray[27].initObstacle(game.wallTexture, 1, 275, 160, 35, 35, 1.41F);
  obstacleArray[28].initObstacle(game.wallTexture, 1, 310, 160, 35, 35, 1.41F);
  obstacleArray[29].initObstacle(game.wallTexture, 1, 345, 160, 35, 35, 1.41F);
  obstacleArray[30].initObstacle(game.wallTexture, 1, 380, 160, 35, 35, 1.41F);
  obstacleArray[31].initObstacle(game.wallTexture, 1, 415, 160, 35, 35, 1.41F);
  obstacleArray[32].initObstacle(game.wallTexture, 1, 450, 160, 35, 35, 1.41F);
  obstacleArray[33].initObstacle(game.wallTexture, 1, 485, 160, 35, 35, 1.41F);
  obstacleArray[34].initObstacle(game.wallTexture, 1, 520, 160, 35, 35, 1.41F);
  obstacleArray[35].initObstacle(game.wallTexture, 1, 555, 160, 35, 35, 1.41F);
  obstacleArray[36].initObstacle(game.wallTexture, 1, 590, 160, 35, 35, 1.41F);
  obstacleArray[37].initObstacle(game.wallTexture, 1, 625, 160, 35, 35, 1.41F);
  obstacleArray[38].initObstacle(game.wallTexture, 1, 660, 160, 35, 35, 1.41F);
  obstacleArray[39].initObstacle(game.wallTexture, 1, 695, 160, 35, 35, 1.41F);
  obstacleArray[40].initObstacle(game.wallTexture, 2, 730, 160, 35, 35, 1.41F);

  //middle floor
  obstacleArray[41].initObstacle(game.wallTexture, 12, 205, 335, 35, 35, 1.41F);
  obstacleArray[42].initObstacle(game.wallTexture, 1, 240, 335, 35, 35, 1.41F);
  obstacleArray[43].initObstacle(game.wallTexture, 1, 275, 335, 35, 35, 1.41F);
  obstacleArray[44].initObstacle(game.wallTexture, 1, 310, 335, 35, 35, 1.41F);
  obstacleArray[45].initObstacle(game.wallTexture, 1, 345, 335, 35, 35, 1.41F);
  obstacleArray[46].initObstacle(game.wallTexture, 1, 380, 335, 35, 35, 1.41F);
  obstacleArray[47].initObstacle(game.wallTexture, 1, 415, 335, 35, 35, 1.41F);
  obstacleArray[48].initObstacle(game.wallTexture, 1, 450, 335, 35, 35, 1.41F);
  obstacleArray[49].initObstacle(game.wallTexture, 1, 485, 335, 35, 35, 1.41F);
  obstacleArray[50].initObstacle(game.wallTexture, 1, 520, 335, 35, 35, 1.41F);
  obstacleArray[51].initObstacle(game.wallTexture, 1, 555, 335, 35, 35, 1.41F);
  obstacleArray[52].initObstacle(game.wallTexture, 1, 590, 335, 35, 35, 1.41F);
  obstacleArray[53].initObstacle(game.wallTexture, 13, 625, 335, 35, 35, 1.41F);

  //bottom floor holes
  obstacleArray[54].initObstacle(game.holeTexture, 13, 330, 450, 24, 60, 3.0F, DEATH_HOLE_L | DEATH_HOLE_U);
  obstacleArray[55].initObstacle(game.holeTexture, 13, 348, 450, 24, 60, 3.0F, DEATH_HOLE_R | DEATH_HOLE_U);

  obstacleArray[56].initObstacle(game.holeTexture, 9, 430, 370, 24, 60, 3.0F, DEATH_HOLE_L | DEATH_HOLE_D);
  obstacleArray[57].initObstacle(game.holeTexture, 9, 448, 370, 24, 60, 3.0F, DEATH_HOLE_R | DEATH_HOLE_U);

  obstacleArray[58].initObstacle(game.holeTexture, 13, 525, 450, 24, 60, 3.0F, DEATH_HOLE_L | DEATH_HOLE_U);
  obstacleArray[59].initObstacle(game.holeTexture, 13, 543, 450, 24, 60, 3.0F, DEATH_HOLE_R | DEATH_HOLE_U);

  obstacleArray[60].initObstacle(game.holeTexture, 9, 618, 370, 24, 60, 3.0F, DEATH_HOLE_L | DEATH_HOLE_D);
  obstacleArray[61].initObstacle(game.holeTexture, 9, 636, 370, 24, 60, 3.0F, DEATH_HOLE_R | DEATH_HOLE_U);



  //one way platforms
  obstacleArray[62].initObstacle(game.platformTexture, -1, 660, 370, 70, 17, 1.75F, ONE_WAY_LINE);
  obstacleArray[63].initObstacle(game.platformTexture, -1, 660, 425, 70, 17, 1.75F, ONE_WAY_LINE);


  //middle floor holes
  obstacleArray[64].initObstacle(game.holeTexture, 1, 205, 318, 40, 16, 2.0F, DEATH_HOLE_U | DEATH_HOLE_R);
  obstacleArray[65].initObstacle(game.holeTexture, 3, 245, 318, 40, 16, 2.0F, DEATH_HOLE_U | DEATH_HOLE_L);

  obstacleArray[66].initObstacle(game.holeTexture, 1, 355, 318, 40, 16, 2.0F, DEATH_HOLE_U | DEATH_HOLE_R);
  obstacleArray[67].initObstacle(game.holeTexture, 3, 395, 318, 40, 16, 2.0F, DEATH_HOLE_U | DEATH_HOLE_L);

  obstacleArray[68].initObstacle(game.holeTexture, 1, 505, 318, 40, 16, 2.0F, DEATH_HOLE_U | DEATH_HOLE_R);
  obstacleArray[69].initObstacle(game.holeTexture, 3, 545, 318, 40, 16, 2.0F, DEATH_HOLE_U | DEATH_HOLE_L);

  }

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, 75, 225, 75, 75);


  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);


  game.player = new Player(game.playerTexture, 100, floorY-20, 20, 20, -1);

}



//gold world

void Level::loadSeventh()
{
  game.backgroundTexture->loadFromFile("assets/backgrounds/oakGold.png", gameWindow.getRenderer()); 
  game.wallTexture->loadFromFile("assets/goldSheet.png", gameWindow.getRenderer());
  
  leftWallX = 30;
  rightWallX = 770;
  roofY = 30;
  floorY = 570;

  const int nObs = 50;
  const int nEnt = 1;
  const int nBut = 1;


  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  {
    //left platforms
    obstacleArray[0].initObstacle(game.platformTexture, -1, 35, 500, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[1].initObstacle(game.platformTexture, -1, 80, 500, 70, 17, 1.75F, ONE_WAY_LINE);

    obstacleArray[2].initObstacle(game.platformTexture, -1, 250, 400, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[3].initObstacle(game.platformTexture, -1, 295, 400, 70, 17, 1.75F, ONE_WAY_LINE);

    obstacleArray[4].initObstacle(game.platformTexture, -1, 35, 300, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[5].initObstacle(game.platformTexture, -1, 80, 300, 70, 17, 1.75F, ONE_WAY_LINE);

    obstacleArray[6].initObstacle(game.platformTexture, -1, 250, 200, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[7].initObstacle(game.platformTexture, -1, 295, 200, 70, 17, 1.75F, ONE_WAY_LINE);

    //center pillar
    obstacleArray[8].initObstacle(game.wallTexture, 8, 365, 530, 35, 35, 1.41F);
    obstacleArray[9].initObstacle(game.wallTexture, 10, 400, 530, 35, 35, 1.41F);
    obstacleArray[10].initObstacle(game.wallTexture, 4, 365, 495, 35, 35, 1.41F);
    obstacleArray[11].initObstacle(game.wallTexture, 4, 400, 495, 35, 35, 1.41F);
    obstacleArray[12].initObstacle(game.wallTexture, 4, 365, 460, 35, 35, 1.41F);
    obstacleArray[13].initObstacle(game.wallTexture, 4, 400, 460, 35, 35, 1.41F);
    obstacleArray[14].initObstacle(game.wallTexture, 4, 365, 425, 35, 35, 1.41F);
    obstacleArray[15].initObstacle(game.wallTexture, 4, 400, 425, 35, 35, 1.41F);
    obstacleArray[16].initObstacle(game.wallTexture, 4, 365, 390, 35, 35, 1.41F);
    obstacleArray[17].initObstacle(game.wallTexture, 4, 400, 390, 35, 35, 1.41F);
    obstacleArray[18].initObstacle(game.wallTexture, 4, 365, 355, 35, 35, 1.41F);
    obstacleArray[19].initObstacle(game.wallTexture, 4, 400, 355, 35, 35, 1.41F);
    obstacleArray[20].initObstacle(game.wallTexture, 4, 365, 320, 35, 35, 1.41F);
    obstacleArray[21].initObstacle(game.wallTexture, 4, 400, 320, 35, 35, 1.41F);
    obstacleArray[22].initObstacle(game.wallTexture, 4, 365, 285, 35, 35, 1.41F);
    obstacleArray[23].initObstacle(game.wallTexture, 4, 400, 285, 35, 35, 1.41F);
    obstacleArray[24].initObstacle(game.wallTexture, 4, 365, 250, 35, 35, 1.41F);
    obstacleArray[25].initObstacle(game.wallTexture, 4, 400, 250, 35, 35, 1.41F);
    obstacleArray[26].initObstacle(game.wallTexture, 4, 365, 215, 35, 35, 1.41F);
    obstacleArray[27].initObstacle(game.wallTexture, 4, 400, 215, 35, 35, 1.41F);
    obstacleArray[28].initObstacle(game.wallTexture, 4, 365, 180, 35, 35, 1.41F);
    obstacleArray[29].initObstacle(game.wallTexture, 4, 400, 180, 35, 35, 1.41F);
    obstacleArray[30].initObstacle(game.wallTexture, 0, 365, 145, 35, 35, 1.41F);
    obstacleArray[31].initObstacle(game.wallTexture, 2, 400, 145, 35, 35, 1.41F);

    //ball holes
    obstacleArray[32].initObstacle(game.holeTexture, 8, 383, 118, 33, 27, 3.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_U | DEATH_HOLE_D);
    obstacleArray[33].initObstacle(game.holeTexture, 12, 383, 35, 33, 27, 3.0F, DEATH_HOLE_L | DEATH_HOLE_R | DEATH_HOLE_U | DEATH_HOLE_D);

    //right side top platform
    obstacleArray[34].initObstacle(game.platformTexture, -1, 550, 200, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[35].initObstacle(game.platformTexture, -1, 595, 200, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[36].initObstacle(game.platformTexture, -1, 435, 200, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[37].initObstacle(game.platformTexture, -1, 480, 200, 70, 17, 1.75F, ONE_WAY_LINE);

    //right side low platform
    obstacleArray[38].initObstacle(game.platformTexture, -1, 550, 400, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[39].initObstacle(game.platformTexture, -1, 595, 400, 70, 17, 1.75F, ONE_WAY_LINE);


    //left floor death pit
    obstacleArray[40].initObstacle(game.holeTexture, 1, 35, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[41].initObstacle(game.holeTexture, 2, 95, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[42].initObstacle(game.holeTexture, 2, 155, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[43].initObstacle(game.holeTexture, 2, 215, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[44].initObstacle(game.holeTexture, 2, 275, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[45].initObstacle(game.holeTexture, 3, 305, 546, 60, 24, 3.0F, DEATH_HOLE_U);


    //right floor pits
    obstacleArray[46].initObstacle(game.holeTexture, 1, 435, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[47].initObstacle(game.holeTexture, 3, 487, 546, 60, 24, 3.0F, DEATH_HOLE_U);

    obstacleArray[48].initObstacle(game.holeTexture, 1, 665, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[49].initObstacle(game.holeTexture, 3, 705, 546, 60, 24, 3.0F, DEATH_HOLE_U);

  }

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, 580, 425, 50, 50);


  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);

  game.player = new Player(game.playerTexture, 75, 480, 20, 20, -1);

}

void Level::loadEigth()
{
  game.backgroundTexture->loadFromFile("assets/backgrounds/oakGold.png", gameWindow.getRenderer()); 
  game.wallTexture->loadFromFile("assets/goldSheet.png", gameWindow.getRenderer());
  
  leftWallX = 30;
  rightWallX = 770;
  roofY = 30;
  floorY = 570;

  const int nObs = 54;
  const int nEnt = 1;
  const int nBut = 1;


  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  {
    //center "pillar"
    obstacleArray[0].initObstacle(game.wallTexture, 8, 365, 535, 35, 35, 1.41F);
    obstacleArray[1].initObstacle(game.wallTexture, 10, 400, 535, 35, 35, 1.41F);
    obstacleArray[2].initObstacle(game.wallTexture, 0, 365, 500, 35, 35, 1.41F);
    obstacleArray[3].initObstacle(game.wallTexture, 2, 400, 500, 35, 35, 1.41F);

    obstacleArray[4].initObstacle(game.wallTexture, 8, 365, 380, 35, 35, 1.41F);
    obstacleArray[5].initObstacle(game.wallTexture, 10, 400, 380, 35, 35, 1.41F);
    obstacleArray[6].initObstacle(game.wallTexture, 0, 365, 345, 35, 35, 1.41F);
    obstacleArray[7].initObstacle(game.wallTexture, 2, 400, 345, 35, 35, 1.41F);

    obstacleArray[8].initObstacle(game.wallTexture, 8, 330, 225, 35, 35, 1.41F);
    obstacleArray[9].initObstacle(game.wallTexture, 10, 435, 225, 35, 35, 1.41F);
    obstacleArray[10].initObstacle(game.wallTexture, 9, 365, 225, 35, 35, 1.41F);
    obstacleArray[11].initObstacle(game.wallTexture, 9, 400, 225, 35, 35, 1.41F);
    obstacleArray[12].initObstacle(game.wallTexture, 9, 365, 190, 35, 35, 1.41F);
    obstacleArray[13].initObstacle(game.wallTexture, 9, 400, 190, 35, 35, 1.41F);
    obstacleArray[14].initObstacle(game.wallTexture, 0, 330, 190, 35, 35, 1.41F);
    obstacleArray[15].initObstacle(game.wallTexture, 2, 435, 190, 35, 35, 1.41F);

    obstacleArray[16].initObstacle(game.wallTexture, 8, 365, 65, 35, 35, 1.41F);
    obstacleArray[17].initObstacle(game.wallTexture, 10, 400, 65, 35, 35, 1.41F);
    obstacleArray[18].initObstacle(game.wallTexture, 0, 365, 30, 35, 35, 1.41F);
    obstacleArray[19].initObstacle(game.wallTexture, 2, 400, 30, 35, 35, 1.41F);


    //left floor pits
    obstacleArray[20].initObstacle(game.holeTexture, 1, 35, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[21].initObstacle(game.holeTexture, 2, 95, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[22].initObstacle(game.holeTexture, 2, 155, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[23].initObstacle(game.holeTexture, 2, 215, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[24].initObstacle(game.holeTexture, 2, 275, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[25].initObstacle(game.holeTexture, 3, 305, 546, 60, 24, 3.0F, DEATH_HOLE_U);


    //right floor pits
    obstacleArray[26].initObstacle(game.holeTexture, 1, 435, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[27].initObstacle(game.holeTexture, 2, 495, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[28].initObstacle(game.holeTexture, 2, 555, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[29].initObstacle(game.holeTexture, 2, 615, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[30].initObstacle(game.holeTexture, 2, 665, 546, 60, 24, 3.0F, DEATH_HOLE_U);
    obstacleArray[31].initObstacle(game.holeTexture, 3, 705, 546, 60, 24, 3.0F, DEATH_HOLE_U);


    //bottom left platforms
    obstacleArray[32].initObstacle(game.platformTexture, -1, 55, 510, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[33].initObstacle(game.platformTexture, -1, 90, 510, 70, 17, 1.75F, ONE_WAY_LINE);

    obstacleArray[34].initObstacle(game.platformTexture, -1, 230, 510, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[35].initObstacle(game.platformTexture, -1, 265, 510, 70, 17, 1.75F, ONE_WAY_LINE);


    //bottom holes
    obstacleArray[36].initObstacle(game.holeTexture, 1, 365, 485, 40, 16, 2.0F, DEATH_HOLE_U);
    obstacleArray[37].initObstacle(game.holeTexture, 3, 395, 485, 40, 16, 2.0F, DEATH_HOLE_U);

    obstacleArray[38].initObstacle(game.holeTexture, 5, 365, 414, 40, 16, 2.0F, DEATH_HOLE_D);
    obstacleArray[39].initObstacle(game.holeTexture, 7, 395, 414, 40, 16, 2.0F, DEATH_HOLE_D);

    //bottom right platforms
    obstacleArray[40].initObstacle(game.platformTexture, -1, 550, 505, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[41].initObstacle(game.platformTexture, -1, 585, 505, 70, 17, 1.75F, ONE_WAY_LINE);

    obstacleArray[42].initObstacle(game.platformTexture, -1, 660, 425, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[43].initObstacle(game.platformTexture, -1, 695, 425, 70, 17, 1.75F, ONE_WAY_LINE);

    obstacleArray[44].initObstacle(game.platformTexture, -1, 550, 345, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[45].initObstacle(game.platformTexture, -1, 585, 345, 70, 17, 1.75F, ONE_WAY_LINE);

    //
    obstacleArray[46].initObstacle(game.platformTexture, -1, 230, 387, 70, 17, 1.75F, ONE_WAY_LINE);
    obstacleArray[47].initObstacle(game.platformTexture, -1, 265, 387, 70, 17, 1.75F, ONE_WAY_LINE);

    obstacleArray[48].initObstacle(game.wallTexture, 12, 90, 347, 35, 35, 1.41F);
    obstacleArray[49].initObstacle(game.wallTexture, 13, 125, 347, 35, 35, 1.41F);

    obstacleArray[50].initObstacle(game.wallTexture, 12, 90, 257, 35, 35, 1.41F);
    obstacleArray[51].initObstacle(game.wallTexture, 13, 125, 257, 35, 35, 1.41F);

    obstacleArray[52].initObstacle(game.wallTexture, 12, 90, 167, 35, 35, 1.41F);
    obstacleArray[53].initObstacle(game.wallTexture, 13, 125, 167, 35, 35, 1.41F);

  }

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, 575, 120, 50, 50);


  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);

  game.player = new Player(game.playerTexture, 75, 490, 20, 20, -1);

}


//end :)

void Level::loadNinth()
{
  game.backgroundTexture->loadFromFile("assets/backgrounds/mainMenu.png", gameWindow.getRenderer()); 
  game.wallTexture->loadFromFile("assets/goldSheet.png", gameWindow.getRenderer());
  
  leftWallX = 45;
  rightWallX = 760;
  roofY = 45;
  floorY = 555;

  const int nObs = 1;
  const int nEnt = 3;
  const int nBut = 1;

  numObstacles = nObs;
  obstacleArray = new Obstacle[nObs];
  obstacleArray[0].initObstacle(game.wallTexture, 0, -100, -100, 35, 35, 1.4F);

  numEntities = nEnt;
  entityArray = new Entity[nEnt];
  entityArray[0].initEntity(game.winTexture, -100, -120, 50, 50);
  entityArray[1].initGraphic("assets/titleNoEyes.png", 172, 100, 485, 155, -1);
  entityArray[2].initGraphic("assets/horror.png", 282, 330, 236, 170, -1);

  numButtons = nBut;
  buttonArray = new Button[nBut];
  buttonArray[0].initButton(-100, -100, 25, 25, NEXT_LEVEL);

  game.player = new Player(game.playerTexture, 387, floorY-20, 20, 20, -1);

}


void Level::initializeLevel()
{

  clearLevel();

  switch(game.getLevel())
  {
    case 0:
      loadTitle();
      break;
    case 1:
      loadFirst();
      break;
    case 2:
      loadSecond();
      break;
    case 3:
      loadThird();
      break;
    case 4:
      loadFourth();
      break;
    case 5:
      loadFifth();
      break;
    case 6:
      loadSixth();
      break;
    case 7:
      loadSeventh();
      break;
    case 8:
      loadEigth();
      break;
    case 9:
      loadNinth();
      break;
    default:
      printf("invalid level\n");
      break;
  }
  
}