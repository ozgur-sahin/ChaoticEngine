#pragma once

#include <iostream>
#include <filesystem>
#include <string>

#include <graphics/renderer/renderer.h>
#include <core/logger/logger.h>
#include <core/window/window.h>
#include <core/time/game_clock.h>
#include <core/main/asset_manager.h>

class ChScene;

class ChEngine
{
private:
    ChWindow window;

    ChRenderer renderer;

    ChAssetManager asset_manager;

    std::unique_ptr<ChScene> scene;

    ChClock clock;

    const int targetFPS;
    const double targetFrametime; // in ms

public:
    ChEngine(const int, const int, const int);
    ~ChEngine();
    void run();
    void ShowFPSCounter();
    void LoadScene(std::unique_ptr<ChScene>);
    ChAssetManager *GetAssetManager() { return &asset_manager; }
};