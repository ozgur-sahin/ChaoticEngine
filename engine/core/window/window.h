#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <tuple>

class ChWindow
{
    SDL_Window *sdl_window;
    int WindowHeight;
    int WindowWidth;

public:
    ChWindow(const int, const int);
    ChWindow(const ChWindow &) = delete;
    ChWindow &operator=(const ChWindow &) = delete;
    ChWindow(ChWindow &&) noexcept;
    ChWindow &operator=(ChWindow &&) noexcept;
    ~ChWindow();
    SDL_Window *GetSDL_Window() const;
    const std::tuple<const int, const int> GetWindowSize() const;
};