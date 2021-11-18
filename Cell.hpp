#pragma once

#include <iostream>
#include <math.h>

///  Class Cell
///  Functions here are only accessible via the Maze.cpp functions 
///  and are NOT MEANT to be used directly by other robot functions.

class Cell
{
private:

    int x;                  ///  Cell row.
    int y;                  ///  Cell column.
    int floodVal;           ///  Value given to cell by Floodfill.
    int visited;

    int wallNorth;
    int wallSouth;
    int wallEast;
    int wallWest;

public:

    ///  Create cell with no walls initially.
    Cell();

    ///  Deconstructor.
    ~Cell();

    ///  Used by Maze.hpp to set the cell's coordinates.
    void setCoords(int new_x, int new_y);

    ///  Used by Maze.hpp to get the cell's floodVal.
    int getFloodVal();

    ///  Used by Maze.hpp to set the cell's distance from current coordinates.
    void setFloodVal(int val);

    ///  Used by Maze.hpp to set a found wall to the corresponding cell.
    void setWall(int orientation);

    ///  Used by Maze.hpp to check for walls in given orientation.
    int hasWall(int orientation);

    ///  Used by Maze.hpp to set the visited flag to each cells.
    void setVisited(int val);

    ///  Used by Maze.hpp to check if the cell has been visited before by the Algorithm.
    int isVisited();

};

Cell::Cell()
{   
    visited = 0;
    floodVal = 0;

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

int Cell::getFloodVal()
{
    return floodVal;
}

void Cell::setFloodVal(int val)
{
    floodVal = val;
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

int Cell::hasWall(int orientation)
{
    switch (orientation)
    {
    ///  Check for northern wall.
    case 1:
        if(wallNorth == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        break;
    ///  Check for southern wall.
    case 2:
        if (wallSouth == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        break;
    ///  Check for eastern wall.
    case 3:
        if (wallEast == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        break;
    ///  Check for western wall.
    case 4:
        if (wallWest == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        break;
    default:
        std::cout << "Something went wrong in checkWall" << std::endl;
        return 1;
        break;
    }
}

void Cell::setVisited(int val)
{
    visited = val;
}

int Cell::isVisited()
{
    if (!visited)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}