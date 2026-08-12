#include "asset_manager.h"

#include <graphics/texture/Texture.h>
#include <graphics/animation/animation.h>

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

void ChAssetManager::LoadAnimationsFromFile(const std::string filename)
{
    std::ifstream file_stream{filename};
    json animation_list;
    file_stream >> animation_list;

    for (const auto &animation : animation_list)
    {
        std::vector<ChAnimation::frametype> animation_frames{};

        std::string class_code = animation.at("class_code").get<std::string>();
        std::string animation_code = animation.at("animation_name").get<std::string>();
        ChTexture *spritesheet = FindTexture(class_code);

        for (const auto &frame : animation.at("frames"))
        {
            const auto &rect = frame["frame_rect"];

            float x = rect[0].get<float>();
            float y = rect[1].get<float>();
            float w = rect[2].get<float>();
            float h = rect[3].get<float>();

            SDL_FRect src_rect{x, y, w, h};
            double frametime = frame.at("frame_time").get<double>();
            animation_frames.push_back(std::make_tuple(src_rect, frametime));
        }

        AddAnimation(class_code, animation_code, ChAnimation{spritesheet, animation_frames});
    }
    // std::cout << animation_list[0].at("animation_name").dump(4) << std::endl;
}