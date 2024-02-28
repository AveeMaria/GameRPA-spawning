#include "Map.hpp"
#include "TextureManager.hpp"

//12x16 tileov po 50x50 pixlov
int lvl1[12][16] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,2,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,2,2,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int MaxIcebergs(int lvl[12][16], float IcebergPercentage) {
	int water = 0;
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 16; ++j) {
			if (lvl[i][j] == 0) {
				water++;
			}
		}
	}
	//std::cout<<"water: "<<water<<"\n";
	return (int)(water * IcebergPercentage);
}

Map::Map() 
{
	sand = TextureManager::LoadTexture("assets/sand.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/water.png");
	corrupted = TextureManager::LoadTexture("assets/corrupted.png");
	LoadMap(lvl1);

	src.x = src.y = 0;
	dest.x = dest.y = 0;

	src.w = dest.w = 50;
	src.h = dest.h = 50;
}

Map::~Map() 
{
}

void Map::LoadMap(int arr[12][16]) 
{
	for (int row = 0; row < 12; ++row) {
		for (int column = 0; column < 16; ++column) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap() 
{
	int type = 0;
	for (int row = 0; row < 12; ++row) {
		for (int column = 0; column < 16; ++column) {
			type = map[row][column];
			dest.x = column * 50;
			dest.y = row * 50;
			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(sand, src, dest);
				break;
			case 2:
				TextureManager::Draw(grass, src, dest);
				break;
			default:
				TextureManager::Draw(corrupted, src, dest);
				break;
			}
			//map[row][column] = arr[row][column];
		}
	}
}