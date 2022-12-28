#include "bucket.hpp"

Bucket::Bucket()
{
    grid = new Grid(WIDTH, HEIGHT);
}

Bucket::~Bucket()
{
    delete grid;
}


void Bucket::bakeShape(ActiveShape &shape)
{
    iXY xy = shape.bucketPosition;

    if(shape.grid == NULL)
    {
        return;
    }
    for(i32 x = 0; x < shape.grid->WIDTH; x++)
    {
        for(i32 y = 0; y < shape.grid->HEIGHT; y++)
        {
            if(shape.grid->get(iXY(x, y)) != 0)
            {
                grid->set(iXY(x + xy.x, y + xy.y), shape.grid->get(iXY(x, y)));
            }
        }
    }
}
