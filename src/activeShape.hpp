#ifndef ACTIVE_SHAPE_HPP
#define ACTIVE_SHAPE_HPP

#include "types/grid.hpp"
#include "types/shape.hpp"

class ActiveShape
{
    Grid *grid = NULL;
    iXY bucketPosition = iXY(3, -4);

    bool canFit(iXY xy, Grid &shape, Grid &bucket);

    ActiveShape();
    ~ActiveShape();
};

#endif  // !ACTIVE_SHAPE_HPP
