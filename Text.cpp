#include "Text.h"

Text::Text()
{
	setSize(70, 30);
	setColor(WHITE);
}

Text::~Text()
{
}

void Text::initText(TTF_Font*& fontText)
{
	if (TTF_Init() == -10) {
		cout << 1;
	}
	fontText = TTF_OpenFont("font.ttf", 20);
	if (fontText == NULL) {
		cout << 1;
	}
}

void Text::setColor(const int& type)
{
	if (type == RED) {
		SDL_Color color = { 255, 0, 0 };
		text_color = color;
	}
	else if (type == WHITE) {
		SDL_Color color = { 255,255,255 };
		text_color = color;
	}
	else {
		SDL_Color color = { 0,0,0 };
		text_color = color;
	}
}

void Text::creatText(TTF_Font* font, SDL_Renderer* renderer)
{
	textSurface = TTF_RenderText_Solid(font, str.c_str(), text_color);
	body = SDL_CreateTextureFromSurface(renderer, textSurface);
	show(renderer);
}
