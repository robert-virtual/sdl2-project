#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "headers/Entity.h"

class RenderWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    RenderWindow(const char* title,int width,int height);
    void cleanUp();
    SDL_Texture* loadTexture(const char* filePath);
    void clear();
    void render(SDL_Texture *texture);
    void render(Entity& entity);
    void display();
};



 