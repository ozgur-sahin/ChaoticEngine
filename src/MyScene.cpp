#include "MyScene.h"

#include "Blue_character.h"
#include "player_character.h"

void MyScene::BeginPlay()
{
    AddActor<PlayerCharacter>(300, 400);
    // AddActor<Blue_character>(200, 300);
}