#include <core/main/engine.h>

ChEngine::ChEngine(const int WindowHeight, const int WindowWidth, const int FPS)
    : window(WindowHeight, WindowWidth),
      renderer(&window),
      clock()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        Logger::Error("SDL initialization failed");
        throw std::runtime_error("SDL initialization failed. Aborting...\n");
    }

    Logger::Info("Engine initialized...");
    targetFPS = FPS;
    targetFrametime = 1000.0 / targetFPS; // defined in milliseconds
}

ChEngine::~ChEngine()
{
    SDL_Quit();
}

void ChEngine::run()
{
    SDL_FRect Walk1Rect{0, 0, 92.0 / 3.0, 128.0 / 4.0};
    ChSprite WalkingPlayerSprite(&renderer, "assets/textures/RedPlayerSpriteSheet.png", Walk1Rect);

    SDL_FRect Walk2Rect{2.0 * 92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};
    ChSprite WalkingPlayerSprite2(&renderer, "assets/textures/RedPlayerSpriteSheet.png", Walk2Rect);

    SDL_FRect IdleRect{92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};
    ChSprite IdlePlayerSprite(&renderer, "assets/textures/RedPlayerSpriteSheet.png", IdleRect);

    bool running = true;

    SDL_FRect destrect{400 - 75, 300 - 75, 150, 150};

    int framecount = 0;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
                // Logger::Info("Window no longer running...");
            }
        }
        renderer.FrameClear();
        // renderer->DrawRectangle(100, 100, 50, 50, 255, 0, 0, 255);
        // renderer->DrawTriangle();
        // renderer->DrawCircle(100);

        switch ((framecount / 100) % 4)
        {
        case (0):
            renderer.DrawRectTexture(&IdlePlayerSprite, &destrect);
            break;

        case (1):
            renderer.DrawRectTexture(&WalkingPlayerSprite, &destrect);
            break;

        case (2):
            renderer.DrawRectTexture(&IdlePlayerSprite, &destrect);
            break;

        case (3):
            renderer.DrawRectTexture(&WalkingPlayerSprite2, &destrect);
            break;
        }
        clock.Update();
        clock.EnforceFrameLimit(targetFrametime);
        ShowFPSCounter();

        renderer.RenderFrame();

        Logger::Info("Frametime = " + std::to_string(clock.GetDeltaTime()) + "ms");
        Logger::Info("FPS: " + std::to_string(1000.0 / clock.GetDeltaTime()));

        framecount++;
    }
}

void ChEngine::ShowFPSCounter()
{
    double FPS = 1000.0 / clock.GetDeltaTime();
    renderer.RenderDebugText(std::format("{:.2f} FPS", FPS));
}