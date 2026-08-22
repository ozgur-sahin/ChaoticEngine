#include "scene.h"

ChScene::ChScene()
{
}

void ChScene::Initialize(ChRenderer &rend, ChAssetManager &asstmngr)
{
    renderer = &rend;
    asset_manager = &asstmngr;
}

void ChScene::TickActors(float DeltaTime)
{
    for (auto &actor : actors)
    {
        // CH_LOG_INFO("Actor " + actor->GetActorAddressAsString() + " about to tick.");
        actor->Tick(DeltaTime, renderer);
    }
}

void ChScene::Render(float DeltaTime)
{
    TickActors(DeltaTime);
    // CH_LOG_INFO("Ticked all actors");
}