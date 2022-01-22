#pragma once
#include"ta.h"
#include"Object.h"
#include"Bullet.h"
#include"Enermy.h"
#include"Boss.h"
#include"Explosion.h"

using namespace TA;

class Player : public Object
{
private:
	int x_p;
	int y_p;
	int speedBull;
	vector<Bullet*> p_bull_list;
	
public:
	
	Player(SDL_Renderer* renderer);
	~Player();
	
	void move_p(SDL_Renderer* renderer, SDL_Event event, Mix_Chunk* bulletSound, bool& unti, int& numunti);
	void move_pm(SDL_Renderer* renderer, SDL_Event event, Mix_Chunk* bulletSound, bool& unti, int& numunti);
	void move();
	void setBullList(vector<Bullet*> bull_list) {
		p_bull_list = bull_list;
	}
	void setSpeedBull(int const x)
	{
		speedBull = x;
	}
	int getSpeedBull() { return speedBull; };
	vector<Bullet*> getBullList() {
		return p_bull_list;
	}
	SDL_Rect p_rect();
	
};

