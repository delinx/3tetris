#ifndef BLOCK_HPP
#define BLOCK_HPP
#include "xy.hpp"
#include <iostream>

class Block
{
      public:
    iXY positionBucket;
    fXY positionVisualCurrent;
    fXY positionVisualTarget;

    Block();
    ~Block();
};

#endif  // !BLOCK_HPP
