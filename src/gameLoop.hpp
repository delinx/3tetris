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

    bool rotateRight = false;
    bool rotateLeft = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool moveDown = false;

    BlockRender *bucketRender = NULL;
    BlockRender *shapeRender = NULL;

    Bucket *bucket = NULL;
    ActiveShape *activeShape = NULL;

    void readInput();
    void resetInput();

    void drawControls();

    GameLoop();
    ~GameLoop();
};

#endif  // !GAME_LOOP_HPP
