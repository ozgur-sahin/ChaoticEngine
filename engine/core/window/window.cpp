#include <core/window/window.h>
#include <core/logger/logger.h>

ChWindow::ChWindow(const int w, const int h)
{
    WindowHeight = h;
    WindowWidth = w;
    sdl_window = SDL_CreateWindow("Chaotic Engine", WindowWidth, WindowHeight, 0);

    if (!sdl_window)
    {
        Logger::Error("Window creation failed...");
        throw std::runtime_error("Window creation failed! Aborting...\n");
    }
}

ChWindow::~ChWindow()
{
    SDL_DestroyWindow(sdl_window);
}

SDL_Window *ChWindow::GetSDL_Window()
{
    return sdl_window;
}