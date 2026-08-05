#include "Blue_character.h"

Blue_character::Blue_character()
{
}

void Blue_character::Tick(float DeltaTime, ChRenderer &renderer)
{
    ChActor::Tick(DeltaTime, renderer);
    Logger::Info("Blue actor ticked.");
}

void Blue_character::ConfigureAnimations(ChTexture *spritesheet)
{
    SDL_FRect IdleRect{92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};

    std::vector<std::tuple<SDL_FRect, double>> idleframe{{IdleRect, 0}};

    ChAnimation IdleAnimation(spritesheet, idleframe);
    Animator.addAnimation("Idle", IdleAnimation);
}