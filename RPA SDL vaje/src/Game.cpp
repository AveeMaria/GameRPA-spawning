#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "Iceberg.hpp"

GameObject* player;
GameObject* enemy;
Map* map;
std::vector<Iceberg*> LedeneGore;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	player = new GameObject("assets/player.png", 0, 0);
	enemy = new GameObject("assets/enemy.png", 200, 200);
	map = new Map();
	
	{
		Iceberg* ledenagora;
		
		for (int i = 0; i < 5; ++i) {
			ledenagora = new Iceberg;
			ledenagora->izpis();
			LedeneGore.push_back(ledenagora);
		}
	}
	
}

void Game::handleEvents() {/*
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				isRunning = false;
				break;
			case SDLK_w:
				player->increaseY(-50);
				std::cout << "W\n";
				break;
			case SDLK_s:
				player->increaseY(50);
				std::cout << "S\n";
				break;
			case SDLK_a:
				player->increaseX(-50);
				std::cout << "A\n";
				break;
			case SDLK_d:
				player->increaseX(50);
				std::cout << "D\n";
				break;
			}

		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			//mousedown = false;
			break;
		}
	}*/
	
	//SDL_GetMouseState(&mx, &my);
	
	/*
	//klemen
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_W] && !keystate[SDL_SCANCODE_S]) {
		std::cout << "W\n";
		player->increaseY(-5);
	}
	else if (!keystate[SDL_SCANCODE_W] && keystate[SDL_SCANCODE_S]) {
		std::cout << "S\n";
		player->increaseY(5);
	}
	if (keystate[SDL_SCANCODE_A] && !keystate[SDL_SCANCODE_D]) {
		std::cout << "A\n";
		player->increaseX(-5);
	}
	else if (!keystate[SDL_SCANCODE_A] && keystate[SDL_SCANCODE_D]) {
		std::cout << "D\n";
		player->increaseX(5);
	}*/

	
	//martin
	SDL_PumpEvents();
	
	if (currentKeyStates[SDL_SCANCODE_W]) {
		std::cout << "W\n";
		player->increaseY(-2.5);
	}
	if (currentKeyStates[SDL_SCANCODE_S]) {
		std::cout << "S\n";
		player->increaseY(2.5);
	}
	if (currentKeyStates[SDL_SCANCODE_A]) {
		std::cout << "A\n";
		player->increaseX(-2.5);
	}
	if (currentKeyStates[SDL_SCANCODE_D]) {
		std::cout << "D\n";
		player->increaseX(2.5);
	}
}

void Game::update() {
	player->Update();
	enemy->Update();

	
	for (Iceberg*& e : LedeneGore) {
		e->Update();
	}
	/*
	for(int i = 0; i > 5; ++i) {
		IceBergs[i]->Update();
	}*/
}

void Game::render() {
	SDL_RenderClear(renderer);

	map->DrawMap();
	player->Render();
	enemy->Render();

	
	for (auto e : LedeneGore) {
		e->Render();
	}
	/*
	for (int i = 0; i > 5; ++i) {
		IceBergs[i]->Render();
	}*/

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned";
}