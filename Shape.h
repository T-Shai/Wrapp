#pragma once
#include "SDL2/SDL.h"

namespace Shape
{
    class Rect
    {
    private:
        SDL_Rect rect_;
        SDL_Color color_;
        
    public:
        Rect();
        Rect(SDL_Rect r, SDL_Color c);
        Rect(int x, int y, int w, int h, SDL_Color c);
        Rect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        ~Rect();

        // getters
        inline const int getX () const { return rect_.x; } 
        inline const int getY () const { return rect_.y; } 
        inline const int getWidth     () const { return rect_.w; } 
        inline const int getHeight    () const { return rect_.h; }

        inline SDL_Color getColor() const { return color_; }
        inline SDL_Rect getRect() const { return rect_; }
        
        // setters 
        inline void setX (int x) { rect_.x = x; } 
        inline void setY (int y) { rect_.y = y; } 
        inline void setWidth    (int w) { rect_.w = w; } 
        inline void setHeight   (int h) { rect_.h = h; } 
        inline void setColor (int r, int g, int b, int a) { color_.r = r; color_.g = g; color_.b = b; color_.a= a; } 
    };    
    
    
} // namespace Shape
