#include "bucket.hpp"

Bucket::Bucket()
{
    grid = new Grid(WIDTH, HEIGHT);
}

Bucket::~Bucket()
{
    delete grid;
}
