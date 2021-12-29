#pragma once
#include "SDL2/SDL.h"

class Window
{
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    bool running_;
public:
    /*
    * \param title the title of the window, in UTF-8 encoding
    * \param x the x position of the window, `SDL_WINDOWPOS_CENTERED`, or
    *          `SDL_WINDOWPOS_UNDEFINED`
    * \param y the y position of the window, `SDL_WINDOWPOS_CENTERED`, or
    *          `SDL_WINDOWPOS_UNDEFINED`
    * \param w the width of the window, in screen coordinates
    * \param h the height of the window, in screen coordinates
    * \param winflags 0, or one or more SDL_WindowFlags OR'd together
    * \param index the index of the rendering driver to initialize, or -1 to
    *              initialize the first one supporting the requested flags
    * \param rendflags 0, or one or more SDL_RendererFlags OR'd together
    * 
    * \returns the window that was created or exit on failure;
    */
    Window(const char* title, int x, int y, int w, int h, Uint32 winflags, int index, Uint32 rendflags);
    virtual ~Window();

    
    inline  int         clear           ()  { return SDL_RenderClear(renderer_);    };
    inline  void        present         ()  { SDL_RenderPresent(renderer_);         };
    
    inline   SDL_Window*   getWindow   ()  { return window_;   }
    inline   SDL_Renderer* getRenderer ()  { return renderer_; }

    inline void stop () { running_ = false; }

    virtual void onInit()   {};
    virtual void onExit()   {};
    /*  
    * \param event SDL_Event to process
    */
    virtual void onEvent(SDL_Event& event);
    virtual void onUpdate() =0;
    virtual void onRender() =0;
    void mainLoop();

    void run();


    inline  int         setDrawColor    (Uint8 r, Uint8 g, Uint8 b, Uint8 a)  
    { return SDL_SetRenderDrawColor(renderer_, r, g, b, a);}

    inline void showCursor(bool toggle) {SDL_ShowCursor(toggle?SDL_ENABLE:SDL_DISABLE);}
    inline bool isCursorShown()         {return SDL_ShowCursor(SDL_QUERY)==SDL_ENABLE;}
};