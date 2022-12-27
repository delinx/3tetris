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


Grid* Grid::rotate(bool clockwise)
{
    Grid* newGrid = new Grid(HEIGHT, WIDTH);
    for(u32 x = 0; x < WIDTH; x++)
    {
        for(u32 y = 0; y < HEIGHT; y++)
        {
            if(clockwise)
            {
                newGrid->set(iXY(y, WIDTH - x - 1), get(iXY(x, y)));
            }
            else
            {
                newGrid->set(iXY(HEIGHT - y - 1, x), get(iXY(x, y)));
            }
        }
    }
    return newGrid;
}

Grid* Grid::copy()
{
    Grid* newGrid = new Grid(WIDTH, HEIGHT);
    for(int i = 0; i < WIDTH * HEIGHT; i++)
    {
        newGrid->grid[i] = grid[i];
    }
    return newGrid;
}
