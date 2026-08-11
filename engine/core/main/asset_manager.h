#pragma once

#include <string>
#include <unordered_map>

#include <graphics/texture/Texture.h>
#include <graphics/animation/animation.h>

class ChAssetManager
{
    using TextureDictionary = std::unordered_map<std::string, ChTexture>;
    using AnimationDictionary = std::unordered_map<std::string, std::unordered_map<std::string, ChAnimation>>;

private:
    ChRenderer &renderer;

public:
    ChAssetManager(ChRenderer &rend) : renderer{rend} {};
    TextureDictionary textures{};
    AnimationDictionary animations{};

    void AddTexture(const std::string, const std::string);
    ChTexture *FindTexture(const std::string);

    void AddAnimation(const std::string, const std::string, const ChAnimation);
    ChAnimation *FindAnimation(const std::string, const std::string);

    void LoadAnimationsFromFile(std::string){};
};