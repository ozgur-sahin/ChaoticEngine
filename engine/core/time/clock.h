#pragma once

#include <chrono>

class ChClock
{
public:
    using Clock = std::chrono::steady_clock;
    using time_point = Clock::time_point;

private:
    time_point current;
    time_point previous;
    time_point global_timer;
    std::chrono::duration<double, std::milli> deltaTime;

public:
    ChClock();
    double GetDeltaTime() const;
    void Update();
};