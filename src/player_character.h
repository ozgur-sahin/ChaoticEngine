#pragma once

#include <core/actors/actor.h>

class PlayerCharacter : public ChActor
{
    std::string class_code{"PLAYER"};

public:
    PlayerCharacter();

    virtual void Tick(float, ChRenderer &) override;
    virtual void ConfigureAnimations(ChTexture *, ChScene *) override;
    virtual const std::string GetClassCode() const override
    {
        return class_code;
    }
};