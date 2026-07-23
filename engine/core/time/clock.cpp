#include "clock.h"
#include <core/logger/logger.h>

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
    Logger::Info("Deltatime: ");
}