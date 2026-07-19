#include <core/main/engine.h>

ChEngine::ChEngine()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        Logger::Error("SDL initialization failed");
        throw std::runtime_error("SDL initialization failed. Aborting...\n");
    }

    const int WindowHeight = 800;
    const int WindowWidth = 600;

    window = new ChWindow(WindowHeight, WindowWidth);
    renderer = new ChRenderer(window);

    Logger::Info("Engine initialized...");
}

ChEngine::~ChEngine()
{
    delete window;
    delete renderer;
    SDL_Quit();
}

void ChEngine::run()
{
    ChTexture Player(renderer, "assets/textures/RedPlayerSpriteSheet.png");

    bool running = true;

    SDL_FRect rect{200, 200, 150, 200};

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
                Logger::Info("Window no longer running...");
            }
        }
        renderer->FrameClear();
        renderer->DrawRectangle(100, 100, 50, 50, 255, 0, 0, 255);
        renderer->DrawTriangle();
        renderer->DrawCircle(100);
        renderer->DrawRectTexture(&Player, &rect);

        renderer->RenderFrame();
    }
}