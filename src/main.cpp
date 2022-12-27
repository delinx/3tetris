#include "blockRender.hpp"
#include "gameLoop.hpp"
#include "raylib.h"
#include "types/types.hpp"

#ifdef UNIT_TEST
#include "uTest.cpp"
#else

#include <iostream>

int main(int argc, char *argv[])
{

    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(120);

    f96 time = 0.0f;

    GameLoop gameLoop;

    while(!WindowShouldClose())
    {
        time += GetFrameTime();
        gameLoop.time = time;
        gameLoop.deltaTime = GetFrameTime();


        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        DrawText("3Tetris", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    std::cout << "Template" << std::endl;
    return 0;
}

#endif
