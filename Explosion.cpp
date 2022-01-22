#include "Explosion.h"

Explosion::Explosion()
{
	fps = 1;
}

Explosion::~Explosion()
{
}

void Explosion::showEx(SDL_Renderer* renderer, int x, int y)
{
	
	exp_.setRect(x, y);
	exp_.show(renderer);
}

void Explosion::broken_plane(SDL_Renderer* renderer, int x, int y)
{
	SDL_Rect rt;
	rt.x = x;
	rt.y = y;
	rt.w = 100;
	rt.h = 100;
	SDL_Rect rex;
	rex.w = e_width;
	rex.h = e_height;

	for (int exp = 0; exp < numRows; exp++) {
		for (int exps = 0; exps < numCols; exps++) {
			rex.x = exps * e_width;
			rex.y = exp * e_height;
			
			SDL_RenderCopy(renderer, brokenPl, &rex, &rt);
			SDL_RenderPresent(renderer);

			SDL_Delay(150);
			if (exp == 2 && exps == 1) break;
		}
		if (exp == 2) break;
	}
}
