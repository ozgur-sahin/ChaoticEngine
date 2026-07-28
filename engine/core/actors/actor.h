#pragma once

#include <core/actors/actor_components/transform.h>
#include <graphics/animation/actor_animator.h>

class ChActor
{
    ChTransform ActorTransform;
    ChActorAnimator Animator;

    bool isTickable;

public:
    ChActor(double, double);
    virtual ~ChActor();

    virtual void Tick(float);
};