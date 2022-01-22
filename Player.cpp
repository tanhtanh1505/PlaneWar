#include "Player.h"

using namespace TA;
Player::Player(SDL_Renderer* renderer)
{	
	x_p = 0;
	y_p = 0;
	rect.x = SCREEN_WIDTH / 2;
	rect.y = SCREEN_HEIGHT*3/4;
	rect.w = 90;
	rect.h = 90;
	body = loadTexture(renderer, "plane.png");
	speedBull = 5;
}

Player::~Player()
{
}

void Player::move_p(SDL_Renderer* renderer, SDL_Event event, Mix_Chunk* bulletSound, bool& unti, int& numunti)
{
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			y_p = -rect.h / 10;
			break;
		case SDLK_DOWN:
			y_p = rect.h / 10;
			break;
		case SDLK_RIGHT:
			x_p = rect.w / 10;
			break;
		case SDLK_LEFT:
			x_p = -rect.w / 10;
			break;
		case SDLK_SPACE:
		{
			Mix_PlayChannel(-1, bulletSound, 0);
			Bullet* p_b = new Bullet();
			p_b->loadImg(renderer, "bulletplane.png");
			p_b->setSize(rect.w / 10, rect.h / 3);
			p_b->setSpeed(speedBull);
			p_b->setMove(true);
			p_b->setRect(rect.x + rect.w / 2 - p_b->getRect().w / 2, rect.y - rect.h / 3);
			p_bull_list.push_back(p_b);
			break;
		}
		case SDLK_CAPSLOCK:
			if (numunti > 0) {
				unti = true;
				numunti--;
			}
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			y_p = 0;
			break;
		case SDLK_DOWN:
			y_p = 0;
			break;
		case SDLK_RIGHT:
			x_p = 0;
			break;
		case SDLK_LEFT:
			x_p = 0;
			break;
		default:
			break;
		}
	}


}
void Player::move_pm(SDL_Renderer* renderer, SDL_Event event, Mix_Chunk* bulletSound, bool& unti, int& numunti) {

	if (event.type == SDL_MOUSEMOTION) {
		rect.x = event.motion.x - rect.w / 2;
		rect.y = event.motion.y - rect.h / 2;
	}
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		Mix_PlayChannel(-1, bulletSound, 0);
		if (event.button.button == SDL_BUTTON_LEFT) {
			Bullet* p_b = new Bullet();
			p_b->loadImg(renderer, "bulletplane.png");
			p_b->setSize(rect.w / 10, rect.h / 3);
			p_b->setSpeed(speedBull);
			p_b->setMove(true);

			p_b->setRect(rect.x + rect.w / 2 - p_b->getRect().w / 2, rect.y - rect.h / 3);
			p_bull_list.push_back(p_b);

		}
	}
	else if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_SPACE && numunti > 0)
		{
			unti = true;
			numunti--;
		}
	}
}
void Player::move()
{
	rect.x += x_p;

	if (rect.x < 0 || rect.x + rect.w > SCREEN_WIDTH) {
		rect.x -= x_p;
	}

	rect.y += y_p;

	if (rect.y < 0 || rect.y + rect.h > SCREEN_HEIGHT) {
		rect.y -= y_p;
	}

}
SDL_Rect Player::p_rect() {
	SDL_Rect r;
	r.x = rect.x + rect.w / 6;
	r.y = rect.y + rect.h / 3;
	r.w = rect.w * 2 / 3;
	r.h = rect.h * 2 / 3;
	return r;
}

