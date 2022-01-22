#pragma once

#include"ta.h"
#include"Object.h"
#include"Bullet.h"

using namespace TA;
class Enermy :public Object
{
private:
	int speed;
	
	string listEnermy[9] = {
		"enermy0.png","enermy1.png","enermy2.png","enermy3.png","enermy4.png",
		"enermy5.png","enermy6.png","enermy7.png","enermy8.png"
	};
public:
	
	Enermy();
	~Enermy();
	Bullet e_p;
	void e_move(SDL_Renderer* renderer);
	void set_speed(int sp) {
		speed = sp;
	}
	int get_speed() {
		return speed;
	}
	Bullet getBull() {
		return e_p;
	}
	void e_fire(SDL_Renderer* renderer, int x_border, int y_border);
	void initEnermy(SDL_Renderer* renderer);
	void active(SDL_Renderer* renderer, int x, int y);

};

