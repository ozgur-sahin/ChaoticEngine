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

    void AddTexture(std::string, std::string);
    ChTexture *FindTexture(std::string);

    void AddAnimation(std::string, std::string, ChAnimation);
    ChAnimation *FindAnimation(std::string, std::string);

    void LoadAnimationsFromFile(std::string){};
};