#include "Blue_character.h"
#include <core/main/asset_manager.h>

Blue_character::Blue_character()
{
}

void Blue_character::Tick(float DeltaTime, ChRenderer *renderer)
{
    ChActor::Tick(DeltaTime, renderer);
    // CH_LOG_INFO("Blue actor ticked.");
}

void Blue_character::ConfigureAnimations(ChAssetManager *asset_manager)
{
    Animator.Animations = &asset_manager->animations.at(class_code);
}