#include "activeShape.hpp"

ActiveShape::ActiveShape()
{
    getRandomShape();
}

ActiveShape::~ActiveShape()
{
    delete grid;
}

void ActiveShape::getRandomShape()
{
    if(grid != NULL)
    {
        delete grid;
    }

    int random = rand() % 7;
    switch(random)
    {
        case 0:
            grid = shapeTemplate.shape_I.copy();
            break;
        case 1:
            grid = shapeTemplate.shape_J.copy();
            break;
        case 2:
            grid = shapeTemplate.shape_L.copy();
            break;
        case 3:
            grid = shapeTemplate.shape_O.copy();
            break;
        case 4:
            grid = shapeTemplate.shape_S.copy();
            break;
        case 5:
            grid = shapeTemplate.shape_T.copy();
            break;
        case 6:
            grid = shapeTemplate.shape_Z.copy();
            break;
    }
}

bool ActiveShape::canFit(iXY xy, Grid &bucket)
{
    if(grid == NULL || bucket.grid == NULL)
    {
        return false;
    }
    for(i32 x = 0; x < grid->WIDTH; x++)
    {
        for(i32 y = 0; y < grid->HEIGHT; y++)
        {
            // if activeBlock cell is empty skip
            if(grid->get(iXY(x, y)) == 0)
            {
                continue;
            }
            // if activeBlock is outside grid return false
            if(xy.x + x < 0 || xy.x + x >= bucket.WIDTH || xy.y + y < -4 || xy.y + y >= bucket.HEIGHT)
            {
                std::cout << "out of bounds" << std::endl;
                return false;
            }
            if(bucket.get(iXY(xy.x + x, xy.y + y)) != 0)
            {
                std::cout << "collision" << std::endl;
                return false;
            }
        }
    }
    return true;
}
