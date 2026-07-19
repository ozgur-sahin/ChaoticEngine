#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <core/logger/logger.h>

class ChRenderer;

class ChTexture
{
    SDL_Texture *sdl_texture;
    int h;
    int w;

public:
    ChTexture(SDL_Renderer *, const int, const int);
    ChTexture(ChRenderer *, const std::string);
    ~ChTexture();
    SDL_Texture *GetSDL_Texture();
};