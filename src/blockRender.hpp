#ifndef BLOCK_RENDER_HPP
#define BLOCK_RENDER_HPP
#include "raylib.h"
#include "types/block.hpp"
#include <iostream>
#include <vector>

class BlockRender
{
      public:
    std::vector<Block> *blocks = new std::vector<Block>();
    f96 time = 0.0f;
    f96 deltaTime = 0.0f;

    void removeExpiredBlocks();
    void addBlock(Block block);
    void stepBlock(Block *block);
    void stepAllBucketBlocks();
    BlockRender();
    ~BlockRender();
};

#endif  // !BLOCK_RENDER_HPP
