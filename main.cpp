#include "stdio.h"
#include "SDL2/SDL.h"

#include <iostream>

#include "Window.h"
#include "Clock.h"
#include "Mouse.h"

class MyWindow: public Window
{

  public:

    using Window::Window;

    void onRender () override
    {
      setDrawColor(0, 0, 0, 255);
      clear();
      std::cout << "FPS : " << Clock::getFPS() << std::endl;
      std::cout << "delta : " << Clock::tick(60*2) << std::endl;
      SDL_Rect r;
      
      r.x = Mouse::getX();
      r.y = Mouse::getY();

      SDL_GetWindowSize(getWindow(), &r.w, &r.h);
      r.w /= 16;
      r.h /= 16;

      if(Mouse::isLeft()) setDrawColor(255, 0, 0, 0);
      else if (Mouse::isMiddle()) setDrawColor(0, 255, 0, 0);
      else if (Mouse::isRight()) setDrawColor(0, 0, 255, 0);
      else setDrawColor(255, 255, 255, 0);
      
      SDL_RenderFillRect(getRenderer(), &r);
      present();
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

int main(int argc, char *argv[])
{
    assert_ltz(SDL_Init(SDL_INIT_EVERYTHING), "SDL_Init");

    MyWindow w("new window", 
                    SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED,
                    WIDTH, HEIGHT,
                    SDL_WINDOW_ALLOW_HIGHDPI,
                    -1, 0);
    w.run();
    SDL_Quit();
    return 0;
}
