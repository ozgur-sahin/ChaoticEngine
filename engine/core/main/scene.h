#pragma once

#include <core/actors/actor.h>
#include <graphics/renderer/renderer.h>
#include <core/window/window.h>
#include <vector>
#include <memory>

// delete these includes later
#include "../src/player_character.h"

class ChScene
{

    std::vector<std::unique_ptr<ChActor>> actors{};
    ChRenderer *renderer;

    std::unordered_map<std::string, std::unique_ptr<ChTexture>> textures{};

public:
    ChScene(ChRenderer *);

    virtual void TickActors(float);

    template <std::derived_from<ChActor> T>
    void AddActor(double xpos, double ypos)
    {
        std::unique_ptr<ChActor> new_actor{new T{}};
        new_actor->ActorTransform.SetPosition(xpos, ypos);
        Logger::Info("New actor with texture code: " + new_actor->GetTextureCode() + "\n");
        new_actor->ConfigureAnimations(FindTexture(new_actor->GetTextureCode()));

        actors.push_back(std::move(new_actor));
    }

    void AddTexture(std::string, std::string);
    ChTexture *FindTexture(std::string);

    void Render(float);
};