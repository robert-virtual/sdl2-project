#include "headers/Utils.h"


int sdlErr(const char* msg){
    std::cout << msg << " " << SDL_GetError() << std::endl;
    return -1;
}