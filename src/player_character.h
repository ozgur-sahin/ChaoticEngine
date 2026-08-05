#pragma once

#include <core/actors/actor.h>

class PlayerCharacter : public ChActor
{
    std::string texture_code{"PLAYER"};

public:
    PlayerCharacter();

    virtual void Tick(float, ChRenderer &) override;
    virtual void ConfigureAnimations(ChTexture *) override;
    virtual std::string GetTextureCode() override
    {
        return texture_code;
    }
};