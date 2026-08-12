#pragma once

#include <tuple>
#include <array>

#include <SDL3/SDL.h>

class ChTransform
{
    double XPosition;
    double YPosition;
    double XVelocity;
    double YVelocity;
    double ActorSizeX;
    double ActorSizeY;

public:
    ChTransform(double x = 0, double y = 0, double sizex = 50, double sizey = 50);
    void Update(float);
    std::array<double, 2> GetPosition() const;
    std::array<double, 2> GetVelocity() const;
    std::array<double, 2> GetActorSize() const;
    void TranslatePosition(double, double);
    void SetPosition(double, double);
    void SetVelocity(double, double);
    SDL_FRect FindDestRectFromTransform() const;
};