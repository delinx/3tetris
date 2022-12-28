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

    bool DEBUG = true;

    gameLoop.shapeRender->addBlocksFromGrid(gameLoop.activeShape->grid);

    while(!WindowShouldClose())
    {
        time += GetFrameTime();
        gameLoop.time = time;
        gameLoop.deltaTime = GetFrameTime();
        gameLoop.updateTime();

        BeginDrawing();
        ClearBackground(GRAY);
        DrawFPS(10, 10);
        DrawText("3Tetris", 190, 200, 20, LIGHTGRAY);

        gameLoop.readInput();
        gameLoop.tickLogic();
        gameLoop.shapeRender->stepAllBucketBlocks();
        gameLoop.shapeRender->drawAllBucketBlocksDebug();


        // gameLoop.activeShape->grid->print();
        // gameLoop.bucket->grid->print();

        if(DEBUG)
        {
            gameLoop.drawControls();
        }
        EndDrawing();

        // debug toggle
        if(IsKeyReleased(KEY_TAB))
        {
            DEBUG = !DEBUG;
        }
    }

    CloseWindow();
    std::cout << "Template" << std::endl;
    return 0;
}

#endif
