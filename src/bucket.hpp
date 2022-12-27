#ifndef BUCKET_HPP
#define BUCKET_HPP
#include "types/grid.hpp"
#include "types/types.hpp"

// setup bucket
// rotation
// move
// logicalTick
class Bucket
{
    Bucket();
    ~Bucket();
    const u32 WIDTH = 10;
    const u32 HEIGHT = 20;

    Grid *grid = NULL;
    // bool findSolvedRows();
    // void removeSolvedRows();
    // void moveRowsDown(u32 row);
};

#endif  // !BUCKET_HPP
