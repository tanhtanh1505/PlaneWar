#pragma once
#include"ta.h"
#include"Object.h"

const int numRows = 3;
const int numCols = 5;
const int e_width = 192;
const int e_height = 192;

class Explosion:public Object
{
private:
	int fps;
	SDL_Rect rct[4];
	SDL_Texture* exp;
	
public:
	Object exp_;
	SDL_Texture* brokenPl;
	Explosion();
	~Explosion();

	void showEx(SDL_Renderer* renderer, int x, int y);
	void broken_plane(SDL_Renderer* renderer, int x, int y);
};

