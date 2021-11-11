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
    void placeWall(int cell_x, int cell_y, int orientation); 
};

Maze::Maze()
{
    for (int i = 0; i <= CELL_COUNT; i++)
    {
        mazeCells[0][i].setWall(1);          ///  Place northern perimeter walls.
        mazeCells[CELL_COUNT][i].setWall(2); ///  Place southern perimeter walls.
        mazeCells[i][0].setWall(3);          ///  Place eastern perimeter walls.
        mazeCells[i][CELL_COUNT].setWall(4); ///  Place western perimeter walls.

        ///  Set the coordinates of each cell in the maze
        ///  REVIEW Check if having cell coords as a variable is really nesessary
        for (int j = 0; j <= CELL_COUNT; j++)
        {
            mazeCells[i][j].setCoords(i, j);
        }
    }
}

/// placeWall avoids placing walls outside of maze borders
void Maze::placeWall(int cell_x, int cell_y, int orientation)
{
    switch (orientation)
    {
        /// Place northern wall on the cell and southern wall on the cell above.
        case 1:

            if(cell_x != 0)
            {
                mazeCells[cell_x][cell_y].setWall(1);
                mazeCells[cell_x - 1][cell_y].setWall(2);
            }

            break;
        /// Place southern wall on the cell and northern wall on the cell below.
        case 2:

            if (cell_x != 0 && cell_x != CELL_COUNT - 1)
            {
                mazeCells[cell_x][cell_y].setWall(orientation);
                mazeCells[cell_x][cell_y].setWall();
            }

            break;
        /// Place eastern wall
        case 3:

            mazeCells[cell_x][cell_y].setWall(orientation);

            if (cell_x != 0 && cell_x != CELL_COUNT - 1)
            {
                mazeCells[cell_x][cell_y].setWall();
            }

            break;
        /// Place western wall
        case 4:

            mazeCells[cell_x][cell_y].setWall(orientation);

            if (cell_x != 0 && cell_x != CELL_COUNT - 1)
            {
                mazeCells[cell_x][cell_y].setWall();
            }

            break;
    }

}

