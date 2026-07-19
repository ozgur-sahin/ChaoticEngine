#include "renderer.h"

Renderer::Renderer(SDL_Window *window)
{
    sdl_renderer = SDL_CreateRenderer(window, nullptr);
    if (!sdl_renderer)
    {
        Logger::Error("SDL Renderer failed to initialize!");
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(sdl_renderer);
    Logger::Info("SDL renderer deleted...");
}

SDL_FPoint Renderer::RotationTheta(const SDL_FPoint &point, const float theta)
{
    SDL_FPoint RotatedPoint{
        point.x * std::cos(theta) - point.y * std::sin(theta),
        point.x * std::sin(theta) + point.y * std::cos(theta)};
    return RotatedPoint;
}

void Renderer::DrawRectangle(float x, float y, float w, float h, int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(sdl_renderer, r, g, b, a);
    SDL_FRect rect{x, y, w, h};
    SDL_RenderFillRect(sdl_renderer, &rect);
}

void Renderer::DrawTriangle()
{
    SDL_Vertex vertices[3];
    vertices[0] = SDL_Vertex{
        {0, 0},
        {255, 0, 0, 255},
        {0, 0},
    };

    vertices[1] = SDL_Vertex{
        {100, 0},
        {255, 0, 0, 255},
        {0, 0},
    };

    vertices[2] = SDL_Vertex{
        {50, 50},
        {255, 0, 0, 255},
        {0, 0},
    };

    if (!SDL_RenderGeometry(sdl_renderer, nullptr, vertices, 3, nullptr, 0))
    {
        Logger::Error("Error drawing a triangle!");
    };
}

void Renderer::DrawCircle(int vertexno)
{
    float radius = 100.0f;
    float center[2]{400.0f, 300.0f};
    float theta = 2 * std::numbers::pi / vertexno; // rotation angle for computing the coordinates of SDL_FPoints

    std::vector<SDL_FPoint> points;
    points.push_back({radius, 0});

    for (int i = 1; i < vertexno; i++)
    {
        points.push_back(Renderer::RotationTheta(points.at(i - 1), theta));
    }
    points.push_back({radius, 0});

    for (auto &point : points)
    {
        point = SDL_FPoint{point.x + center[0],
                           point.y + center[1]};
    }

    if (!SDL_RenderLines(sdl_renderer, points.data(), points.size()))
    {
        Logger::Error("Error drawing a circle!");
    };
}

void Renderer::FrameClear()
{
    SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
    SDL_RenderClear(sdl_renderer);
}

void Renderer::RenderFrame()
{
    SDL_RenderPresent(sdl_renderer);
}