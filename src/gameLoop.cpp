#include "gameLoop.hpp"

GameLoop::GameLoop()
{
    bucketRender = new BlockRender();
    shapeRender = new BlockRender();
    bucket = new Bucket();
    activeShape = new ActiveShape();

    bucketRender->time = time;
    shapeRender->time = time;
    bucketRender->deltaTime = deltaTime;
    shapeRender->deltaTime = deltaTime;
}

void GameLoop::updateTime()
{
    bucketRender->time = time;
    shapeRender->time = time;
    bucketRender->deltaTime = deltaTime;
    shapeRender->deltaTime = deltaTime;
}

GameLoop::~GameLoop()
{
    delete bucketRender;
    delete shapeRender;
}


void GameLoop::readInput()
{
    moveRight = IsKeyPressed(KEY_RIGHT) ? true : false;
    moveLeft = IsKeyPressed(KEY_LEFT) ? true : false;
    moveDown = IsKeyDown(KEY_SPACE) ? true : false;
    rotateRight = IsKeyPressed(KEY_UP) ? true : false;
    rotateLeft = IsKeyPressed(KEY_DOWN) ? true : false;

    moveRequsted = moveRight || moveLeft || rotateRight || rotateLeft;
}

void GameLoop::resetInput()
{
    rotateRight = false;
    rotateLeft = false;
    moveLeft = false;
    moveRight = false;
    moveDown = false;
    moveRequsted = false;
}

void GameLoop::tickLogic()
{
    f96 interval = moveDown ? tickIntervalFast : tickInterval;

    bool skipWaiting = false;
    // check if shape can fit, if it can then we skip waiting for the tick
    if(moveRequsted)
    {
        iXY requestedPosition = activeShape->bucketPosition;
        if(moveRight)
        {
            requestedPosition.x++;
        }
        if(moveLeft)
        {
            requestedPosition.x--;
        }
        if(rotateRight)
        {
            // activeShape->rotateRight();
        }
        if(rotateLeft)
        {
            // activeShape->rotateLeft();
        }

        if(activeShape->canFit(requestedPosition, *bucket->grid))
        {
            std::cout << "can fit" << std::endl;
            skipWaiting = true;
            activeShape->bucketPosition = requestedPosition;
            shapeRender->addOffsetToVisualTarget(fXY(requestedPosition.x * 10.f, requestedPosition.y * 10.f));
        }
    }

    if(time - lastTick > interval || skipWaiting)
    {
        std::cout << "tick" << std::endl;
        lastTick = time;
        resetInput();
    }
}

void GameLoop::updateActiveShape()
{
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
