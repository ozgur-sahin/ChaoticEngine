#include "actor.h"

ChActor::ChActor(double x, double y) : ActorTransform{x, y}
{
}

ChActor::~ChActor()
{
}

void ChActor::Tick(float DeltaTime)
{
}