#pragma once

#include <graphics/texture/Texture.h>
#include <vector>
#include <SDL3/SDL.h>

struct ChAnimation
{
    ChTexture *spritesheet; // master spritesheet that contains all of the frames

    std::vector<std::tuple<SDL_FRect, double>> frames; // frame rectangle and durations in ms

    bool looping;

    ChAnimation(ChTexture *texture, std::vector<std::tuple<SDL_FRect, double>> f, bool loop = false) : spritesheet{texture},
                                                                                                       frames{f},
                                                                                                       looping{loop} {};
};