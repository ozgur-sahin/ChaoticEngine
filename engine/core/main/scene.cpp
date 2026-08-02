#include "scene.h"

ChScene::ChScene(ChRenderer *renderer_ptr) : renderer{renderer_ptr}
{
}

void ChScene::TickActors(float DeltaTime)
{
    for (auto &actor : actors)
    {
        actor->Tick(DeltaTime, renderer);
    }
}

void ChScene::AddTexture(std::string texture_code, std::string filename)
{
    std::unique_ptr<ChTexture> new_texture{new ChTexture{renderer, filename}};
    textures.try_emplace(texture_code, std::move(new_texture));
}

ChTexture *ChScene::FindTexture(std::string texture_code)
{
    ChTexture *return_texture{textures.at(texture_code).get()};

    if (return_texture)
    {
        Logger::Info("Texture for " + texture_code + " found!");
    }
    else
    {
        Logger::Info("Eep no texture");
    }
    return return_texture;
}

void ChScene::Render(float DeltaTime)
{

    Logger::Info("Cleared frame");

    TickActors(DeltaTime);
    Logger::Info("Ticked all actors");

       Logger::Info("Finished rendering");
}