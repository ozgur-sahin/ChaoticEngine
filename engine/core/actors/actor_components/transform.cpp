#include "transform.h"

ChTransform::ChTransform(double x, double y, double sizex, double sizey) : XPosition{x}, YPosition{y}, ActorSizeX{sizex}, ActorSizeY{sizey}
{
}

void ChTransform::Update(float DeltaTime)
{
    TranslatePosition(XVelocity * DeltaTime, YVelocity * DeltaTime);
}

std::array<double, 2> ChTransform::GetPosition() const
{
    return std::array<double, 2>{XPosition, YPosition};
}

std::array<double, 2> ChTransform::GetVelocity() const
{
    return std::array<double, 2>{XVelocity, YVelocity};
}

std::array<double, 2> ChTransform::GetActorSize() const
{
    return std::array<double, 2>{XPosition, YPosition};
}

void ChTransform::TranslatePosition(double deltax, double deltay)
{
    XPosition += deltax;
    YPosition += deltay;
}

void ChTransform::SetPosition(double x, double y)
{
    XPosition = x;
    YPosition = y;
}

void ChTransform::SetVelocity(double vx, double vy)
{
    XVelocity = vx;
    YVelocity = vy;
}

SDL_FRect ChTransform::FindDestRectFromTransform() const
{
    return SDL_FRect{static_cast<float>(XPosition - ActorSizeX / 2),
                     static_cast<float>(YPosition - ActorSizeY / 2),
                     static_cast<float>(ActorSizeX),
                     static_cast<float>(ActorSizeY)};
}