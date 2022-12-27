#include "blockRender.hpp"
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

    BlockRender *bucketBlockRender = new BlockRender();

    f96 time = 0.0f;



    while(!WindowShouldClose())
    {
        time += GetFrameTime();
        bucketBlockRender->time = time;
        bucketBlockRender->deltaTime = GetFrameTime();


        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    std::cout << "Template" << std::endl;
    return 0;
}

#endif
