#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Renderer
{
    SDL_Renderer *sdl_renderer;

public:
    Renderer(SDL_Window *);
    ~Renderer();
    void DrawRectangle(float, float, float, float, int, int, int, int);
    void RenderFrame();
    void FrameClear();
};