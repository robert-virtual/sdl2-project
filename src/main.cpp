#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Hola mundo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1080,720,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);
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
           
           case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            
            break;
           } 
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}

