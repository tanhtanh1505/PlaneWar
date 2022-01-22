#include"Game.h"

using namespace GAME;

int main(int argc, char* argv[]) {
	
LOOP:
	srand(time(0));
	//Init SDL- LoadObject- Menu
	initSDL(window, renderer);
	initGame(renderer, bg, bgz, bum, gunSound, brokenPlane, tx1, tx2, explosion, gift, untis);
	initMenu(renderer, fontText, menu1, menu, setup);
	mark.initText(fontText);

	//Creat Player
	Player player(renderer);
	/*player.loadImg(renderer, "plane.png");
	player.setSize(90, 90);*/
	
	//Creat Enermy
	vector<Enermy> enermy(10);
	for (int i = 0; i < enermy.size(); i++) {
		enermy.at(i).initEnermy(renderer);
	}

	//Creat Boss
	vector<Boss> boss(5);
	for (int i = 0; i < boss.size(); i++) {
		boss.at(i).initBoss(renderer);
	}

	ResetGame(n, si, playbymouse, selected, sl, setu, numunti, ut, mapEnermy, ok, nHb, movebymouse, unti, quit, mk);

	//SelectMode
	while (!selected) {
		SDL_RenderCopy(renderer, menu, NULL, NULL);
		menu1.creatText(fontText, renderer);
		setup[si].show(renderer);

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event) != 0)
		{
			selectMode(event, playbymouse, selected, sl, si, setu, quit, menu1, setup);
		}
		
	}

	if (playbymouse)
		instruction(renderer, 2);
	else
		instruction(renderer, 1);

	//RunGame
	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (playbymouse)
				player.move_pm(renderer, event, gunSound, unti, numunti);
			else 
				player.move_p(renderer, event, gunSound, unti, numunti);
		}

		SDL_RenderClear(renderer);

		loadMap(renderer, mapEnermy, nHb, bg, bgz, ok, tx1, tx2, pickgift);

		RunPEB(renderer, player, enermy, boss, explosion, bum, brokenPlane, ok, quit, nHb, mk, mapEnermy);
		
		RunGift(renderer, unti, ut, player, enermy, bum, mk, numunti, pickgift, mapEnermy, untis, explosion, gift);

		showMark(renderer, fontText, mark, mk);

		SDL_RenderPresent(renderer);
	}

	showLastScore(renderer, endGame, fontText, mk);

	//Play Again or exit
	while (true) 
	{
		if (SDL_WaitEvent(&event) && event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_BACKSPACE)
				break;
			else goto LOOP;
		}
	}

	
	return 0;
}