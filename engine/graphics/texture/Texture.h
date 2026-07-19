#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <core/logger/logger.h>
// #include <graphics/renderer/renderer.h>

class Renderer;

class Texture
{
    SDL_Texture *sdl_texture;

public:
    // Texture(SDL_Renderer *, const int, const int);
    Texture(Renderer *, const std::string);
    ~Texture();
    SDL_Texture *GetSDL_Texture();
};