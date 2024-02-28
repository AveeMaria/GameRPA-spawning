#pragma once

#include "Game.hpp"

class GameObject 
{
private:
	float xpos;
	float ypos;

	int step = 50;
	int SCREENWIDTH = 800;
	int SCREENHEIGHT = 600;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	bool showHitboxes = false;
public:
	GameObject(const char* texturesheet,float x,float y);
	~GameObject();

	void increaseX(float);
	void increaseY(float);

	void Update();
	void Render();
};

