#include "player_character.h"
#include <core/main/scene.h>

PlayerCharacter::PlayerCharacter()
{
}

void PlayerCharacter::Tick(float DeltaTime, ChRenderer &renderer)
{
    ChActor::Tick(DeltaTime, renderer);
    Logger::Info("Red actor ticked.");
}

void PlayerCharacter::ConfigureAnimations(ChTexture *spritesheet, ChAssetManager &asset_manager)
{
    SDL_FRect Walk1Rect{0, 0, 92.0 / 3.0, 128.0 / 4.0};
    SDL_FRect Walk2Rect{2.0 * 92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};
    SDL_FRect IdleRect{92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};

    std::vector<std::tuple<SDL_FRect, double>> idleframe{{IdleRect, 0}};
    std::vector<std::tuple<SDL_FRect, double>> walkingframes{{IdleRect, 500}, {Walk1Rect, 250}, {IdleRect, 500}, {Walk2Rect, 250}};
    ChAnimation WalkingAnimation{spritesheet, walkingframes, true};
    ChAnimation IdleAnimation(spritesheet, idleframe);
    asset_manager.AddAnimation(class_code, "Walk", WalkingAnimation);
    asset_manager.AddAnimation(class_code, "Idle", IdleAnimation);
    Animator.Animations = &asset_manager.animations.at(class_code);
    Animator.Play("Walk");

    Logger::Info("Player character animations configured");
}