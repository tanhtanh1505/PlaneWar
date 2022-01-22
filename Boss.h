#pragma once
#include"ta.h"
#include"Object.h"
#include"Bullet.h"

class Boss:public Object
{
private:
	int speed_x;
	int speed_y;
	bool is_move;
	int heal;
public:
	Bullet bull;
	Boss();
	~Boss();
	void bossMove();
	void bossFire(SDL_Renderer* renderer, int x_border, int y_border);
	void initBoss(SDL_Renderer* renderer);
	void active(SDL_Renderer* renderer, int x, int y);
	void recoverHeal() {
		heal = 20;
	}
	void decHeal() {
		heal--;
	}
	int getNumberHeal() {
		return 20;
	}
	int getHeal() {
		return heal;
	}
};

