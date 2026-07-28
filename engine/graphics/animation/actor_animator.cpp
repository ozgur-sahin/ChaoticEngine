#include <graphics/animation/actor_animator.h>

void ChActorAnimator::addAnimation(std::string AnimationName, ChAnimation *Animation)
{
    Animations.insert({AnimationName, Animation});
}

void ChActorAnimator::Play(std::string AnimationName)
{
    currentAnimation = Animations.at(AnimationName);
}