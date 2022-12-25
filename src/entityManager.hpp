#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP
#include "block.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

class EntityManager
{
      public:
    std::vector<Block> blocks;

    EntityManager();
    ~EntityManager();
};

#endif  // !ENTITY_MANAGER_HPP
