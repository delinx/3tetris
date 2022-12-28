#include "gameLoop.hpp"

GameLoop::GameLoop()
{
    bucketRender = new BlockRender();
    shapeRender = new BlockRender();
    bucket = new Bucket();
    activeShape = new ActiveShape();
}

GameLoop::~GameLoop()
{
    delete bucketRender;
    delete shapeRender;
}


void GameLoop::readInput()
{
    moveRight = IsKeyDown(KEY_RIGHT) ? true : false;
    moveLeft = IsKeyDown(KEY_LEFT) ? true : false;
    moveDown = IsKeyDown(KEY_SPACE) ? true : false;
    rotateRight = IsKeyDown(KEY_UP) ? true : false;
    rotateLeft = IsKeyDown(KEY_DOWN) ? true : false;
}

void GameLoop::resetInput()
{
    rotateRight = false;
    rotateLeft = false;
    moveLeft = false;
    moveRight = false;
    moveDown = false;
}

void GameLoop::tickLogic()
{
    f96 interval = moveDown ? tickIntervalFast : tickInterval;
    if(time - lastTick > interval)
    {
        std::cout << "tick" << std::endl;
        lastTick = time;
        resetInput();
    }
}

void GameLoop::drawControls()
{

    DrawText("Right", 10, 30, 20, BLACK);
    if(moveRight)
    {
        DrawCircle(80, 40, 5, RED);
    }
    DrawText("Left", 10, 50, 20, BLACK);
    if(moveLeft)
    {
        DrawCircle(80, 60, 5, RED);
    }
    DrawText("Space", 10, 70, 20, BLACK);
    if(moveDown)
    {
        DrawCircle(80, 80, 5, RED);
    }
    DrawText("Up", 10, 90, 20, BLACK);
    if(rotateRight)
    {
        DrawCircle(80, 100, 5, RED);
    }
    DrawText("Down", 10, 110, 20, BLACK);
    if(rotateLeft)
    {
        DrawCircle(80, 120, 5, RED);
    }
}
