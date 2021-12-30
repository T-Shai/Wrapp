#pragma once
#include "SDL2/SDL.h"

class Window;

namespace Shape
{   
    // Base shape class
    class Shape 
    {
        virtual void draw       (Window& w) =0;
        virtual void drawFill   (Window& w) =0;
    };
    
    // Rectangle
    class Rect : public Shape
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

        inline void scale (int d) { scale(d, d); }
        inline void scale (int dw, int dh) { rect_.w += dw; rect_.h += dh; }
        inline void scaleMult (int d) { scaleMult(d, d); }
        inline void scaleMult (int dw, int dh) { rect_.w *= dw; rect_.h *= dh; }

        // Draw
        void draw       (Window& w) override;
        void drawFill   (Window& w) override;
    };

    // Circle
    class Circle : public Shape
    {
        private:
            SDL_Point center_;
            int radius_;
            SDL_Color color_;
        
        public:
            Circle();
            Circle(SDL_Point center, int radius, SDL_Color color);
            Circle(SDL_Point center, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
            Circle(int centerx, int centery, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

            Circle(SDL_Point center, int radius);
            Circle(int centerx, int centery, int radius);
            ~Circle();

            // getters
            inline SDL_Point    getCenter   () { return center_;    }
            inline SDL_Color    getColor    () { return color_;     }
            inline int          getCenterX  () { return center_.x;  }
            inline int          getCenterY  () { return center_.y;  }
            inline int          getRadius   () { return radius_;    }

            // setters
            inline void         setCenter       (SDL_Point c)       { center_=c;    }
            inline void         setColor        (SDL_Color c)       { color_=c;     }
            inline void         setColor        (int r, int g, int b, int a)        {color_.r = r; color_.g = g; color_.b = b; color_.a = a; }
            inline void         setCenter       (int x, int y)      { center_.x=x; center_.y=y; }
            inline void         setCenterX      (int x)             { center_.x=x; }
            inline void         setCenterY      (int y)             { center_.y=y; }
            inline void         setRadius       (int r)             { radius_=r;   }


            inline void         scale       (int dr)    { radius_+= dr; }
            inline void         scaleMult   (int dr)    { radius_*= dr; }

            // Draw
            void draw       (Window& w) override;
            void drawFill   (Window& w) override;

    };
} // namespace Shape
