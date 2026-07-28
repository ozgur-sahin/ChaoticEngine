#pragma once

#include <graphics/texture/Texture.h>
#include <graphics/animation/animation.h>
#include <unordered_map>

class ChActorAnimator
{

    std::unordered_map<std::string, ChAnimation *> Animations{};

    ChAnimation *currentAnimation;

public:
    ChActorAnimator() {};
    void addAnimation(std::string, ChAnimation *);
    void Play(std::string);
};