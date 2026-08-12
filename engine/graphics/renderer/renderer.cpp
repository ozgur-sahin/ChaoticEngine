#include "renderer.h"
#include <graphics/texture/Texture.h>
#include <core/window/window.h>

ChRenderer::ChRenderer(ChWindow *window)
{
    sdl_renderer = SDL_CreateRenderer(window->GetSDL_Window(), nullptr);
    if (!sdl_renderer)
    {
        Logger::Error("SDL Renderer failed to initialize!");
    }
}

ChRenderer::~ChRenderer()
{
    SDL_DestroyRenderer(sdl_renderer);
    // Logger::Info("SDL renderer deleted...");
}

ChRenderer::ChRenderer(ChRenderer &&old_renderer) noexcept
{
    sdl_renderer = old_renderer.sdl_renderer;
    old_renderer.sdl_renderer = nullptr;
}

ChRenderer &ChRenderer::operator=(ChRenderer &&old_renderer) noexcept
{
    if (this != &old_renderer)
    {
        SDL_DestroyRenderer(sdl_renderer);
        sdl_renderer = old_renderer.sdl_renderer;
        old_renderer.sdl_renderer = nullptr;
    }
    return *this;
}

SDL_FPoint ChRenderer::RotationTheta(const SDL_FPoint &point, const float theta)
{
    SDL_FPoint RotatedPoint{
        point.x * std::cos(theta) - point.y * std::sin(theta),
        point.x * std::sin(theta) + point.y * std::cos(theta)};
    return RotatedPoint;
}

void ChRenderer::DrawRectangle(float x, float y, float w, float h, int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(sdl_renderer, r, g, b, a);
    SDL_FRect rect{x, y, w, h};
    SDL_RenderFillRect(sdl_renderer, &rect);
}

void ChRenderer::DrawRectTexture(ChTexture *texture, SDL_FRect *destRect, SDL_FRect *srcRect)
{
    SDL_RenderTexture(sdl_renderer, texture->GetSDL_Texture(), srcRect, destRect);
}

void ChRenderer::DrawTriangle()
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

void ChRenderer::DrawCircle(int vertexno)
{
    float radius = 100.0f;
    float center[2]{400.0f, 300.0f};
    float theta = 2 * std::numbers::pi / vertexno; // rotation angle for computing the coordinates of SDL_FPoints

    std::vector<SDL_FPoint> points;
    points.push_back({radius, 0});

    for (int i = 1; i < vertexno; i++)
    {
        points.push_back(ChRenderer::RotationTheta(points.at(i - 1), theta));
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

void ChRenderer::FrameClear()
{
    SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
    SDL_RenderClear(sdl_renderer);
}

void ChRenderer::RenderFrame()
{
    SDL_RenderPresent(sdl_renderer);
}

SDL_Renderer *ChRenderer::GetSDL_Renderer() const
{
    return sdl_renderer;
}

void ChRenderer::RenderDebugText(std::string Text)
{
    std::vector<Uint8> old_color(4);
    SDL_GetRenderDrawColor(sdl_renderer, &old_color[0], &old_color[1], &old_color[2], &old_color[3]);
    SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
    SDL_RenderDebugText(sdl_renderer, 0, 0, Text.c_str());
    SDL_SetRenderDrawColor(sdl_renderer, old_color[0], old_color[1], old_color[2], old_color[3]);
}