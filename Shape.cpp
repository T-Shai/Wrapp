#include "Shape.h"
#include "Window.h"

using namespace Shape;

/* Rectangle */
Rect::Rect()
:Rect(0, 0, 0, 0, 0, 0, 0, 0)
{}

Rect::Rect(SDL_Rect r, SDL_Color c)
:rect_(r), color_(c)
{}

Rect::Rect(int x, int y, int w, int h, SDL_Color c)
:rect_({x,y,w,h}), color_(c)
{}

Rect::Rect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
:rect_({x,y,w,h}), color_({r,g,b,a})
{}

Rect::~Rect()
{}

void Rect::draw(Window& w)
{
    SDL_Color save;
    SDL_GetRenderDrawColor(w.getRenderer(), &save.r, &save.g, &save.b, &save.a);
    
    SDL_SetRenderDrawColor(w.getRenderer(), color_.r, color_.g, color_.b, color_.a);
    SDL_RenderDrawRect(w.getRenderer(), &rect_);

    SDL_SetRenderDrawColor(w.getRenderer(), save.r, save.g, save.b, save.a);
}

void Rect::drawFill(Window& w)
{
    SDL_Color save;
    SDL_GetRenderDrawColor(w.getRenderer(), &save.r, &save.g, &save.b, &save.a);
    
    SDL_SetRenderDrawColor(w.getRenderer(), color_.r, color_.g, color_.b, color_.a);
    SDL_RenderFillRect(w.getRenderer(), &rect_);

    SDL_SetRenderDrawColor(w.getRenderer(), save.r, save.g, save.b, save.a);
}