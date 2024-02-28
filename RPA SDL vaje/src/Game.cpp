#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "Iceberg.hpp"

GameObject* player;
GameObject* enemy;
Map* map;
Iceberg* ledenagora;

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
	ledenagora = new Iceberg("assets/iceberg.png",50,100);
}

void Game::handleEvents() {
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
	}
	//SDL_GetMouseState(&mx, &my);
}

void Game::update() {
	player->Update();
	enemy->Update();
	ledenagora->Update();
}

void Game::render() {
	SDL_RenderClear(renderer);

	map->DrawMap();
	player->Render();
	enemy->Render();
	ledenagora->Render();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned";
}