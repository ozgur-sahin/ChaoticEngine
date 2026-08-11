#pragma once

#include <graphics/texture/Texture.h>
#include <vector>
#include <tuple>
#include <SDL3/SDL.h>

struct ChAnimation
{
    using frametype = std::tuple<SDL_FRect, double>;

    ChTexture *spritesheet{}; // master spritesheet that contains all of the frames

    std::vector<frametype> frames{}; // frame rectangle and durations in ms

    SDL_FRect currentFrame;

    std::vector<double> frameTimeTable{};

    bool looping;

    ChAnimation(ChTexture *texture, std::vector<std::tuple<SDL_FRect, double>> f, bool loop = true) : spritesheet{texture},
                                                                                                      frames{f},
                                                                                                      looping{loop}

    {
        double timecounter{0};
        for (auto frame : frames)
        {
            timecounter += std::get<double>(frame);
            frameTimeTable.push_back(timecounter);
        }
    };
};