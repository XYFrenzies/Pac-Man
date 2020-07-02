#include <iostream>
#include "StartupApp.h"
int main(int argc, char* argv[])
{
    {
        StartupApp game;
        game.StartUp();
        game.Run();
        game.ShutDown();
    }
    return 0;
}
