#include <SDL3/SDL.h>
#include <iostream>

int main()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL initialization failed\n";
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "ChaoticEngine",
        800,
        600,
        0);

    if (!window)
    {
        std::cout << "Window creation failed\n";
        return 1;
    }

    bool running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}