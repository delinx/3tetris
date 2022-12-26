#ifndef GRID_HPP
#define GRID_HPP
#include "types.hpp"
#include "xy.hpp"

class Grid
{
      public:
    u32 WIDTH;
    u32 HEIGHT;
    i32 *grid = NULL;

    /// make a newi32 array of X*Y size
    Grid(u32 width, u32 height);
    ~Grid();

    /// set XY to giveni32
    void set(iXY xy, i32 value);

    /// get XY value
    i32 get(iXY xy);
};


#endif  // !GRID_HPP
