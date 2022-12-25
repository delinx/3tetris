#ifndef BLOCK_HPP
#define BLOCK_HPP
#include "types.hpp"
#include "xy.hpp"
#include <iostream>
#include <random>

class Block
{
      private:
    i32 pseudoUniqueID = rand() % 1000;

      public:
    iXY positionBucket;
    fXY positionVisualCurrent;
    fXY positionVisualTarget;
    f32 movementSpeed = 4.0f;

    bool scheduledForDeletion = false;
    f32 deleteAfterTimestamp = 0.0f;

    bool playingAnimation = false;
    bool deleteAfterAnimating = false;
    f32 animationTimestampCurrent = 0.0f;
    const f32 animationTimestampEnd = 100.0f;

    f32 animationSpeed = 1.0f;

    void print();

    Block();
    Block(iXY bucketPos, fXY visualPos);
    Block(iXY bucketPos, fXY visualPosCurrent, fXY visualPosTarget);
    ~Block();
};

#endif  // !BLOCK_HPP
