#pragma once

#include <array>
#include <string>
#include <core/actors/actor_components/transform.h>
#include <graphics/animation/actor_animator.h>
#include <graphics/renderer/renderer.h>

class ChActor
{
    double ActorLifetime{0};
    std::string TextureCode{}; // identifier for the texture for actors

public:
        ChActor();
    virtual ~ChActor();

    virtual void Tick(float, ChRenderer *);
    virtual void ConfigureAnimations(ChTexture *) {};
    virtual std::string GetTextureCode() = 0;

    std::string GetActorAddressAsString() const;

    ChTransform ActorTransform;
    ChActorAnimator Animator;

    bool isTickable;
};