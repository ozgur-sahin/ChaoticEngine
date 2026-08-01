#pragma once

#include <tuple>
#include <array>
#include <SDL3/SDL.h>

class ChTransform
{
    double XPosition;
    double YPosition;
    double ActorSizeX;
    double ActorSizeY;

public:
    ChTransform(double x = 0, double y = 0, double sizex = 50, double sizey = 50);
    std::array<double, 2> GetPosition() const;
    std::array<double, 2> GetActorSize() const;
    void TranslatePosition(double, double);
    void SetPosition(double, double);
    SDL_FRect FindDestRectFromTransform() const;
};