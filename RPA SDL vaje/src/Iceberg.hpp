#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include <vector>
#include <time.h>

//int IcebergW = 50, IcebergH = 50

class Iceberg
{
private:
    int ID, oknoW = 800, oknoH = 600;
    float xpos=0, ypos=0;

    SDL_Texture* objTexture = TextureManager::LoadTexture("assets/iceberg.png");
    SDL_Rect srcRect, destRect;

    bool showHitboxes = true;
public:
    //random x,y
    Iceberg();
    //podan x,y
    Iceberg(float x, float y);
    //idk lol
    Iceberg(const char* texturesheet);
    ~Iceberg();    

    void izpis();
    void Render();
    void Update();
    //int ReturnID() { return ID; } // vrne ID
};

int rendom(int n,int x) {
    //srand(time(NULL));
    int a = (rand() % n + x);
    return a;
}

Iceberg::Iceberg()
{
    //srand(time(NULL));
    ID = rendom(900000, 100000);
    xpos = rendom(16, 0) * 50;
    ypos = rendom(12, 0) * 50;/*
    ID = rand() % 900000 + 100000;
    xpos = (float)(rand() % 16) * 50;
    ypos = (float)(rand() % 12) * 50;*/
}

//podan x in y
Iceberg::Iceberg(float x, float y)
{
    ID = rand() % 900000 + 100000;
    xpos = x;
    ypos = y;
}

//idk
Iceberg::Iceberg(const char* texturesheet)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    ID = rand() % 900000 + 100000;
    xpos = (float)(rand() % 16) * 50;
    ypos = (float)(rand() % 12) * 50;
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

//izpise cel vektor
/*
void VectorIzpis(std::vector<Iceberg>& v)
{
    for (int i = 0; i < v.size(); i++) {
        v[i].izpis();
    }
}*/

//VectorIzpis(v);