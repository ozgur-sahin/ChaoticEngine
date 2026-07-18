#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <core/logger/logger.h>
#include <string>
#include <graphics/renderer/renderer.h>

int main()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        Logger::Error("SDL initialization failed\n");
        return 1;
    }

    const int WindowHeight = 800;
    const int WindowWidth = 600;

    SDL_Window *window = SDL_CreateWindow(
        "ChaoticEngine",
        WindowHeight,
        WindowWidth,
        0);

    Logger::Info("Window started...");

    if (!window)
    {
        Logger::Error("Window creation failed...");
        return 1;
    }

    Renderer CHRenderer(window);

    bool running = true;

    Logger::Info("Game loop starting now...");

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

        CHRenderer.RenderFrame();
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}