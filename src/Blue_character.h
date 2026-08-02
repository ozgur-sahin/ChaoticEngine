#pragma once

#include <core/actors/actor.h>

class Blue_character : public ChActor
{
    std::string texture_code{"BLUE"};

public:
    Blue_character();

    virtual void Tick(float, ChRenderer *) override;
    virtual void ConfigureAnimations(ChTexture *) override;
    virtual std::string GetTextureCode() override
    {
        return texture_code;
    }
};