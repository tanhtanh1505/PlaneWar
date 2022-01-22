#ifndef TA_H_
#define TA_H_

#include <SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<Windows.h>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>


static const int SCREEN_WIDTH = 1000;
static const int SCREEN_HEIGHT = 700;
static SDL_Window* window;
static SDL_Renderer* renderer;
static SDL_Event event;
static bool quit = false;

static SDL_Rect bg;
static SDL_Rect bgz;

static Mix_Chunk* bum = NULL;
static Mix_Chunk* gunSound = NULL;
static Mix_Music* brokenPlane = NULL;
static Mix_Music* music = NULL;

static TTF_Font* fontText = NULL;


using namespace std;

namespace TA
{
	void logSDLError(std::ostream& os, const std::string& msg, bool fatal);
	void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
	void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
	SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);
	bool checkCollision(SDL_Rect a, SDL_Rect b);

	
}

#endif 
