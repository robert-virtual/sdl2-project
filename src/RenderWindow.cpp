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
       SDL_WINDOW_RESIZABLE 
    );
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

void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity){

    SDL_RenderCopy(renderer,entity.getTexture(),NULL,entity.getCurrentFrame());
}
void RenderWindow::render(SDL_Texture* texture){

    SDL_Rect src;
    src.h = 32; 
    src.w = 32; 
    src.x = 0;
    src.y = 0;
    SDL_Rect dst;
    dst.h = 32*2; 
    dst.w = 32*2; 
    dst.x = 400;
    dst.y = 200;
    SDL_RenderCopy(renderer,texture,&src,&dst);
}
void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int RenderWindow::height(){
     SDL_GetWindowSize(window,&w,&h);
     return h;
}
int RenderWindow::width(){
     SDL_GetWindowSize(window,&w,&h);
     return w;
}









