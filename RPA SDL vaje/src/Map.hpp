#pragma once

#include "Game.hpp"

class Map {
private:
	SDL_Rect src, dest;

	SDL_Texture* water;
	SDL_Texture* sand;
	SDL_Texture* grass;
	SDL_Texture* corrupted;

public:
	Map();
	~Map();

	void LoadMap(int [12][16]);
	void DrawMap();
	int MaxIcebergs(float);
	//vector superiority???
	int map[12][16];
};