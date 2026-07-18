#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cmath>
#include <numbers>
#include <core/logger/logger.h>

class Renderer
{
    SDL_Renderer *sdl_renderer;

public:
    Renderer(SDL_Window *);
    ~Renderer();
    void DrawRectangle(float, float, float, float, int, int, int, int);
    void RenderFrame();
    void FrameClear();
    void DrawTriangle();
    void DrawCircle(int);

    static SDL_FPoint RotationTheta(const SDL_FPoint &, float);
};