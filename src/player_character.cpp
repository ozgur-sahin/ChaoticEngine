#include "player_character.h"

PlayerCharacter::PlayerCharacter(double x, double y, double xsize, double ysize) : ChActor(x, y, xsize, ysize) {}

void PlayerCharacter::Tick(float DeltaTime, ChRenderer *renderer)
{
    ChActor::Tick(DeltaTime, renderer);
}