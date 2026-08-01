#include <core/actors/actor.h>

class PlayerCharacter : public ChActor
{

public:
    PlayerCharacter(double, double, double, double);

    virtual void Tick(float, ChRenderer *) override;
};