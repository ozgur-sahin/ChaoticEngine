#include "scene.h"

ChScene::ChScene(ChRenderer &renderer_ref) : renderer{renderer_ref}
{
}

void ChScene::TickActors(float DeltaTime)
{
    for (auto &actor : actors)
    {
        Logger::Info("Actor " + actor->GetActorAddressAsString() + " about to tick.");
        actor->Tick(DeltaTime, renderer);
    }
}

void ChScene::Render(float DeltaTime)
{
    TickActors(DeltaTime);
    Logger::Info("Ticked all actors");
}

void ChScene::AddTexture(std::string texture_code, std::string filename)
{
    textures.try_emplace(texture_code, ChTexture{renderer, filename});
}

ChTexture *ChScene::FindTexture(std::string texture_code)
{
    ChTexture *return_texture{&textures.at(texture_code)};

    if (return_texture)
    {
        Logger::Info("Texture for " + texture_code + " found!");
    }
    else
    {
        Logger::Info("No texture found.");
    }
    return return_texture;
}

void ChScene::AddAnimation(std::string class_code, std::string animation_code, ChAnimation animation)
{
    animations.try_emplace(class_code);
    auto &class_animations = animations.at(class_code);
    class_animations.try_emplace(animation_code, ChAnimation{animation});
}

ChAnimation *ChScene::FindAnimation(std::string class_code, std::string animation_code)
{
    return &animations.at(class_code).at(animation_code);
}