#include "gameLoop.hpp"

GameLoop::GameLoop()
{
    bucketRender = new BlockRender();
    shapeRender = new BlockRender();
}

GameLoop::~GameLoop()
{
    delete bucketRender;
    delete shapeRender;
}
