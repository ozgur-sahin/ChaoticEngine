#include <core/main/engine.h>

int main()
{
    const int WindowHeight = 800;
    const int WindowWidth = 600;

    ChEngine engine{WindowHeight, WindowWidth, 120};

    engine.run();

    return 0;
}