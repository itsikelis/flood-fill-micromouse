#pragma once

#include <iostream>
#include <math.h>

///  Class Cell
///  Functions here are only accessible via the Maze.cpp functions 
///  and are NOT MEANT to be used directly by other robot functions.

class Cell
{
private:

    int x;
    int y;

    int wallNorth;
    int wallSouth;
    int wallEast;
    int wallWest;

public:

    ///  Create cell with no walls initially
    Cell();

    /// Deconstructor
    ~Cell();

    /// Used by Maze.hpp to set the cell's coordinates
    void setCoords(int x, int y);

    /// Used by Maze.hpp to set a found wall to the corresponding cell
    void setWall(int orientation);
};

Cell::Cell()
{
    wallNorth = 0;
    wallSouth = 0;
    wallEast = 0;
    wallWest = 0;
}

Cell::~Cell()
{
}

void Cell::setCoords(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
}

///  Orientation: 1 for North, 2 for South, 3 for East, 4 for West
void Cell::setWall(int orientation)
{
    switch (orientation)
    {
    case 1:
        wallNorth = 1;
        break;
    case 2:
        wallSouth = 1;
        break;
    case 3:
        wallEast = 1;
        break;
    case 4:
        wallWest = 1;
        break;
    default:
        std::cout << "A problem occured in setWall" << std::endl;
        break;
    }
}