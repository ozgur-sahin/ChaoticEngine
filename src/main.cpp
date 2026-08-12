#include <core/main/engine.h>
#include <memory>
#include "MyScene.h"

int main()
{
    const int WindowHeight = 800;
    const int WindowWidth = 600;

    ChEngine engine{WindowHeight, WindowWidth, 120};

    engine.GetAssetManager()->AddTexture("PLAYER", "../src/assets/textures/RedPlayerSpriteSheet.png");
    engine.GetAssetManager()->AddTexture("BLUE", "../src/assets/textures/BlueRivalSpriteSheet.png");
    engine.GetAssetManager()->LoadAnimationsFromFile("../src/assets/animations/player.anim");

    std::unique_ptr<ChScene> new_scene = std::make_unique<MyScene>();
    engine.LoadScene(std::move(new_scene));

    engine.run();

    return 0;
}