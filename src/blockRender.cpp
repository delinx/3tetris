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

void BlockRender::addBlock(Block *block)
{
    blocks->push_back(*block);
}

void BlockRender::addBlocksFromGrid(Grid *grid)
{
    for(int x = 0; x < grid->WIDTH; x++)
    {
        for(int y = 0; y < grid->HEIGHT; y++)
        {
            if(grid->get(iXY(x, y)) != 0)
            {
                Block *block = new Block();
                block->positionBucket = iXY(x, y);
                block->positionVisualTarget = fXY(x * 10.0f, y * 10.0f);
                block->BaseColor = RED;
                addBlock(block);
            }
        }
    }
}

void BlockRender::addOffsetToVisualTarget(fXY offset)
{
    for(int i = 0; i < blocks->size(); i++)
    {
        blocks->at(i).positionVisualTarget.x = offset.x + blocks->at(i).positionBucket.x * 10.0f;
        blocks->at(i).positionVisualTarget.y = offset.y + blocks->at(i).positionBucket.y * 10.0f;
    }
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
        if(block->positionVisualCurrent.x > block->positionVisualTarget.x)
        {
            block->positionVisualCurrent.x -= block->movementSpeed * deltaTime;
        }
        if(block->positionVisualCurrent.x < block->positionVisualTarget.x)
        {
            block->positionVisualCurrent.x += block->movementSpeed * deltaTime;
        }
        if(std::abs(block->positionVisualCurrent.x - block->positionVisualTarget.x) < 1.f)
        {
            block->positionVisualTarget.x = block->positionVisualTarget.x;
        }
    }
    if(block->positionVisualCurrent.y != block->positionVisualTarget.y)
    {
        if(block->positionVisualCurrent.y > block->positionVisualTarget.y)
        {
            block->positionVisualCurrent.y -= block->movementSpeed * deltaTime;
        }
        if(block->positionVisualCurrent.y < block->positionVisualTarget.y)
        {
            block->positionVisualCurrent.y += block->movementSpeed * deltaTime;
        }
        if(std::abs(block->positionVisualCurrent.y - block->positionVisualTarget.y) < 1.f)
        {
            block->positionVisualTarget.y = block->positionVisualTarget.y;
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

void BlockRender::drawAllBucketBlocksDebug()
{
    for(int i = 0; i < blocks->size(); i++)
    {
        Block block = blocks->at(i);
        std::cout << "Drawing block " << std::endl;
        DrawRectangle(block.positionVisualCurrent.x, block.positionVisualCurrent.y, block.size, block.size, block.BaseColor);
    }
}
