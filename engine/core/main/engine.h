#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <core/logger/logger.h>
#include <string>
#include <graphics/renderer/renderer.h>
#include <graphics/texture/Texture.h>
#include <graphics/sprite/sprite.h>
#include <core/window/window.h>
#include <core/time/game_clock.h>
#include <filesystem>

class ChEngine
{
    ChWindow window;

    ChRenderer renderer;

    ChClock clock;

    int targetFPS;
    double targetFrametime;

public:
    ChEngine(const int, const int, const int);
    ~ChEngine();
    void run();
    void ShowFPSCounter();
};