#include "blockRender.hpp"
#include <string>

BlockRender::BlockRender()
{
}

BlockRender::~BlockRender()
{
}

void BlockRender::removeExpiredBlocks()
{
    std::vector<Block> *NewBlocks = new std::vector<Block>();
    for(int i = 0; i < blocks->size(); i++)
    {
        if(!blocks->at(i).scheduledForDeletion)
        {
            NewBlocks->push_back(blocks->at(i));
        }
    }
    delete blocks;
    blocks = NewBlocks;
}

void BlockRender::addBlock(Block block)
{
    blocks->push_back(block);
}

void BlockRender::stepBlock(Block *block)
{
    // check if block needs to be deleted after certain time has passed
    if(block->deleteAfterTimestamp > 0.0f)
    {
        if(time > block->deleteAfterTimestamp)
        {
            block->scheduledForDeletion = true;
        }
    }
    // check if block needs to be deleted after animation has finished
    if(block->deleteAfterAnimating)
    {
        if(block->animationTimestampCurrent >= block->animationTimestampEnd)
        {
            block->scheduledForDeletion = true;
        }
    }
    // check if block needs to be animated
    if(block->playingAnimation)
    {
        block->animationTimestampCurrent += block->animationSpeed * deltaTime;
        if(block->animationTimestampCurrent > 100.f)
        {
            block->animationTimestampCurrent = 100.f;
        }
    }
    // check if block needs to be moved in X or Y
    if(block->positionVisualCurrent.x != block->positionVisualTarget.x)
    {
        block->positionVisualCurrent.x += block->movementSpeed * deltaTime;
        if(block->positionVisualCurrent.x > block->positionVisualTarget.x)
        {
            block->positionVisualCurrent.x = block->positionVisualTarget.x;
        }
    }
    if(block->positionVisualCurrent.y != block->positionVisualTarget.y)
    {
        block->positionVisualCurrent.y += block->movementSpeed * deltaTime;
        if(block->positionVisualCurrent.y > block->positionVisualTarget.y)
        {
            block->positionVisualCurrent.y = block->positionVisualTarget.y;
        }
    }
    block->print();
}

void BlockRender::stepAllBucketBlocks()
{
    for(int i = 0; i < blocks->size(); i++)
    {
        stepBlock(&blocks->at(i));
    }
}
