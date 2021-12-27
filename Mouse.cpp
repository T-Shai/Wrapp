#include "Mouse.h"

SDL_Point Mouse::getPosition()
{
    SDL_Point p;
    SDL_GetMouseState(&p.x, &p.y);
    return p;
}
int       Mouse::getX()
{
    int x;
    SDL_GetMouseState(&x, NULL);
    return x;
}
int       Mouse::getY()
{
    int y;
    SDL_GetMouseState(NULL, &y);
    return y;
    
}

Uint32 Mouse::getButtonState()
{
   return SDL_GetMouseState(NULL, NULL);
}

bool Mouse::isLeft(Uint32 button)
{
    if(button == 0) button =  SDL_GetMouseState(NULL, NULL);
    return SDL_BUTTON(Mouse::BUTTON::LEFT) & button;

}

bool Mouse::isMiddle(Uint32 button)
{
    if(button == 0) button =  SDL_GetMouseState(NULL, NULL);
    return SDL_BUTTON(Mouse::BUTTON::MIDDLE) & button;

}

bool Mouse::isRight(Uint32 button)
{
    if(button == 0) button =  SDL_GetMouseState(NULL, NULL);
    return SDL_BUTTON(Mouse::BUTTON::RIGHT) & button;
}

SDL_Point Mouse::getGlobalPosition()
{
    SDL_Point p;
    SDL_GetGlobalMouseState(&p.x, &p.y);
    return p;
}
int       Mouse::getGlobalX()
{
    int x;
    SDL_GetGlobalMouseState(&x, NULL);
    return x;
    
}
int       Mouse::getGlobalY()
{
    int y;
    SDL_GetGlobalMouseState(NULL, &y);
    return y;
}