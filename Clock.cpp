#include "Clock.h"

Uint64 Clock::start_ = 0;
Uint64 Clock::end_ = 0;
double Clock::delta_ = 0.0;

Uint64 Clock::fps_lasttime = 0;
Uint64 Clock::fps_frames = 0;
Uint64 Clock::fps_current = 0;

double Clock::tick(Uint64 fps)
{
    const Uint64 perfCountPerSec = SDL_GetPerformanceFrequency();
    const double target = (double)perfCountPerSec/fps;
    start_ = SDL_GetPerformanceCounter();
    delta_ = start_ - end_;
    while( ! (delta_ > target) )
    {
        /*
            target - delta | perfCountPerSec
                X          | 1000
            
            X = (1000 * (target - delta)) / perfCountPerSec
        */
        SDL_Delay( (1000 * (target - delta_)) / perfCountPerSec );
        start_ = SDL_GetPerformanceCounter();
        delta_ = start_ - end_;
    }
    end_ = start_;

    fps_frames++;
    if (fps_lasttime < SDL_GetTicks64() - 1000)
    {
        fps_lasttime = SDL_GetTicks64();
        fps_current = fps_frames;
        fps_frames = 0;
    }

    return delta_/perfCountPerSec; 
}




// test

// int main1(int argc, char *argv[])
// {
//   assert_ltz(SDL_Init(SDL_INIT_EVERYTHING), "SDL_Init");
//   #define FPS_INTERVAL 1.0 //seconds.
//   Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
//   Uint32 fps_current; //the current FPS.
//   Uint32 fps_frames = 0; //frames passed since the last recorded fps.
//   while (true)
//   {
//     Clock::tick(10);
//     printf(" delta : %f\n", Clock::getDelta());
//     printf(" fps : %d\n", fps_current);
//     fps_frames++;
//     if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL*1000)
//     {
//         fps_lasttime = SDL_GetTicks();
//         fps_current = fps_frames;
//         fps_frames = 0;
//     }
//   }
//   std::cout << "Performance frequency : " << SDL_GetPerformanceFrequency() << std::endl;
//   std::cout << "Performance counter : " << SDL_GetPerformanceCounter() << std::endl;
//   std::cout << "Performance counter/120 : " << (double)SDL_GetPerformanceFrequency()/120 << std::endl;
//   std::cout << "Performance counter : " << SDL_GetPerformanceCounter() << std::endl;
//   SDL_Quit();
//   return 0;
  
// }
