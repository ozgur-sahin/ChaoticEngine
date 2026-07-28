#pragma once

#include <tuple>

class ChTransform
{
    double XPosition;
    double YPosition;

public:
    ChTransform(double x = 0, double y = 0);
    std::pair<double, double> GetPosition() const;
    void TranslatePosition(double, double);
    void SetPosition(double, double);
};