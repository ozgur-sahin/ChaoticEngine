#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <core/logger/logger.h>
#include <string>
#include <graphics/renderer/renderer.h>
#include <graphics/texture/Texture.h>
#include <core/window/window.h>
#include <filesystem>

class ChEngine
{
    ChWindow *window;

    ChRenderer *renderer;

public:
    ChEngine();
    ~ChEngine();
    void run();
};