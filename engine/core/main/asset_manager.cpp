#include "asset_manager.h"

void ChAssetManager::AddTexture(std::string texture_code, std::string filename)
{
    textures.try_emplace(texture_code, renderer, filename);
}

ChTexture *ChAssetManager::FindTexture(std::string texture_code)
{
    ChTexture *return_texture{&textures.at(texture_code)};
    return return_texture;
}

void ChAssetManager::AddAnimation(std::string class_code, std::string animation_code, ChAnimation animation)
{
    animations.try_emplace(class_code);
    auto &class_animations = animations.at(class_code);
    class_animations.try_emplace(animation_code, ChAnimation{animation});
}

ChAnimation *ChAssetManager::FindAnimation(std::string class_code, std::string animation_code)
{
    return &animations.at(class_code).at(animation_code);
}