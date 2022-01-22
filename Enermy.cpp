#include "Enermy.h"

Enermy::Enermy()
{
	rect.w = 50;
	rect.h = 50;
	speed = rand()%2 +2 ;
	e_p.setRect(rect.x + rect.w / 2 - e_p.getRect().w / 2, rect.y + rect.h);
	e_p.setSize(rect.w / 8, rect.h / 3);
	e_p.setSpeed(speed*4);
}

Enermy::~Enermy()
{
}

void Enermy::e_move(SDL_Renderer* renderer)
{
	rect.y += speed;
	if (rect.y > SCREEN_HEIGHT) {
		rect.y = (rand() % SCREEN_WIDTH) / 5;
		rect.x = rand() % SCREEN_HEIGHT;
		body = TA::loadTexture(renderer, listEnermy[rand() % 9]);
	}
}

void Enermy::e_fire(SDL_Renderer* renderer, int x_border, int y_border)
{
	e_p.setRect(rect.x + rect.w / 2 - e_p.getRect().w / 2, e_p.getRect().y + speed*2);
	if (e_p.getRect().y > SCREEN_HEIGHT) {
		e_p.setRect(rect.x + rect.w / 2 - e_p.getRect().w / 2, rect.y + rect.h);
	}
	e_p.show(renderer);
}

void Enermy::initEnermy(SDL_Renderer* renderer)
{
	rect.x = rand() % SCREEN_WIDTH + 10;
	rect.y = (rand() % SCREEN_HEIGHT) / 5;
	body = TA::loadTexture(renderer, listEnermy[rand() % 9]);
	e_p.loadImg(renderer, "enerbul.png");
}

void Enermy::active(SDL_Renderer* renderer, int x, int y)
{
	show(renderer);
	e_move(renderer);
	e_fire(renderer, x, y);
}
