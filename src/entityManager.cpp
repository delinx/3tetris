#include "entityManager.hpp"
#include <string>

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::removeExpiredBlocks()
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

void EntityManager::addBlock(Block block)
{
    blocks->push_back(block);
}

void EntityManager::stepBlocks()
{
    for(int i = 0; i < blocks->size(); i++)
    {
        // check if block needs to be deleted after certain time has passed
        if(blocks->at(i).deleteAfterTimestamp > 0.0f)
        {
            if(time > blocks->at(i).deleteAfterTimestamp)
            {
                blocks->at(i).scheduledForDeletion = true;
            }
        }
        // check if block needs to be deleted after animation has finished
        if(blocks->at(i).deleteAfterAnimating)
        {
            if(blocks->at(i).animationTimestampCurrent >= blocks->at(i).animationTimestampEnd)
            {
                blocks->at(i).scheduledForDeletion = true;
            }
        }
        // check if block needs to be animated
        if(blocks->at(i).playingAnimation)
        {
            blocks->at(i).animationTimestampCurrent += blocks->at(i).animationSpeed * deltaTime;
            if(blocks->at(i).animationTimestampCurrent > 100.f)
            {
                blocks->at(i).animationTimestampCurrent = 100.f;
            }
        }
        // check if block needs to be moved in X or Y
        if(blocks->at(i).positionVisualCurrent.x != blocks->at(i).positionVisualTarget.x)
        {
            blocks->at(i).positionVisualCurrent.x += blocks->at(i).movementSpeed * deltaTime;
            if(blocks->at(i).positionVisualCurrent.x > blocks->at(i).positionVisualTarget.x)
            {
                blocks->at(i).positionVisualCurrent.x = blocks->at(i).positionVisualTarget.x;
            }
        }
        if(blocks->at(i).positionVisualCurrent.y != blocks->at(i).positionVisualTarget.y)
        {
            blocks->at(i).positionVisualCurrent.y += blocks->at(i).movementSpeed * deltaTime;
            if(blocks->at(i).positionVisualCurrent.y > blocks->at(i).positionVisualTarget.y)
            {
                blocks->at(i).positionVisualCurrent.y = blocks->at(i).positionVisualTarget.y;
            }
        }
        blocks->at(i).print();
    }
}
