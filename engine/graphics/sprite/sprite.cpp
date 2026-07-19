#include "sprite.h"
#include "core/logger/logger.h"
#include <cstring>

ChSprite::ChSprite(ChRenderer *renderer, const std::string filename, const SDL_FRect &SourceRectangle)
{
    spritesheet = new ChTexture{renderer, filename};

    sheetheight = &spritesheet->GetSDL_Texture()->h;
    sheetwidth = &spritesheet->GetSDL_Texture()->w;

    Logger::Info("Width of sprite: " + std::to_string(*sheetwidth));
    Logger::Info("Height of sprite: " + std::to_string(*sheetheight));

    srcRect = new SDL_FRect{SourceRectangle};
}

ChSprite::ChSprite(ChTexture *sheet, const SDL_FRect &SourceRectangle)
{
    spritesheet = new ChTexture(*sheet);

    if (!spritesheet)
    {
        throw std::runtime_error("Invalid texture detected! Aborting...");
    }

    sheetheight = &spritesheet->GetSDL_Texture()->h;
    sheetwidth = &spritesheet->GetSDL_Texture()->w;

    Logger::Info("Width of sprite: " + std::to_string(*sheetwidth));
    Logger::Info("Height of sprite: " + std::to_string(*sheetheight));

    srcRect = new SDL_FRect{SourceRectangle};
}

ChSprite::~ChSprite()
{
    delete spritesheet;
    delete srcRect;
}

ChTexture *ChSprite::GetSpriteSheet()
{
    return spritesheet;
}

SDL_FRect *ChSprite::GetSrcRect()
{
    return srcRect;
}