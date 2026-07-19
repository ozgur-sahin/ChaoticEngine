#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cmath>
#include <numbers>
#include <core/logger/logger.h>
// #include <graphics/texture/Texture.h>

class Window;

class Texture;

class Renderer
{
    SDL_Renderer *sdl_renderer;

public:
    Renderer(Window *);
    ~Renderer();
    void DrawRectangle(float, float, float, float, int, int, int, int);
    void RenderFrame();
    void FrameClear();
    void DrawTriangle();
    void DrawCircle(int);
    void DrawRectTexture(Texture *, SDL_FRect *);

    SDL_Renderer *GetSDL_Renderer();

    static SDL_FPoint RotationTheta(const SDL_FPoint &, const float);
};