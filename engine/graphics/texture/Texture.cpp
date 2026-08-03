#include <graphics/texture/Texture.h>
#include <graphics/renderer/renderer.h>

ChTexture::ChTexture(SDL_Renderer *renderer, int w, int h)
{
    sdl_texture = SDL_CreateTexture(renderer,
                                    SDL_PIXELFORMAT_UNKNOWN,
                                    SDL_TEXTUREACCESS_STATIC,
                                    w,
                                    h);
}

ChTexture::ChTexture(ChRenderer *renderer, std::string filename)
{
    SDL_Surface *sdl_surface = IMG_Load(filename.data());
    if (!sdl_surface)
    {
        Logger::Error("Unable to open the file: " + filename + "!");
        throw std::runtime_error("Unable to open the file: " + filename + "!");
    }
    sdl_texture = SDL_CreateTextureFromSurface(renderer->GetSDL_Renderer(), sdl_surface);
    SDL_DestroySurface(sdl_surface);

    w = sdl_texture->w;
    h = sdl_texture->h;
}

ChTexture::~ChTexture()
{
    SDL_DestroyTexture(sdl_texture);
}

SDL_Texture *ChTexture::GetSDL_Texture() const
{
    return sdl_texture;
}