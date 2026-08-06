#pragma once

#include <core/actors/actor.h>

class Blue_character : public ChActor
{
    std::string class_code{"BLUE"};

public:
    Blue_character();

    virtual void Tick(float, ChRenderer &) override;
    virtual void ConfigureAnimations(ChTexture *, ChScene *) override;
    virtual const std::string GetClassCode() const override
    {
        return class_code;
    }
};