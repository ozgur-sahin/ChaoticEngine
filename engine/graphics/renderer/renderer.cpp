#include "renderer.h"
#include <core/logger/logger.h>

Renderer::Renderer(SDL_Window *window)
{
    sdl_renderer = SDL_CreateRenderer(window, nullptr);
    if (!sdl_renderer)
    {
        Logger::Error(" SDL Renderer failed to initialize!");
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(sdl_renderer);
    Logger::Warning("SDL renderer deleted...");
}

void Renderer::DrawRectangle(float x, float y, float w, float h, int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(sdl_renderer, r, g, b, a);
    SDL_FRect rect{x, y, w, h};
    SDL_RenderFillRect(sdl_renderer, &rect);
}

void Renderer::FrameClear()
{
    SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
    SDL_RenderClear(sdl_renderer);
}

void Renderer::RenderFrame()
{
    SDL_RenderPresent(sdl_renderer);
}