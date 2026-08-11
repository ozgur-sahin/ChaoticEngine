#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cmath>
#include <numbers>
#include <core/logger/logger.h>
#include <vector>

class ChWindow;

class ChTexture;

class ChRenderer
{
    SDL_Renderer *sdl_renderer;

public:
    ChRenderer(ChWindow *);
    ~ChRenderer();
    ChRenderer(const ChRenderer &) = delete;
    ChRenderer &operator=(const ChRenderer &) = delete;
    ChRenderer(ChRenderer &&) = delete;
    ChRenderer &operator=(ChRenderer &&) = delete;
    void DrawRectangle(float, float, float, float, int, int, int, int);
    void RenderFrame();
    void FrameClear();
    void DrawTriangle();
    void DrawCircle(int);
    void DrawRectTexture(ChTexture *, SDL_FRect *, SDL_FRect *srcRect = nullptr);

    void RenderDebugText(std::string);

    SDL_Renderer *GetSDL_Renderer() const;

    static SDL_FPoint RotationTheta(const SDL_FPoint &, const float);
};