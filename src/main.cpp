#include <SDL3/SDL.h>
#include <iostream>
#include <core/logger/logger.h>

int main()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        Logger::Error("SDL initialization failed\n");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "ChaoticEngine",
        800,
        600,
        0);

    Logger::Info("Window started...");

    if (!window)
    {
        Logger::Error("Window creation failed...");
        return 1;
    }

    bool running = true;

    Logger::Info("Loop starting now...");

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
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}