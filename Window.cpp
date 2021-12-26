#include "Window.h"

Window::Window(const char* title, int x, int y, int w, int h, Uint32 winflags, int index, Uint32 rendflags)
: running_(false) 
{
    window_ = SDL_CreateWindow(title, x, y, w, h, winflags);
    if(window_ == NULL)
    {
        printf("[ERROR] SDL_CreateWindow FAILED : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    renderer_ = SDL_CreateRenderer(window_, index, rendflags);
    if(!renderer_)
    {
        printf("[ERROR] SDL_CreateRenderer FAILED : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
}
void Window::onEvent(SDL_Event& event)
{
    switch (event.type)
    {
    case SDL_QUIT:
        running_ = false;
        break;
    
    default:
        break;
    }
}

void Window::mainLoop()
{
    SDL_Event event;
    while(running_)
    {
        if(SDL_PollEvent(&event))
        {
            onEvent(event);
        }
        onUpdate();
        onRender();
    }
}
void Window::run()
{
    onRun();
    running_ = true;
    mainLoop();
    onExit();
}