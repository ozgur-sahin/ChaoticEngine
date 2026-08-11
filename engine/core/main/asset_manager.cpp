#include "asset_manager.h"

void ChAssetManager::AddTexture(const std::string class_code, const std::string filename)
{
    textures.try_emplace(class_code, renderer, filename);
}

ChTexture *ChAssetManager::FindTexture(const std::string class_code)
{
    ChTexture *return_texture{&textures.at(class_code)};
    return return_texture;
}

void ChAssetManager::AddAnimation(const std::string class_code, const std::string animation_code, const ChAnimation animation)
{
    animations.try_emplace(class_code);
    auto &class_animations = animations.at(class_code);
    class_animations.try_emplace(animation_code, ChAnimation{animation});
}

ChAnimation *ChAssetManager::FindAnimation(const std::string class_code, const std::string animation_code)
{
    return &animations.at(class_code).at(animation_code);
}