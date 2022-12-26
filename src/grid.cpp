#include "grid.hpp"

Grid::Grid(u32 width, u32 height)
{
    WIDTH = width;
    HEIGHT = height;
    grid = new i32[WIDTH * HEIGHT];
    for(usize i = 0; i < WIDTH * HEIGHT; i++)
    {
        grid[i] = 0;
    }
}

Grid::~Grid()
{
    delete[] grid;
}

void Grid::set(iXY xy, i32 value)
{
    grid[xy.x + WIDTH * xy.y] = value;
}

i32 Grid::get(iXY xy)
{
    return grid[xy.x + WIDTH * xy.y];
}
