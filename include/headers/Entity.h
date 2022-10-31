#pragma once
#include <SDL2/SDL.h>

class Entity
{
private:
    float x,y;
    int w,h;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
public:
    Entity(float _x,float _y,SDL_Texture* _texture,int _w,int _h);
    float getX();
    float getY();
    SDL_Texture* getTexture();
    SDL_Rect* getCurrentFrame();
    void moveX(float _x);
    void moveY(float _y);
};


            