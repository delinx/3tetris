#include "activeShape.hpp"

ActiveShape::ActiveShape()
{
}

ActiveShape::~ActiveShape()
{
    delete grid;
}

bool ActiveShape::canFit(iXY xy, Grid &shape, Grid &bucket)
{
    if(shape.grid == NULL || bucket.grid == NULL)
    {
        return false;
    }
    for(i32 x = 0; x < shape.WIDTH; x++)
    {
        for(i32 y = 0; y < shape.HEIGHT; y++)
        {
            // if activeBlock cell is empty skip
            if(shape.get(iXY(x, y)) == 0)
            {
                continue;
            }
            // if activeBlock is outside grid return false
            if(xy.x + x < 0 || xy.x + x >= bucket.WIDTH || xy.y + y < -4 || xy.y + y >= bucket.HEIGHT)
            {
                return false;
            }
            if(bucket.get(iXY(xy.x + x, xy.y + y)) != 0)
            {
                return false;
            }
        }
    }
    return true;
}
