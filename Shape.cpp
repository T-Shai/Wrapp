#include "Shape.h"

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