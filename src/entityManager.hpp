#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP
#include "raylib.h"
#include "types/block.hpp"
#include <iostream>
#include <vector>

class EntityManager
{
      public:
    std::vector<Block> *blocks = new std::vector<Block>();
    f96 time = 0.0f;
    f96 deltaTime = 0.0f;

    void removeExpiredBlocks();
    void addBlock(Block block);
    void stepBlock(Block *block);
    void stepAllBucketBlocks();
    EntityManager();
    ~EntityManager();
};

#endif  // !ENTITY_MANAGER_HPP
