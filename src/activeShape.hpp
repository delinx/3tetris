#ifndef ACTIVE_SHAPE_HPP
#define ACTIVE_SHAPE_HPP

#include "types/grid.hpp"
#include "types/shape.hpp"

class ActiveShape
{
      public:
    Grid *grid = NULL;
    iXY bucketPosition = iXY(4, 1);

    bool canFit(iXY xy, Grid &bucket);

    Shape shapeTemplate = Shape();
    void getRandomShape();
    ActiveShape();
    ~ActiveShape();
};

#endif  // !ACTIVE_SHAPE_HPP
