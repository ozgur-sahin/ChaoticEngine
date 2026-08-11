#include "scene.h"

ChScene::ChScene(ChRenderer &renderer_ref, ChAssetManager &asset_mngr) : renderer{renderer_ref},
                                                                         asset_manager{asset_mngr}
{
}

void ChScene::TickActors(float DeltaTime)
{
    for (auto &actor : actors)
    {
        // Logger::Info("Actor " + actor->GetActorAddressAsString() + " about to tick.");
        actor->Tick(DeltaTime, renderer);
    }
}

void ChScene::Render(float DeltaTime)
{
    TickActors(DeltaTime);
    // Logger::Info("Ticked all actors");
}