#pragma once

#include <graphics/texture/Texture.h>
#include <graphics/animation/animation.h>
#include <unordered_map>
#include <sstream>

class ChRenderer;

class ChActorAnimator
{
public:
    std::unordered_map<std::string, ChAnimation> *Animations;

    ChAnimation *currentAnimation{nullptr};

    double AnimationRunTime{0};

    ChActorAnimator() {};
    // void addAnimation(std::string, ChAnimation);
    void Play(ChAnimation *);
    void Stop();
    void RenderIdle(SDL_FRect, ChRenderer &);
    void AnimationUpdate(float, SDL_FRect, ChRenderer &);
    SDL_FRect FindCurrentAnimationFrame();
};