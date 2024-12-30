#include "Rendering.hpp"

SDL_Rect wallSpriteClips[16];
SDL_Rect holeSpriteClips[16];



adamTexture::adamTexture()
{
  texture = NULL;
  tWidth = 0;
  tHeight = 0;
}

adamTexture::~adamTexture()
{
    free();
}

void adamTexture::free()
{
  if(texture == NULL) return;

  SDL_DestroyTexture(texture);
  tWidth = 0;
  tHeight = 0;
}

bool adamTexture::loadFromFile(std::string path, SDL_Renderer* renderer)
{
  free();

  texture = IMG_LoadTexture(renderer, path.c_str());
  if(texture == NULL)
  {
    std::cout << "Failed to load texture from file!" << std::endl;
    return false;
  }
    

  SDL_SetTextureScaleMode(texture, SDL_ScaleModeNearest);
  SDL_QueryTexture(texture, NULL, NULL, &tWidth, &tHeight);
  

  
  return true;

}

bool adamTexture::loadFromText(char* text, SDL_Color textColor, SDL_Renderer* renderer, TTF_Font* font)
{
    free();

    //SDL_Color bgColor = {0,0,0,0};
    
    SDL_Surface* tmpSurface = TTF_RenderUTF8_Blended(font, text, textColor);

    if(tmpSurface == NULL)
    {
        std::cout << "Text failure\n" << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    if(texture == NULL)
    {
        std::cout << "Text texture failure\n" << std::endl;
        return false;
    }

    tWidth = tmpSurface->w;
    tHeight = tmpSurface->h;

    SDL_FreeSurface(tmpSurface);
    SDL_SetTextureScaleMode(texture, SDL_ScaleModeBest);
    
    return true;
}

void adamTexture::render(int x, int y, SDL_Renderer* renderer, float stretchFactor, SDL_Rect* clip, double angle, SDL_Point center, SDL_Color colorMod)
{
    

  //area to render
  SDL_Rect renderSpace;
  renderSpace.x = x;
  renderSpace.y = y;
  renderSpace.w = tWidth * stretchFactor;
  renderSpace.h = tHeight * stretchFactor;
  


  if(center.x == 0 && center.y == 0)
  {
    center.x = renderSpace.w;
    center.y = 5;
  }

  if(clip != NULL)
  {
    renderSpace.w = clip->w*stretchFactor;
    renderSpace.h = clip->h*stretchFactor;
  }

  if(colorMod.a != 0)
    SDL_SetTextureColorMod(texture, colorMod.r, colorMod.g, colorMod.b);
  

  SDL_RenderCopyEx(renderer, texture, clip, &renderSpace, angle, &center, SDL_FLIP_NONE);
}

void adamTexture::setBlendMode(SDL_BlendMode blendMode)
{
    SDL_SetTextureBlendMode(texture, blendMode);
}

void adamTexture::setAlphaLevel(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(texture, alpha);
}

void adamTexture::replaceTexture(adamTexture* newTexture)
{
    texture = newTexture->texture;
    tWidth = newTexture->tWidth;
    tHeight = newTexture->tHeight;
}


// ------------------------------------------------------------

GameWindow::GameWindow()
{
  window = NULL;
  renderer = NULL;
  font = NULL;
  initAll(800, 600, &window, &renderer, &font);

}

GameWindow::~GameWindow()
{
  aSDL_Close();
}

SDL_Renderer* GameWindow::getRenderer()
{
  return renderer;
}

// ------------------------------------------------------------


//Initiates SDL, SDL_image, and SDL_TTF with a window
SDL_Window* ainitWindow(std::string windowName, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    SDL_Window* tempWindow = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL initialization failed\n");
        return NULL;
    }
    

    //Set texture filtering to linear
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) )
	{
		printf( "Linear texture filtering not enabled!\n" );
		return NULL;
	}

    tempWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(tempWindow == NULL)
    {
        printf("Window initialization failed\n");
        return NULL;
    } 
    int imgFlags = IMG_INIT_PNG;

    if(!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image initialization failed\n");
        return NULL;
    }

    //Initialize SDL_ttf
    if(TTF_Init() == -1)
    {
        printf( "SDL_ttf initialization failed\n");
        return NULL;
    }
    

    return tempWindow;
}

//Initiates a renderer with vsync optional
SDL_Renderer* ainitRenderer(SDL_Window* window, bool vsync)
{
    SDL_Renderer* tempRenderer = NULL;
    if(vsync)
        tempRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    else
        tempRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(tempRenderer == NULL)
    {
        std::cout << "Renderer Error" << SDL_GetError() << std::endl;
        return NULL;
    }

    SDL_SetRenderDrawColor(tempRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    return tempRenderer;
}



void initAll(int SCREENW, int SCREENH, SDL_Window** window, SDL_Renderer** renderer, TTF_Font** font)
{
  
  std::string fontString = "assets/Arial.ttf";

  *window = ainitWindow("Test Game", SCREENW, SCREENH);
  if(window == NULL)
      exit(1);

  *renderer = ainitRenderer(*window);
  if(renderer == NULL)
      exit(1);

  TTF_SetFontHinting(*font, TTF_HINTING_NORMAL);
  *font = TTF_OpenFont(fontString.c_str(), 100);
  if(*font == NULL)
      exit(1);

  
  
}

void aSDL_Close()
{
    /*
        Implement
    */

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}





