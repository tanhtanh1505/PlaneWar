#include "Boss.h"

Boss::Boss()
{
	speed_x = 3;
	speed_y = 2;
	is_move = true;
	heal = 20;
	rect.y = 0;

	bull.setRect(rect.x + rect.w /2 - bull.getRect().w/2, rect.y + rect.h);
	bull.setSize(rect.w / 2, rect.h / 2);
	bull.setSpeed(speed_x * 4);
}

Boss::~Boss()
{
}

void Boss::bossMove()
{
	rect.x += speed_x;
	if (rect.x > (SCREEN_WIDTH - rect.w) || rect.x <0) {
		speed_x = -speed_x;
	}
	rect.y += speed_y/2;
	if (rect.y > SCREEN_HEIGHT / 2 || rect.y < 0) {
		speed_y = -speed_y;
	}
}

void Boss::bossFire(SDL_Renderer* renderer, int x_border, int y_border)
{
	bull.setRect(rect.x + rect.w / 2 - bull.getRect().w / 2, bull.getRect().y + abs(speed_x) * 2);
	if (bull.getRect().y > SCREEN_HEIGHT) {
		bull.setRect(rect.x + rect.w / 2 - bull.getRect().w / 2, rect.y + rect.h);
	}
	bull.show(renderer);
}

void Boss::initBoss(SDL_Renderer* renderer)
{
	rect.x = rand()% (SCREEN_WIDTH/2) + SCREEN_WIDTH/4 ;
	int r = rand() % 2 + 1;
	if (r == 1) {
		loadImg(renderer, "boss1.png");
		bull.loadImg(renderer, "bossbul.png");
	}
	else {
		loadImg(renderer, "boss2.png");
		bull.loadImg(renderer, "bossbul1.png");
	}
	
}

void Boss::active(SDL_Renderer* renderer, int x, int y)
{
	if (heal > 0) {
		show(renderer);
		bossMove();
		bossFire(renderer, x, y);
	}
	
}
