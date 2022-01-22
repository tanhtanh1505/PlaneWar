#pragma once
#include"ta.h"
#include"Object.h"

using namespace TA;

class Text: public Object
{
private:
	string str;
	SDL_Color text_color;
	SDL_Surface* textSurface;

public:
	enum TextColor {
		RED = 0,
		WHITE = 1,
		BLACK = 2,
	};
	Text();
	~Text();
	void initText(TTF_Font* &fontText);
	void setText(string t) {
		str = t;
	}
	void setColor(const int& type);
	void creatText(TTF_Font* font, SDL_Renderer* renderer);



};

