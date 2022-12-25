#include "block.hpp"

Block::Block()
{
}

Block::Block(iXY bucketPos, fXY visualPos)
{
    positionBucket = bucketPos;
    positionVisualCurrent = visualPos;
    positionVisualTarget = visualPos;
}

Block::~Block()
{
}

void Block::print()
{

    std::cout << "\n--- --- --- [" << pseudoUniqueID << "]\n"
              << "Bucket XY: " << positionBucket.x << ", " << positionBucket.y << "\n"
              << "--- *** ---\ncXY: " << positionVisualCurrent.x << ", " << positionVisualCurrent.y << " | "
              << "gXY: " << positionVisualTarget.x << ", " << positionVisualTarget.y << " (" << movementSpeed << ")\n"
              << "Del: b" << scheduledForDeletion << " | " << deleteAfterTimestamp << "\n"
              << "Animation: b" << playingAnimation << " | Del: b" << deleteAfterAnimating << " | " << animationTimestampCurrent
              << " | (" << animationSpeed << ")\n"
              << std::endl;
}
