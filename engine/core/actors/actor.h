#pragma once

#include <array>
#include <string>
#include <core/actors/actor_components/transform.h>
#include <graphics/animation/actor_animator.h>
#include <graphics/renderer/renderer.h>

class ChActor
{
    double ActorLifetime{0};

public:
    ChActor(double, double, double, double);
    virtual ~ChActor();

    virtual void Tick(float, ChRenderer *);
    virtual void ConfigureAnimations() {};

    std::string GetActorAddressAsString() const;

    ChTransform ActorTransform;
    ChActorAnimator Animator;

    bool isTickable;
};