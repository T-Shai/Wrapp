#pragma once
#include "SDL2/SDL.h"

class Clock
{
private:
    /* tick */
    static Uint64 start_;
    static Uint64 end_;
    static double delta_;

    /* fps */
    static Uint64 fps_lasttime; //the last recorded time.
    static Uint64 fps_current; //the current FPS.
    static Uint64 fps_frames; //frames passed since the last recorded fps.
public:
    static inline   Uint64 getTick () { return SDL_GetTicks64();}
    static inline   double getDelta () { return delta_/(double)SDL_GetPerformanceFrequency();}
    static double   tick    (Uint64 fps);     

    static inline   Uint64 getFPS () {return fps_current; }
};