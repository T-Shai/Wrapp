#pragma once
#include "SDL2/SDL.h"




class Mouse
{   

    
    public:

        enum BUTTON
        {
            NONE    = -1,
            LEFT    = SDL_BUTTON_LEFT,
            MIDDLE  = SDL_BUTTON_MIDDLE,
            RIGHT   = SDL_BUTTON_RIGHT
        };


        static SDL_Point getPosition();
        static int       getX();
        static int       getY();
        
        static Uint32    getButtonState();
        static bool      isLeft     (Uint32 button=0);    
        static bool      isMiddle   (Uint32 button=0);    
        static bool      isRight    (Uint32 button=0);    


        static SDL_Point getGlobalPosition();
        static int       getGlobalX();
        static int       getGlobalY();
};