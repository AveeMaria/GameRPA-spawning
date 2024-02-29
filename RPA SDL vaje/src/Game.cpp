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
	enemy = new GameObject("assets/enemy.png", 300, 300);
	map = new Map();
	
	{
		Iceberg* ledenagora;
		
		for (int i = 0; i < 5; ++i) {
			ledenagora = new Iceberg;
			ledenagora->izpis();
			//idk neki da se nebi podvojila
			/*
			for (auto e : LedeneGore) {
				if (e->ReturnID() == ledenagora->ReturnID()) {
					ledenagora = new Iceberg;
				}
			}*/
			LedeneGore.push_back(ledenagora);
		}
	}
}

void Game::handleEvents() {
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
	if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}
}

void Game::update() {
	player->Update();
	enemy->Update();
	
	for (Iceberg*& e : LedeneGore) {
		e->Update();
	}
}

void Game::render() {
	SDL_RenderClear(renderer);

	map->DrawMap();
	player->Render();
	enemy->Render();
	
	for (auto e : LedeneGore) {
		e->Render();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned";
}