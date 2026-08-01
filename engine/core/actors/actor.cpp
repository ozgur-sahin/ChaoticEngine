#include "actor.h"

#include <sstream>

ChActor::ChActor(double x, double y, double sizex, double sizey) : ActorTransform{x, y, sizex, sizey}
{
    ActorTransform.SetVelocity(0.005, 0);
}

ChActor::~ChActor()
{
}

void ChActor::Tick(float DeltaTime, ChRenderer *renderer)
{
    // Logger::Info("Actor Coordinates: " + std::to_string(ActorTransform.GetPosition()[0]));
    ActorLifetime += DeltaTime; // in ms

    // Logger::Info("Actor " + GetActorAddressAsString() + " lifetime: " + std::to_string(ActorLifetime));

    ActorTransform.Update(DeltaTime);
    SDL_FRect destrect = ActorTransform.FindDestRectFromTransform();

    Animator.AnimationUpdate(DeltaTime, destrect, renderer);
}

std::string ChActor::GetActorAddressAsString() const
{
    std::ostringstream oss;
    oss << this;
    return oss.str();
}