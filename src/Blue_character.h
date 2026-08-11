#pragma once

#include <core/actors/actor.h>

class Blue_character : public ChActor
{
    std::string class_code{"BLUE"};
    std::string animation_file{"blue.anim"};

public:
    Blue_character();

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