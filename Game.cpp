#include"Game.h"

void GAME::initMenu(SDL_Renderer* renderer, TTF_Font* fontText, Text& menu1, SDL_Texture*& menu, Object setup[2])
{
	menu1.initText(fontText);
	menu1.setText("Start");
	menu1.setRect(SCREEN_WIDTH * 3 / 4, SCREEN_HEIGHT * 3 / 4);
	menu1.setSize(200, 100);

	setup[0].loadImg(renderer, "keyboard.png");
	setup[0].setSize(50, 50);
	setup[0].setRect(SCREEN_WIDTH - setup[0].getRect().w * 5 / 4, setup[0].getRect().h / 4);

	setup[1].loadImg(renderer, "mouse.png");
	setup[1].setSize(50, 50);
	setup[1].setRect(SCREEN_WIDTH - setup[1].getRect().w * 5 / 4, setup[1].getRect().h / 4);

	menu = loadTexture(renderer, "menu.jpg");
}

void GAME::showMark(SDL_Renderer* renderer, TTF_Font* fontText, Text& mark, int mks)
{
	string s = "Score: ";
	s = s + to_string(mks);
	mark.setText(s);
	mark.creatText(fontText, renderer);
}

void GAME::initGame(SDL_Renderer* renderer, SDL_Rect& bg, SDL_Rect& bgz, Mix_Chunk*& bum, Mix_Chunk*& gunSound, 
	Mix_Music*& brokenPlane, SDL_Texture*& tx1, SDL_Texture*& tx2, Explosion& explosion, Object & gift, Bullet untis[3]/*, Text& mark*/)
{
	bg.x = 0;
	bg.y = -SCREEN_HEIGHT;
	bg.w = SCREEN_WIDTH;
	bg.h = SCREEN_HEIGHT;

	bgz.x = 0;
	bgz.y = 0;
	bgz.w = SCREEN_WIDTH;
	bgz.h = SCREEN_HEIGHT;

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
		cout << "-1";
	}
	music = Mix_LoadMUS("mbg.mp3");
	;	if (music == NULL)
	{
		cout << Mix_GetError();
	}
	brokenPlane = Mix_LoadMUS("broken.mp3");
	bum = Mix_LoadWAV("bum.wav");
	gunSound = Mix_LoadWAV("Gunsound2.wav");

	Mix_PlayMusic(music, 10);

	tx1 = loadTexture(renderer, "bg1.jpg");
	tx2 = loadTexture(renderer, "bg1.jpg");

	explosion.exp_.loadImg(renderer, "bum.png");
	explosion.brokenPl = TA::loadTexture(renderer, "brokenP.png");

	gift.loadImg(renderer, "gift.png");
	gift.setSize(35, 40);
	gift.setRect(rand() % (SCREEN_WIDTH / 2) + SCREEN_WIDTH / 4, rand() % (SCREEN_HEIGHT / 4));

	for (int ui = 0; ui < 3; ui++) {
		untis[ui].loadImg(renderer, untimate[ui]);
		untis[ui].setSize(100, 100);
		untis[ui].setRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		untis[ui].setSpeed(4);
		untis[ui].setMove(false);
	}
	/*mark.initText(fontText);*/
}

void GAME::ResetGame(int& n, int& si, int& playbymouse, bool& selected, bool& sl, bool& setu, int& numunti, int& ut,
	int& mapEnermy, bool& ok, int& nHb, bool& movebymouse, bool& unti, bool& quit, int &mk)
{
	n = 0;
	si = 0;
	playbymouse = 0;
	selected = false;
	sl = false;
	setu = 0;
	numunti = 0;
	mapEnermy = 0;
	ok = true;
	nHb = 0;
	movebymouse = true;
	unti = false;
	quit = false;
	mk = 0;
}
void GAME::selectMode(SDL_Event event, int& mo, bool& selected, bool& sl, int& si, bool& setu, bool& quit, Text& menu1, Object setup[2])
{
	if (event.type == SDL_QUIT)
	{
		quit = true;
	}
	if (event.type == SDL_MOUSEMOTION) {
		int x_m = event.motion.x;
		int y_m = event.motion.y;
		if (x_m > menu1.getRect().x && x_m < menu1.getRect().x + menu1.getRect().w
			&& y_m > menu1.getRect().y && y_m < menu1.getRect().y + menu1.getRect().h)
		{
			menu1.setColor(Text::RED);
			sl = true;
		}
		else
		{
			menu1.setColor(Text::WHITE);
			sl = false;
		}
	}
	if (event.type == SDL_MOUSEBUTTONDOWN && sl) {
		selected = true;
	}
	//----------------
	if (event.type == SDL_MOUSEMOTION) {
		int x_m = event.motion.x;
		int y_m = event.motion.y;
		if (x_m > setup[si].getRect().x && x_m < setup[si].getRect().x + setup[si].getRect().w
			&& y_m > setup[si].getRect().y && y_m < setup[si].getRect().y + setup[si].getRect().h)
		{
			si = 1 - mo;
			setu = true;
		}
		else
		{
			si = mo;
			setu = false;
		}
	}
	if (event.type == SDL_MOUSEBUTTONDOWN && setu) {
		mo = 1 - mo;
	}
}

void GAME::instruction(SDL_Renderer* renderer, int x)
{
	SDL_Texture* bgr = loadTexture(renderer, "bg1.jpg");
	SDL_RenderCopy(renderer, bgr, NULL, NULL);
	Text ins1, ins2, ins3;
	if (x == 1) {
		ins1.initText(fontText);
		ins1.setText("Instruction: ");
		ins1.setSize(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 7);
		ins1.setRect(SCREEN_WIDTH / 2 - ins1.getRect().w / 2, SCREEN_HEIGHT / 6);

		ins2.initText(fontText);
		ins2.setText("Press SPACE to shoot");
		ins2.setSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10);
		ins2.setRect(SCREEN_WIDTH / 2 - ins2.getRect().w / 2, SCREEN_HEIGHT * 2 / 6);

		ins3.initText(fontText);
		ins3.setText("Press CAPLOCKS to use untimate");
		ins3.setSize(SCREEN_WIDTH / 10 * 7, SCREEN_HEIGHT / 10);
		ins3.setRect(SCREEN_WIDTH / 2 - ins3.getRect().w / 2, SCREEN_HEIGHT * 3 / 6);

		ins1.creatText(fontText, renderer);
		ins2.creatText(fontText, renderer);
		ins3.creatText(fontText, renderer);
	}
	else
	{
		ins1.initText(fontText);
		ins1.setText("Instruction: ");
		ins1.setSize(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 7);
		ins1.setRect(SCREEN_WIDTH / 2 - ins1.getRect().w / 2, SCREEN_HEIGHT / 6);

		ins2.initText(fontText);
		ins2.setText("Click left mouse to shoot");
		ins2.setSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10);
		ins2.setRect(SCREEN_WIDTH / 2 - ins2.getRect().w / 2, SCREEN_HEIGHT * 2 / 6);

		ins3.initText(fontText);
		ins3.setText("Press SPACE to use untimate");
		ins3.setSize(SCREEN_WIDTH / 10 * 7, SCREEN_HEIGHT / 10);
		ins3.setRect(SCREEN_WIDTH / 2 - ins3.getRect().w / 2, SCREEN_HEIGHT * 3 / 6);

		ins1.creatText(fontText, renderer);
		ins2.creatText(fontText, renderer);
		ins3.creatText(fontText, renderer);
	}
	SDL_RenderPresent(renderer);
	SDL_Event e;
	while (true) {
		if (SDL_WaitEvent(&e) != 0 &&
			(e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
			return;
		SDL_Delay(100);
	}
}

void GAME::loadMap(SDL_Renderer* renderer, int& mapEnermy, int& nHb, SDL_Rect& bg, 
	SDL_Rect& bgz, bool& ok, SDL_Texture* tx1, SDL_Texture* tx2, bool &pickgift)
{
	if (mapEnermy < 3) {
		ok = true;
		nHb = 0;
		if (mapEnermy % 2 == 1) {
			pickgift = true;
		}
		bg.y += 1;
		bgz.y += 1;
		SDL_RenderCopy(renderer, tx1, NULL, &bg);
		SDL_RenderCopy(renderer, tx2, NULL, &bgz);
		if (bg.y > 0) {
			bg.y = -SCREEN_HEIGHT;
			mapEnermy++;
		}
		if (bgz.y > SCREEN_HEIGHT) {
			bgz.y = 0;
		}
	}
	else
	{
		ok = false;
		SDL_RenderCopy(renderer, tx1, NULL, NULL);
	}
}
void GAME::RunPEB(SDL_Renderer* renderer, Player& player, vector<Enermy>& enermy, vector<Boss>& boss, Explosion& explosion,
	Mix_Chunk*& bum, Mix_Music*& brokenPlane, bool& ok, bool& quit, int& nHb, int& mk, int& mapEnermy)
{
	//Solve bullet to Enermy & Boss------------------------------------------------------------------------
	for (int ip = 0; ip < player.getBullList().size(); ip++) {
		vector<Bullet*> bullet_list = player.getBullList();
		if (bullet_list.at(ip) != NULL) {
			if (bullet_list.at(ip)->is_move()) {
				bullet_list.at(ip)->show(renderer);
				bullet_list.at(ip)->fire(SCREEN_WIDTH, SCREEN_HEIGHT);
				if (ok) {
					//If fire with Enermy
					for (int jp = 0; jp < enermy.size(); jp++) {
						if (checkCollision(enermy.at(jp).getRect(), bullet_list.at(ip)->getRect())) {
							bullet_list.at(ip)->setMove(false);
							explosion.showEx(renderer, enermy.at(jp).getRect().x - enermy.at(jp).getRect().w / 2, enermy.at(jp).getRect().y - enermy.at(jp).getRect().h / 2);
							Mix_PlayChannel(-1, bum, 0);
							enermy.at(jp).setRect(rand() % SCREEN_HEIGHT, (rand() % SCREEN_WIDTH) / 4);
							mk++;
						}
					}
				}
				else {
					//Fire with Boss
					for (int jb = 0; jb < boss.size(); jb++) {
						if (checkCollision(boss.at(jb).getRect(), bullet_list.at(ip)->getRect()) && boss.at(jb).getHeal() > 0) {
							bullet_list.at(ip)->setMove(false);
							boss.at(jb).decHeal();
							explosion.showEx(renderer, player.getBullList().at(ip)->getRect().x - player.getBullList().at(ip)->getRect().w / 2, player.getBullList().at(ip)->getRect().y - player.getBullList().at(ip)->getRect().h);
							Mix_PlayChannel(-1, bum, 0);
							nHb++;
							mk++;
						}
					}
					//Boss Heal
					if (nHb == boss.at(0).getNumberHeal() * 2) {
						mapEnermy = 0;
						for (int jbb = 0; jbb < boss.size(); jbb++) {
							boss.at(jbb).recoverHeal();
						}
						for (int ein = 0; ein < 5; ein++) {
							enermy.push_back(enermy.at(0));
						}
						for (int ein = 0; ein < enermy.size(); ein++) {
							//enermy.at(ein).set_speed(enermy.at(ein).get_speed()+1);
							enermy.at(ein).setRect(rand() % SCREEN_WIDTH, 0);
						}
						player.setSpeedBull(player.getSpeedBull() + 3);
					}
				}
			}
		}
		else {
			//Clear Bullet
			if (bullet_list.at(ip) != NULL && !bullet_list.at(ip)->is_move()) {
				bullet_list.erase(bullet_list.begin() + ip);
				player.setBullList(bullet_list);

				delete bullet_list.at(ip);
				bullet_list.at(ip) = NULL;
			}
		}
	}


	//Solve Enermy & Boss------------------------------------------------------------
	if (ok) {
		//Enermy
		for (int ie = 0; ie < enermy.size(); ie++) {
			enermy.at(ie).active(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
			if (checkCollision(enermy.at(ie).e_p.getRect(), player.p_rect())) {
				Mix_PlayMusic(brokenPlane, 0);
				explosion.broken_plane(renderer, player.getRect().x, player.getRect().y);
				quitGame(quit);
			}
		}
	}
	else {
		//Boss
		for (int ib = 0; ib < boss.size(); ib++) {
			boss.at(ib).active(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
			if (checkCollision(boss.at(ib).bull.getRect(), player.p_rect()) && boss.at(ib).getHeal() > 0) {
				Mix_PlayMusic(brokenPlane, 0);
				explosion.broken_plane(renderer, player.getRect().x, player.getRect().y);
				quitGame(quit);
			}
		}
	}

	//Render Player
	player.show(renderer);
	player.move();
}

void GAME::RunGift(SDL_Renderer* renderer, bool& unti, int& ut, Player& player, vector<Enermy>& enermy,
	Mix_Chunk*& bum, int& mk, int& numunti, bool& pickgift, int& mapEnermy, Bullet untis[3], Explosion& explosion, Object& gift)
{

	if (unti) {
		for (int ux = 0; ux < 3; ux++) {
			untis[ux].setRect(player.getRect().x, player.getRect().y - untis[ux].getRect().h);
			untis[ux].setMove(true);
		}
		unti = false;
	}
	if (untis[ut].is_move()) {
		untis[ut].show(renderer);
		for (int enm = 0; enm < enermy.size(); enm++) {
			if (checkCollision(untis[ut].getRect(), enermy.at(enm).getRect())) {
				explosion.showEx(renderer, enermy.at(enm).getRect().x - enermy.at(enm).getRect().w / 2, enermy.at(enm).getRect().y - enermy.at(enm).getRect().h / 2);
				Mix_PlayChannel(-1, bum, 0);
				enermy.at(enm).setRect(rand() % SCREEN_HEIGHT, (rand() % SCREEN_WIDTH) / 4);
				mk++;
			}
		}
		//untis[ut].setSpeed(6);
		untis[ut].fire(SCREEN_WIDTH, SCREEN_HEIGHT);
		ut++;
		if (ut == 3) ut = 0;
	}

	if (mapEnermy % 2 == 0 && pickgift) {
		gift.show(renderer);
		if (checkCollision(player.getRect(), gift.getRect()))
		{
			numunti++;
			pickgift = false;
		}

	}

}

void GAME::showLastScore(SDL_Renderer* renderer, SDL_Texture*& endGame, TTF_Font* fontText, int mks)
{
	Text score, playAgain;
	endGame = TA::loadTexture(renderer, "sc.jpg");
	score.initText(fontText);
	score.setText("Your Score: " + to_string(mks));
	score.setColor(Text::BLACK);
	score.setSize(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 70 * 8);
	score.setRect(SCREEN_WIDTH / 2 - score.getRect().w / 2, SCREEN_HEIGHT / 3);
	playAgain.initText(fontText);
	playAgain.setText("Press BACKSPACE to exit or any key to play again !");
	playAgain.setSize(SCREEN_WIDTH * 9 / 10 , SCREEN_HEIGHT / 10);
	playAgain.setRect(SCREEN_WIDTH / 2 - playAgain.getRect().w / 2, SCREEN_HEIGHT / 2);

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, endGame, NULL, NULL);
	score.creatText(fontText, renderer);
	playAgain.creatText(fontText, renderer);
	SDL_RenderPresent(renderer);
	//SDL_Delay(5000);
}

void GAME::quitGame(bool& quit)
{
	SDL_Delay(2000);
	if (MessageBox(NULL, L"Game Over!", L"Oh! Noo . . .", MB_OK)) {
		quit = true;
	}
}
