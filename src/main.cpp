#include "entityManager.hpp"
#include "raylib.h"
#include "types.hpp"

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

    EntityManager *entityManager = new EntityManager();

    f96 time = 0.0f;

    Block block = Block(iXY(1, 1), fXY(0.0f, 0.0f));
    block.positionVisualTarget = fXY(100.0f, 100.0f);
    entityManager->addBlock(block);


    while(!WindowShouldClose())
    {
        time += GetFrameTime();
        entityManager->time = time;
        entityManager->deltaTime = GetFrameTime();

        // test logic
        entityManager->stepAllBlocks();
        entityManager->removeExpiredBlocks();
        //


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
