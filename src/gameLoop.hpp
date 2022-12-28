#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP
#include "activeShape.hpp"
#include "blockRender.hpp"
#include "bucket.hpp"
#include "types/grid.hpp"
#include "types/shape.hpp"
#include "types/types.hpp"
#include <iostream>
#include <raylib.h>

class GameLoop
{

      public:
    f96 time = 0.0f;
    f96 deltaTime = 0.0f;
    f96 lastTick = 0.0f;
    f96 tickInterval = 0.4f;
    f96 tickIntervalFast = 0.1f;

    bool rotateRight = false;
    bool rotateLeft = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool moveDown = false;
    bool moveRequsted = false;

    BlockRender *bucketRender = NULL;
    BlockRender *shapeRender = NULL;

    Bucket *bucket = NULL;
    ActiveShape *activeShape = NULL;

    void readInput();
    void resetInput();
    void tickLogic();
    void updateTime();

    void drawControls();

    void updateActiveShape();

    GameLoop();
    ~GameLoop();
};

#endif  // !GAME_LOOP_HPP
