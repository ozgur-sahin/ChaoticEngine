#include <core/main/engine.h>

int main()
{
    const int WindowHeight = 800;
    const int WindowWidth = 600;

    ChEngine engine{WindowHeight, WindowWidth};

    engine.run();

    return 0;
}