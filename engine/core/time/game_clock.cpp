#include "game_clock.h"
#include <core/logger/logger.h>
#include <graphics/renderer/renderer.h>
#include <thread>

ChClock::ChClock()
{
    current = Clock::now();
    global_timer = Clock::now();
    previous = current;
}

double ChClock::GetDeltaTime() const
{
    return deltaTime.count();
}

void ChClock::Update()
{
    previous = current;
    current = Clock::now();
    deltaTime = current - previous;
    // CH_LOG_INFO("Deltatime: ");
}

void ChClock::EnforceFrameLimit(double targetFrametime)
{
    auto DurationTargetFrameTime = std::chrono::duration<double, std::milli>(targetFrametime);
    if (deltaTime < DurationTargetFrameTime)
    {
        auto SleepDuration = DurationTargetFrameTime - deltaTime;
        // CH_LOG_INFO("Sleeping for " + std::to_string(SleepDuration.count()) + " ms");
        std::this_thread::sleep_for(SleepDuration);
    }
}