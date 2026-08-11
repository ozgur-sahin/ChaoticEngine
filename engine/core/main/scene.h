#pragma once

#include <core/actors/actor.h>
#include <graphics/renderer/renderer.h>
#include <core/window/window.h>
#include <core/main/asset_manager.h>
#include <vector>
#include <memory>

// delete these includes later
#include "../src/player_character.h"

class ChScene
{

    std::vector<std::unique_ptr<ChActor>> actors{};
    ChRenderer &renderer;
    ChAssetManager &asset_manager;

public:
    ChScene(ChRenderer &, ChAssetManager &);
    virtual ~ChScene() {};

    virtual void TickActors(float);
    virtual void BeginPlay() {};

    template <std::derived_from<ChActor> T>
    void AddActor(double xpos, double ypos)
    {
        std::unique_ptr<ChActor> new_actor{new T{}};
        new_actor->ActorTransform.SetPosition(xpos, ypos);
        new_actor->ActorTransform.SetVelocity(0.005, 0.005);
        Logger::Info("New actor with texture code: " + new_actor->GetClassCode() + "\n");
        new_actor->ConfigureAnimations(asset_manager);
        auto &animations = asset_manager.animations;
        new_actor->Animator.Animations = &animations.at(new_actor->GetClassCode());

        actors.push_back(std::move(new_actor));
    }

    void Render(float);
};