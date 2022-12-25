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

    while(!WindowShouldClose())
    {
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
