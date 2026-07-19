#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Window
{
    SDL_Window *sdl_window;

public:
    Window(const int, const int);
    ~Window();
    SDL_Window *GetSDL_Window();
};