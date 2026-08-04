#include <core/main/engine.h>

ChEngine::ChEngine(const int WindowHeight, const int WindowWidth, const int FPS)
    : window{WindowHeight, WindowWidth},
      renderer{&window},
      scene{&renderer},
      clock{},
      targetFPS{FPS},
      targetFrametime{1000.0 / targetFPS}
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        Logger::Error("SDL initialization failed");
        throw std::runtime_error("SDL initialization failed. Aborting...\n");
    }

    Logger::Info("Engine initialized...");
}

ChEngine::~ChEngine()
{
    SDL_Quit();
}

void ChEngine::run()
{
    scene.AddTexture("PLAYER", "assets/textures/RedPlayerSpriteSheet.png");
    scene.AddTexture("BLUE", "assets/textures/BlueRivalSpriteSheet.png");

    scene.AddActor<PlayerCharacter>(300, 400);
    scene.AddActor<Blue_character>(200, 300);
    Logger::Info("Successfully added player character!");
    bool running = true;

    while (running)
    {
        Logger::Info("Event loop started");
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                running = false;
                break;

            case SDL_EVENT_KEY_DOWN:
                Logger::Info("A key was pressed down");
                switch (event.key.key)
                {
                case SDLK_S:
                    scene.AddActor<PlayerCharacter>(200, 200);
                    break;
                case SDLK_W:
                    scene.AddActor<Blue_character>(200, 100);
                    break;
                default:
                    Logger::Info("Couldn't find which key was pressed.");
                }
                break;
            }
        }
        renderer.FrameClear();

        scene.Render(clock.GetDeltaTime());

        ShowFPSCounter();

        renderer.RenderFrame();

        clock.Update();
        clock.EnforceFrameLimit(targetFrametime);

        // Logger::Info("Frametime = " + std::to_string(clock.GetDeltaTime()) + "ms");
        // Logger::Info("FPS: " + std::to_string(1000.0 / clock.GetDeltaTime()));
    }
}

void ChEngine::ShowFPSCounter()
{
    double FPS = 1000.0 / clock.GetDeltaTime();
    renderer.RenderDebugText(std::format("{:.2f} FPS", FPS));
}