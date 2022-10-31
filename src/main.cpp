#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "headers/Utils.h"
#include "headers/RenderWindow.h"
#include "headers/Entity.h"

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return sdlErr("SDL init");
    if (!IMG_Init(IMG_INIT_PNG))
        return sdlErr("IMG init");
    RenderWindow window("Game v1.0.0", 1080, 720);
    bool isRunning = true;
    SDL_Event event;
    SDL_Texture *texture = window.loadTexture("res/gfx/ground_grass_1.png");
    std::vector<Entity> ground = {
        Entity(0, 30, texture, 32, 32),
        Entity(30, 30, texture, 32, 32),
        Entity(60, 30, texture, 32, 32)};

    SDL_Texture *ghostTex = window.loadTexture("res/gfx/ghost.png");
    Entity ghost(100, 100, ghostTex, 32, 32);
    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {

            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    ghost.moveY(-15);
                    break;
                case SDLK_DOWN:
                    ghost.moveY(15);
                    break;
                case SDLK_LEFT:
                    ghost.moveX(-15);
                    break;
                case SDLK_RIGHT:
                    ghost.moveX(15);
                    break;
                }
                break;
            }
        }
        window.clear();
        // window.render(grass.getTexture());
        for (Entity &e : ground)
        {
            window.render(e);
        }
        window.render(ghost);
        window.display();
    }
    window.cleanUp();
    SDL_Quit();

    return 0;
}
