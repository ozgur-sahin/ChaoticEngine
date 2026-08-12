#pragma once

#include <array>
#include <string>
#include <core/actors/actor_components/transform.h>
#include <graphics/animation/actor_animator.h>
// #include <graphics/renderer/renderer.h>
// #include <core/main/asset_manager.h>

class ChScene;
class ChRenderer;
class ChAssetManager;

class ChActor
{
    double ActorLifetime{0};
    std::string class_code{}; // identifier for the texture for actors

public:
    ChActor();
    virtual ~ChActor();

    virtual void Tick(float, ChRenderer *);
    virtual void ConfigureAnimations(ChAssetManager *) {};
    virtual std::string GetTextureCode() { return ""; };
    virtual const std::string GetClassCode() const = 0;
    virtual const std::string GetAnimationFile() const = 0;

    std::string GetActorAddressAsString() const;

    ChTransform ActorTransform;
    ChActorAnimator Animator;

    bool isTickable;
};