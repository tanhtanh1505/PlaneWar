#include "Bullet.h"

Bullet::Bullet()
{
	x_b = 0;
	y_b = 0;
	isMove = false;
	speed = 2;
}

Bullet::~Bullet()
{
}

void Bullet::fire(const int& x_border, const int& y_border)
{
	rect.y-=speed;
	if (rect.x > x_border) {
		isMove = false;
	}
}
