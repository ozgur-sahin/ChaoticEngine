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
    ChTexture RedSpriteSheet(&renderer, "assets/textures/RedPlayerSpriteSheet.png");

    ChActor RedPlayer{0, 0};

    // RedPlayer.Animator.addAnimation()

    SDL_FRect Walk1Rect{0, 0, 92.0 / 3.0, 128.0 / 4.0};
    // ChSprite WalkingPlayerSprite(&RedSpriteSheet, Walk1Rect);

    SDL_FRect Walk2Rect{2.0 * 92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};
    // ChSprite WalkingPlayerSprite2(&RedSpriteSheet, Walk2Rect);

    SDL_FRect IdleRect{92.0 / 3.0, 0, 92.0 / 3.0, 128.0 / 4.0};
    // ChSprite IdlePlayerSprite(&RedSpriteSheet, IdleRect);

    std::vector<std::tuple<SDL_FRect, double>> frames{{IdleRect, 100}, {Walk1Rect, 100}, {IdleRect, 100}, {Walk2Rect, 100}};
    ChAnimation WalkingAnimation{&RedSpriteSheet, frames, true};
    RedPlayer.Animator.addAnimation("Walk", &WalkingAnimation);
    RedPlayer.Animator.Play("Walk");

    bool running = true;

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
        clock.Update();
        clock.EnforceFrameLimit(targetFrametime);
        ShowFPSCounter();

        renderer.RenderFrame();


        // Logger::Info("Frametime = " + std::to_string(clock.GetDeltaTime()) + "ms");
        // Logger::Info("FPS: " + std::to_string(1000.0 / clock.GetDeltaTime()));
    }
}

void ChEngine::ShowFPSCounter()
{
    double FPS = 1000.0 / clock.GetDeltaTime();
    renderer.RenderDebugText(std::format("{:.2f} FPS", FPS));
}