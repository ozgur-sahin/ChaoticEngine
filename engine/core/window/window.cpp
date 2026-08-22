#include <core/window/window.h>
#include <core/logger/logger.h>

ChWindow::ChWindow(const int w, const int h)
{
    WindowHeight = h;
    WindowWidth = w;
    sdl_window = SDL_CreateWindow("Chaotic Engine", WindowWidth, WindowHeight, 0);

    if (!sdl_window)
    {
        CH_LOG_ERROR("Window creation failed...");
        throw std::runtime_error("Window creation failed! Aborting...\n");
    }
}

ChWindow::ChWindow(ChWindow &&old_window) noexcept
{
    sdl_window = old_window.sdl_window;
    old_window.sdl_window = nullptr;
}

ChWindow &ChWindow::operator=(ChWindow &&old_window) noexcept
{
    if (this != &old_window)
    {
        SDL_DestroyWindow(sdl_window);
        sdl_window = old_window.sdl_window;
        old_window.sdl_window = nullptr;
    }
    return *this;
}

ChWindow::~ChWindow()
{
    SDL_DestroyWindow(sdl_window);
}

SDL_Window *ChWindow::GetSDL_Window() const
{
    return sdl_window;
}

const std::tuple<const int, const int> ChWindow::GetWindowSize() const
{
    return std::tuple<const int, const int>{WindowHeight, WindowWidth};
}