#include "headers/RenderWindow.h"
#include "headers/Utils.h"

RenderWindow::RenderWindow(const char *title, int width, int height) : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
       sdlErr("Create window");
       return;
    }
    renderer = SDL_CreateRenderer(
        window, 
        -1, 
        SDL_RENDERER_ACCELERATED
    );
    if (renderer == NULL)
    {
       sdlErr("Create renderer");
       return;
    }
    
}


SDL_Texture* RenderWindow::loadTexture(const char* filePath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer,filePath);
    if (texture == NULL){
        sdlErr("Load texture ");
        return NULL;
    }
    
    return texture;
}


void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}










