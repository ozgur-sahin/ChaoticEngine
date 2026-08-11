#pragma once

#include <core/actors/actor.h>

class PlayerCharacter : public ChActor
{
    std::string class_code{"PLAYER"};
    std::string animation_file{"player.anim"};

public:
    PlayerCharacter();

    virtual void Tick(float, ChRenderer &) override;
    virtual void ConfigureAnimations(ChAssetManager &) override;
    virtual const std::string GetClassCode() const override
    {
        return class_code;
    }
    virtual const std::string GetAnimationFile() const override
    {
        return animation_file;
    }
};