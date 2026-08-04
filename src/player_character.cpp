#include "player_character.h"

PlayerCharacter::PlayerCharacter()
{
}

void PlayerCharacter::Tick(float DeltaTime, ChRenderer *renderer)
{
    ChActor::Tick(DeltaTime, renderer);
    Logger::Info("Red actor ticked.");
}

void PlayerCharacter::ConfigureAnimations(ChTexture *spritesheet)
{
    SDL_FRect Walk1Rect{0, 0, 92.0 / 3.0, 128.0 / 4.0};
    SDL_FRect Walk2Rect{2.0 * 92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};
    SDL_FRect IdleRect{92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};

    std::vector<std::tuple<SDL_FRect, double>> idleframe{{IdleRect, 0}};
    std::vector<std::tuple<SDL_FRect, double>> walkingframes{{IdleRect, 500}, {Walk1Rect, 250}, {IdleRect, 500}, {Walk2Rect, 250}};
    ChAnimation WalkingAnimation{spritesheet, walkingframes, true};
    ChAnimation IdleAnimation(spritesheet, idleframe);
    Animator.addAnimation("Walk", WalkingAnimation);
    Animator.addAnimation("Idle", IdleAnimation);
    Animator.Play("Walk");

    Logger::Info("Player character animations configured");
}