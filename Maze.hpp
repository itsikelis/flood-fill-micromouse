#pragma once

#include <iostream>
#include <math.h>
#include "Param.hpp"
#include "Cell.hpp"

class Maze
{
private:

    Cell mazeCells[CELL_COUNT][CELL_COUNT];

public:

    ///  Initiate cell coordinates and place perimeter walls
    Maze();

    ///  Deconstructor
    ~Maze();

    ///  Used by the robot to place a discovered wall to the maze cell.
    void placeWall(int cellX, int cellY, int orientation);

    /// Used by the robot to check for neighbouring walls.
    int hasWall(int cellX, int cellY, int orientation);

    int getFloodVal(int x, int y);
    void setFloodVal(int val, int x, int y);

    ///  Mark cell as visited.
    void setVisited(int val, int x, int y);

    ///  Return whether or not the maze cell has been visited.
    int isVisited(int cellX, int cellY);

    void printMazeFloodVal();
};

Maze::Maze()
{
    for (int i = 0; i <= CELL_COUNT - 1; i++)
    {

        ///  Set the coordinates of each cell in the maze.
        ///  REVIEW Check if having cell coords as a variable is really nesessary.
        ///  It is not needed, but it helps when looking at maze cells during debugging.
        for (int j = 0; j <= CELL_COUNT - 1; j++)
        {
            mazeCells[i][j].setCoords(i, j);
        }

        mazeCells[0][i].setWall(1);             ///  Place northern perimeter walls.
        mazeCells[CELL_COUNT - 1][i].setWall(2);    ///  Place southern perimeter walls.
        mazeCells[i][0].setWall(3);             ///  Place eastern perimeter walls.
        mazeCells[i][CELL_COUNT - 1].setWall(4);    ///  Place western perimeter walls.


    }
}

Maze::~Maze()
{

}

///  placeWall avoids placing walls outside of maze borders
///  Orientation: 1 for North, 2 for South, 3 for East, 4 for West
void Maze::placeWall(int cellX, int cellY, int orientation)
{
    switch (orientation)
    {
        /// Place northern wall on the cell and southern wall on the cell above.
        case 1:

            if(cellX != 0)
            {
                mazeCells[cellX][cellY].setWall(1);
                mazeCells[cellX - 1][cellY].setWall(2);
            }

            break;
        /// Place southern wall on the cell and northern wall on the cell below.
        case 2:

            if (cellX != 0 && cellX != CELL_COUNT - 1)
            {
                mazeCells[cellX][cellY].setWall(2);
                mazeCells[cellX + 1][cellY].setWall(1);
            }

            break;
        /// Place eastern wall on the cell and western wall on the cell on the left
        case 3:

            if (cellY != 0)
            {
                mazeCells[cellX][cellY].setWall(3);
                mazeCells[cellX][cellY - 1].setWall(4);
            }

            break;
        /// Place western wall on the cell and eastern wall on the cell on the right
        case 4:

            if (cellY != CELL_COUNT - 1)
            {
                mazeCells[cellX][cellY].setWall(4);
                mazeCells[cellX][cellY + 1].setWall(3);
            }

            break;
    }

}

///  Orientation: 1 for North, 2 for South, 3 for East, 4 for West
int Maze::hasWall(int cellX, int cellY, int orientation)
{
    if ( mazeCells[cellX][cellY].hasWall(orientation) )
    {
        return 1;       ///  Wall at given orientation found.
    }
    else
    {
        return 0;       ///  Wall at given orientation not found.
    }
}

int Maze::getFloodVal(int x, int y)
{
    return mazeCells[x][y].getFloodVal();
}

void Maze::setFloodVal(int val,int x, int y)
{
    mazeCells[x][y].setFloodVal(val);
}

/// <summary>
/// 
/// </summary>
/// <param name="val"></param>
/// <param name="x"></param>
/// <param name="y"></param>
void Maze::setVisited(int val, int x, int y)
{
    mazeCells[x][y].setVisited(val);
}

int Maze::isVisited(int cellX, int cellY)
{
    if ( !mazeCells[cellX][cellY].isVisited() )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Maze::printMazeFloodVal()
{
    for(int i = 0; i < CELL_COUNT; i++)
    {
        for(int j = 0; j < CELL_COUNT; j++)
        {
            std::cout << " " << mazeCells[i][j].getFloodVal() << " " ;
        }
        std::cout << std::endl;
    }
}