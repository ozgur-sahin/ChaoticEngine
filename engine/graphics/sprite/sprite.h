#pragma once

#include <graphics/texture/Texture.h>

class ChSprite
{
    ChTexture *spritesheet{nullptr};
    SDL_FRect srcRect{0, 0, 0, 0};
    int sheetwidth{0};
    int sheetheight{0};

public:
    // ChSprite(ChRenderer *, std::string, const SDL_FRect);
    ChSprite(ChTexture *, const SDL_FRect);
    ~ChSprite();
    ChTexture *GetSpriteSheet() const;
    const SDL_FRect GetSrcRect() const;
};