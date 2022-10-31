#include "headers/Entity.h"

Entity::Entity(float _x,float _y,SDL_Texture* _texture,int _w,int _h){
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    texture = _texture;
    currentFrame.x = x;
    currentFrame.y = y;
    currentFrame.w = w;
    currentFrame.h = h;
}

float Entity::getX(){
    return x;
}
float Entity::getY(){
    return y;
}

SDL_Texture* Entity::getTexture(){
    return texture;
}

SDL_Rect* Entity::getCurrentFrame(){
    return &currentFrame;
}

void Entity::moveX(float _x){
   x += _x; 
   currentFrame.x = x;
}
void Entity::moveY(float _y){
   y += _y; 
   currentFrame.y = y;
}