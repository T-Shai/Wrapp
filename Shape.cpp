#include "Shape.h"
#include "Window.h"
#include <cmath>
using namespace Shape;

#define SAVE_COLOR() SDL_Color _save; SDL_GetRenderDrawColor(w.getRenderer(), &_save.r, &_save.g, &_save.b, &_save.a)
#define LOAD_COLOR() SDL_SetRenderDrawColor(w.getRenderer(), _save.r, _save.g, _save.b, _save.a)

/* Rectangle */
Rect::Rect()
:Rect(0, 0, 0, 0, 0, 0, 0, 0)
{}

Rect::Rect(SDL_Rect r, SDL_Color c)
:rect_(r), color_(c)
{}

Rect::Rect(int x, int y, int w, int h, SDL_Color c)
:Rect({x,y,w,h}, c)
{}

Rect::Rect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
:Rect({x,y,w,h}, {r,g,b,a})
{}

Rect::~Rect()
{}

void Rect::draw(Window& w)
{
    SAVE_COLOR();
    
    SDL_SetRenderDrawColor(w.getRenderer(), color_.r, color_.g, color_.b, color_.a);
    SDL_RenderDrawRect(w.getRenderer(), &rect_);

    LOAD_COLOR();
    
}

void Rect::drawFill(Window& w)
{
    SAVE_COLOR();

    SDL_SetRenderDrawColor(w.getRenderer(), color_.r, color_.g, color_.b, color_.a);
    SDL_RenderFillRect(w.getRenderer(), &rect_);

    LOAD_COLOR();
}

/* Circle */

Circle::Circle()
: Circle(0, 0, 0, 255, 0, 0, 0)
{}

Circle::Circle(SDL_Point center, int radius, SDL_Color color)
: center_(center), radius_(radius), color_(color)
{}

Circle::Circle(SDL_Point center, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
: Circle(center, radius,{r, g, b, a})
{}

Circle::Circle(int centerx, int centery, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
: Circle({centerx, centery}, radius, {r, g, b, a})
{}


Circle::Circle(SDL_Point center, int radius)
: Circle(center, radius, 255, 0, 0, 0)
{}

Circle::Circle(int centerx, int centery, int radius)
: Circle({centerx, centery}, radius, 255, 0, 0, 0)
{}

Circle::~Circle()
{}

void Circle::draw(Window& w)
{
    SAVE_COLOR();
    SDL_SetRenderDrawColor(w.getRenderer(), color_.r, color_.g, color_.b, color_.a);
    
    const int diameter = (radius_ * 2);

    int x = (radius_ - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y)
    {
        SDL_RenderDrawPoint(w.getRenderer(), center_.x + x, center_.y - y);
        SDL_RenderDrawPoint(w.getRenderer(), center_.x + x, center_.y + y);
        SDL_RenderDrawPoint(w.getRenderer(), center_.x - x, center_.y - y);
        SDL_RenderDrawPoint(w.getRenderer(), center_.x - x, center_.y + y);
        SDL_RenderDrawPoint(w.getRenderer(), center_.x + y, center_.y - x);
        SDL_RenderDrawPoint(w.getRenderer(), center_.x + y, center_.y + x);
        SDL_RenderDrawPoint(w.getRenderer(), center_.x - y, center_.y - x);
        SDL_RenderDrawPoint(w.getRenderer(), center_.x - y, center_.y + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
        }

    LOAD_COLOR();
}

void Circle::drawFill   (Window& w)
{
    SAVE_COLOR();
    SDL_SetRenderDrawColor(w.getRenderer(), color_.r, color_.g, color_.b, color_.a);

    int offsetx, offsety, d;

    offsetx = 0;
    offsety = radius_;
    d = radius_ -1;
    while (offsety >= offsetx) {

        SDL_RenderDrawLine(w.getRenderer(), center_.x - offsety, center_.y + offsetx, center_.x + offsety, center_.y + offsetx);
        SDL_RenderDrawLine(w.getRenderer(), center_.x - offsetx, center_.y + offsety, center_.x + offsetx, center_.y + offsety);
        SDL_RenderDrawLine(w.getRenderer(), center_.x - offsetx, center_.y - offsety, center_.x + offsetx, center_.y - offsety);
        SDL_RenderDrawLine(w.getRenderer(), center_.x - offsety, center_.y - offsetx, center_.x + offsety, center_.y - offsetx);

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius_ - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    LOAD_COLOR();
}


#undef SAVE_COLOR
#undef LOAD_COLOR