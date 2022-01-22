#ifndef GAME_H_
#define GAME_H_

#include "ta.h"
#include"Object.h"
#include"Player.h"
#include"Bullet.h"
#include"Enermy.h"
#include"Boss.h"
#include"Explosion.h"
#include"Text.h"

static Object setup[2];

static Text menu1;
static Text mark;
static int mk = 0;
static SDL_Texture* menu = NULL;
static Explosion explosion;
static SDL_Texture* endGame;
static Object gift;
static SDL_Texture* tx1;
static SDL_Texture* tx2;

static int n = 0;
static int si = 0;
static int playbymouse = 0;
static bool selected = false;
static bool sl = false;
static bool setu = false;
static int numunti = 0;
static bool pickgift = true;
static int ut = 0;

static int mapEnermy = 0;
static bool ok = true;
static int nHb = 0;
static bool movebymouse = true;
static bool unti = false;

static string untimate[3] = {"untibul0.png", "untibul1.png", "untibul2.png"};
static Bullet untis[3];
using namespace TA;

namespace GAME 
{
	void initMenu(SDL_Renderer* renderer, TTF_Font* fontText, Text &menu1, SDL_Texture*& menu, Object setup[2]);
	
	void showMark(SDL_Renderer* renderer, TTF_Font* fontText, Text& mark, int mks);
	
	void initGame(SDL_Renderer* renderer, SDL_Rect& bg, SDL_Rect& bgz, Mix_Chunk*& bum, Mix_Chunk*& gunSound, 
		Mix_Music*& brokenPlane, SDL_Texture*& tx1, SDL_Texture*& tx2, Explosion& explosion, Object & gift, Bullet untis[3]);
	
	void ResetGame(int& n, int& si, int& playbymouse, bool& selected, bool& sl, bool& setu, int& numunti, int& ut,
		int& mapEnermy, bool& ok, int& nHb, bool& movebymouse, bool& unti, bool& quit, int& mk);

	void selectMode(SDL_Event event, int& mo, bool& selected, bool& sl, int& si, bool& setu, bool& quit, Text& menu1, Object setup[2]);

	void instruction(SDL_Renderer* renderer, int x);

	void loadMap(SDL_Renderer* renderer, int& mapEnermy, int& nHb, SDL_Rect& bg, SDL_Rect& bgz, bool& ok, SDL_Texture* tx1, SDL_Texture* tx2, bool& pickgift);
	
	void RunPEB(SDL_Renderer* renderer, Player& player, vector<Enermy>& enermy, vector<Boss>& boss,
		Explosion& explosion, Mix_Chunk*& bum, Mix_Music*& brokenPlane, bool& ok, bool& quit, int& nHb, int& mk, int& mapEnermy);

	void RunGift(SDL_Renderer* renderer, bool& unti, int& ut, Player& player, vector<Enermy>& enermy,
		Mix_Chunk*& bum, int& mk, int& numunti, bool& pickgift, int& mapEnermy, Bullet untis[3], Explosion& explosion, Object& gift);

	void showLastScore(SDL_Renderer* renderer, SDL_Texture*& endGame, TTF_Font* fontText, int mks);

	void quitGame(bool &quit);
}
#endif 
