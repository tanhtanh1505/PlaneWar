#pragma once
#include"ta.h"
#include"Object.h"

using namespace TA;

class Bullet :public Object
{
private:
	int x_b;
	int y_b;
	bool isMove;
	int speed;
public:
	Bullet();
	~Bullet();

	void fire(const int& x_border, const int& y_border);

	void setMove(bool ok) {
		isMove = ok;
	}
	bool is_move() {
		return isMove;
	}
	void setSpeed(int s) {
		speed = s;
	}
	int getSpeed() {
		return speed;
	}
};

