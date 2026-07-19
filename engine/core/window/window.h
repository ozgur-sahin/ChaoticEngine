#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class ChWindow
{
    SDL_Window *sdl_window;

public:
    ChWindow(const int, const int);
    ~ChWindow();
    SDL_Window *GetSDL_Window();
};