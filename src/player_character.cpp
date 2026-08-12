#include "player_character.h"

#include <core/main/asset_manager.h>

PlayerCharacter::PlayerCharacter()
{
}

void PlayerCharacter::Tick(float DeltaTime, ChRenderer *renderer)
{
    ChActor::Tick(DeltaTime, renderer);
    // Logger::Info("Red actor ticked.");
}

void PlayerCharacter::ConfigureAnimations(ChAssetManager *asset_manager)
{
    Animator.Animations = &asset_manager->animations.at(class_code);
    Animator.Play("Walk");

    // Logger::Info("Player character animations configured");
}