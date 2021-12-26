#include "stdio.h"
#include "SDL2/SDL.h"

#include <iostream>

#include "Window.h"
#include "Clock.h"

class MyWindow: public Window
{

  public:

    using Window::Window;

    void onRender () override
    {
      std::cout << "FPS : " << Clock::getFPS() << std::endl;
      std::cout << "delta : " << Clock::tick(30) << std::endl;
    }

    void onUpdate () override
    {
    } 
};






void assert_ltz(int code, const char* funcname)
{
  if(code < 0)
  {
    printf("%s failed: %s\n", funcname, SDL_GetError());
    exit(code);
  }
}
const int WIDTH = 800, HEIGHT = 600;

int main1(int argc, char *argv[])
{
  assert_ltz(SDL_Init(SDL_INIT_EVERYTHING), "SDL_Init");
  #define FPS_INTERVAL 1.0 //seconds.
  Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
  Uint32 fps_current; //the current FPS.
  Uint32 fps_frames = 0; //frames passed since the last recorded fps.
  while (true)
  {
    Clock::tick(10);
    printf(" delta : %f\n", Clock::getDelta());
    printf(" fps : %d\n", fps_current);
    fps_frames++;
    if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL*1000)
    {
        fps_lasttime = SDL_GetTicks();
        fps_current = fps_frames;
        fps_frames = 0;
    }
  }
  std::cout << "Performance frequency : " << SDL_GetPerformanceFrequency() << std::endl;
  std::cout << "Performance counter : " << SDL_GetPerformanceCounter() << std::endl;
  std::cout << "Performance counter/120 : " << (double)SDL_GetPerformanceFrequency()/120 << std::endl;
  std::cout << "Performance counter : " << SDL_GetPerformanceCounter() << std::endl;
  SDL_Quit();
  return 0;
  
}


int main(int argc, char *argv[])
{
    assert_ltz(SDL_Init(SDL_INIT_EVERYTHING), "SDL_Init");

    MyWindow w("new window", 
                    SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED,
                    WIDTH, HEIGHT,
                    SDL_WINDOW_ALLOW_HIGHDPI,
                    -1, SDL_RENDERER_ACCELERATED);
    w.setDrawColor(255, 0, 0, 255);
    w.clear();
    w.present();
    w.run();
    SDL_Quit();
    return 0;
}
