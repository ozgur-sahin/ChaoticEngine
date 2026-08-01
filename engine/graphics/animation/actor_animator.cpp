#include <graphics/animation/actor_animator.h>
#include <graphics/renderer/renderer.h>

void ChActorAnimator::addAnimation(std::string AnimationName, ChAnimation *Animation)
{
    Animations.insert({AnimationName, Animation});
}

void ChActorAnimator::Play(std::string AnimationName)
{
    currentAnimation = Animations.at(AnimationName);
    AnimationRunTime = 0;
}

void ChActorAnimator::Stop()
{
    currentAnimation = nullptr;
}

void ChActorAnimator::RenderIdle(SDL_FRect destRect, ChRenderer *renderer)
{
    SDL_FRect srcRect{std::get<SDL_FRect>(Animations.at("Idle")->frames[0])};

    renderer->DrawRectTexture(Animations.at("Idle")->spritesheet, &destRect, &srcRect);
}

void ChActorAnimator::AnimationUpdate(float DeltaTime, SDL_FRect destrect, ChRenderer *renderer)
{
    if (!currentAnimation)
    {
        RenderIdle(destrect, renderer);
        return;
    }

    AnimationRunTime += DeltaTime;
    while (AnimationRunTime > currentAnimation->frameTimeTable.back())
    {
        AnimationRunTime -= currentAnimation->frameTimeTable.back();
    }
    if (AnimationRunTime < 0)
    {
        Logger::Error("Logic error in animation update! AnimationRunTime is negative!");
    }

    SDL_FRect srcrect = FindCurrentAnimationFrame();

    renderer->DrawRectTexture(currentAnimation->spritesheet,
                              &destrect, &srcrect);
}

SDL_FRect ChActorAnimator::FindCurrentAnimationFrame()
{
    auto frames = currentAnimation->frames;
    auto frametimetable = currentAnimation->frameTimeTable;

    Logger::Info("Animation runtime: " + std::to_string(AnimationRunTime) + "\n");

    for (size_t i = 0; i < frames.size(); i++)
    {
        if (AnimationRunTime <= frametimetable.at(i))
        {
            // Logger::Info("Frame " + std::to_string(i) + " being used.\n");
            return std::get<SDL_FRect>(frames.at(i));
        }
    }
    Logger::Warning("Check logic, the frame finder got out of the loop without finding the correct frame.");
    return std::get<SDL_FRect>(frames.back());
}