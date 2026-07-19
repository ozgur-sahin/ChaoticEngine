#pragma once

#include <graphics/texture/Texture.h>

class ChSprite
{
    ChTexture *spritesheet;
    SDL_FRect *srcRect;
    int *sheetwidth;
    int *sheetheight;

public:
    ChSprite(ChRenderer *, std::string, const SDL_FRect &);
    ChSprite(ChTexture *, const SDL_FRect &);
    ~ChSprite();
    ChTexture *GetSpriteSheet();
    SDL_FRect *GetSrcRect();
};