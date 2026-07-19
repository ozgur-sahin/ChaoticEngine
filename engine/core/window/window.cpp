#include <core/window/window.h>
#include <core/logger/logger.h>

Window::Window(const int WindowWidth, const int WindowHeight)
{
    sdl_window = SDL_CreateWindow("Chaotic Engine", WindowWidth, WindowHeight, 0);

    if (!sdl_window)
    {
        Logger::Error("Window creation failed...");
        throw std::runtime_error("Window creation failed! Aborting...\n");
    }
}

Window::~Window()
{
    SDL_DestroyWindow(sdl_window);
}

SDL_Window *Window::GetSDL_Window()
{
    return sdl_window;
}