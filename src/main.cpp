#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <core/logger/logger.h>
#include <string>
#include <graphics/renderer/renderer.h>
#include <graphics/texture/Texture.h>
#include <core/window/window.h>
#include <filesystem>

int main()
{

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        Logger::Error("SDL initialization failed\n");
        return 1;
    }

    const int WindowHeight = 800;
    const int WindowWidth = 600;

    Window window(WindowHeight, WindowWidth);

    Logger::Info("Window started...");

    Renderer CHRenderer(&window);

    bool running = true;

    Logger::Info("Game loop starting now...");

    Texture Player(&CHRenderer, "assets/textures/RedPlayerSpriteSheet.png");

    SDL_FRect rect{200, 200, 150, 200};

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
                Logger::Info("Window no longer running...");
            }
        }
        CHRenderer.FrameClear();
        CHRenderer.DrawRectangle(100, 100, 50, 50, 255, 0, 0, 255);
        CHRenderer.DrawTriangle();
        CHRenderer.DrawCircle(100);
        CHRenderer.DrawRectTexture(&Player, &rect);

        CHRenderer.RenderFrame();
    }
    SDL_Quit();

    return 0;
}