#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_events.h>
#include <iostream>
#include <core/logger/logger.h>
#include <string>
#include <graphics/renderer/renderer.h>
#include <graphics/texture/Texture.h>
#include <graphics/sprite/sprite.h>
#include <core/window/window.h>
#include <core/time/game_clock.h>
#include <filesystem>
#include <core/actors/actor.h>
#include <core/main/scene.h>
#include "../src/player_character.h"
#include <graphics/animation/actor_animator.h>
#include <graphics/animation/animation.h>

class ChEngine
{
    ChWindow window;

    ChRenderer renderer;

    ChScene scene;

    ChClock clock;

    const int targetFPS;
    const double targetFrametime; // in ms

public:
    ChEngine(const int, const int, const int);
    ~ChEngine();
    void run();
    void ShowFPSCounter();
};