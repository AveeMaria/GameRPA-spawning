#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include <vector>
#include <time.h>

//int IcebergW = 50, IcebergH = 50, 

class Iceberg
{
private:
    int ID, oknoW = 800, oknoH = 600;
    float xpos, ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;

    bool showHitboxes = false;
public:
    //random x,y
    Iceberg(const char* texturesheet, float x, float y);
    ~Iceberg();
    //podan x,y
    Iceberg() {}
    void izpis();
    void Render();
    void Update();
};

Iceberg::Iceberg(const char* texturesheet, float x, float y)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    ID = rand() % 900000 + 100000;
    xpos = x;
    ypos = y;
    //xpos = rand() % oknoW;
    //ypos = rand() % oknoH;
}

Iceberg::~Iceberg()
{
    SDL_DestroyTexture(objTexture);
}

void Iceberg::Update()
{
    srcRect.h = 50;
    srcRect.w = 50;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.y = 0;

    destRect.x = (int)xpos;
    destRect.y = (int)ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void Iceberg::izpis()
{
    std::cout << "ID: " << ID << " x: " << xpos << " y: " << ypos << "\n";
}

void Iceberg::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    if (showHitboxes)
    {
        SDL_RenderDrawRect(Game::renderer, &destRect);
    }
}

//podamo x in y
/*
Iceberg::Iceberg(float x, float y)
{
    ID = rand() % 900000 + 100000;
    xpos = x;
    ypos = y;
}*/

//izpise cel vektor
/*
void VectorIzpis(std::vector<Iceberg>& v)
{
    for (int i = 0; i < v.size(); i++) {
        v[i].izpis();
    }
}*/

//std::vector<Iceberg> v(5);

//VectorIzpis(v);