#include "sprite.h"
#include "core/logger/logger.h"
#include <cstring>

// ChSprite::ChSprite(ChRenderer *renderer, const std::string filename, SDL_FRect SourceRectangle)
// {
//     spritesheet = new ChTexture{renderer, filename};

//     sheetheight = spritesheet->GetSDL_Texture()->h;
//     sheetwidth = spritesheet->GetSDL_Texture()->w;

//     Logger::Info("Width of sprite: " + std::to_string(sheetwidth));
//     Logger::Info("Height of sprite: " + std::to_string(sheetheight));

//     srcRect = SourceRectangle;
// }

ChSprite::ChSprite(ChTexture *sheet, SDL_FRect SourceRectangle) : spritesheet(sheet)
{
    // spritesheet = sheet;

    if (!spritesheet)
    {
        throw std::runtime_error("Invalid texture detected! Aborting...");
    }

    sheetheight = spritesheet->GetSDL_Texture()->h;
    sheetwidth = spritesheet->GetSDL_Texture()->w;

    Logger::Info("Width of sprite: " + std::to_string(sheetwidth));
    Logger::Info("Height of sprite: " + std::to_string(sheetheight));

    srcRect = SourceRectangle;
}

ChSprite::~ChSprite()
{
}

ChTexture *ChSprite::GetSpriteSheet() const
{
    return spritesheet;
}

const SDL_FRect ChSprite::GetSrcRect() const
{
    return srcRect;
}