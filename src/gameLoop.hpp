#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP
#include "blockRender.hpp"
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

    BlockRender *bucketRender = NULL;
    BlockRender *shapeRender = NULL;

    GameLoop();
    ~GameLoop();
};

#endif  // !GAME_LOOP_HPP
