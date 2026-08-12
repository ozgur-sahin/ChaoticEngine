// SDL libraries
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_events.h>

#include <core/main/engine.h>
#include <core/main/scene.h>

ChEngine::ChEngine(const int WindowHeight, const int WindowWidth, const int FPS)
    : window{WindowHeight, WindowWidth},
      renderer{&window},
      asset_manager{renderer},
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
    bool running = true;

    while (running)
    {
        // Logger::Info("Event loop started");
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
                    // scene.AddActor<PlayerCharacter>(200, 200);
                    break;
                case SDLK_W:
                    // scene.AddActor<Blue_character>(200, 100);
                    break;
                default:
                    Logger::Info("Couldn't find which key was pressed.");
                }
                break;
            }
        }
        renderer.FrameClear();

        scene->Render(clock.GetDeltaTime());

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

void ChEngine::LoadScene(std::unique_ptr<ChScene> scene_ptr)
{
    scene = std::move(scene_ptr);
    scene->Initialize(renderer, asset_manager);
    scene->BeginPlay();
}