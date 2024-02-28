#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "constants.hpp"

GameObject::GameObject(const char* texturesheet, float x, float y) 
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

//does nothing
GameObject::~GameObject() 
{
    SDL_DestroyTexture(objTexture);
}

void GameObject::Update() 
{
    srcRect.h = 50;
    srcRect.w = 50;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = (int)xpos;
    destRect.y = (int)ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void GameObject::Render() 
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    if (showHitboxes) 
    {
        SDL_RenderDrawRect(Game::renderer,&destRect);
    }    
}

void GameObject::increaseX(float x)
{
    if (xpos <= WINDOW_WIDTH) { //800 je sirina okna
        if (xpos + x > WINDOW_WIDTH - srcRect.w)
            xpos = WINDOW_WIDTH - srcRect.w; //150 je sirina teksture
        else if (xpos + x < 0)
            xpos = 0;
        else xpos += x;
    }
    /*
    float newX = xpos + x;
    //std::cout << "xpos: " << xpos<<"\n";
    if (newX >= 0 && newX <= WINDOW_WIDTH - srcRect.w) {
        xpos = newX;
    }*/
}

void GameObject::increaseY(float y) 
{
    if (ypos <= WINDOW_HEIGHT) {
        if (ypos + y > WINDOW_HEIGHT - srcRect.h)
            ypos = WINDOW_HEIGHT - srcRect.h;
        else if (ypos + y < 0)
            ypos = 0;
        else ypos += y;
    }
    /*
    float newY = ypos + y;
    //std::cout << "xpos: " << ypos << "\n";
    if (newY >= 0 && newY <= WINDOW_HEIGHT - srcRect.h) {
        ypos = newY;
    }*/
}