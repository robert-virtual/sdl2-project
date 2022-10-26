#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "headers/Utils.h"
#include "headers/RenderWindow.h"

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return sdlErr("SDL init");
    if (!IMG_Init(IMG_INIT_PNG))
        return sdlErr("IMG init");
    RenderWindow window("Game v1.0.0", 1080, 720);
    bool isRunning = true;
    SDL_Event event;
    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;
            }
        }
    }
    window.cleanUp();
    SDL_Quit();

    return 0;
}
