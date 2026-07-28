#include "transform.h"

ChTransform::ChTransform(double x, double y) : XPosition{x}, YPosition{y}
{
}

std::pair<double, double> ChTransform::GetPosition() const
{
    return std::pair<double, double>{XPosition, YPosition};
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