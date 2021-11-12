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

    int getFloodVal(int x, int y);
    void setFloodVal(int val, int x, int y);

    void setVisited(int val, int x, int y);

    void printMazeFloodVal();
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
                mazeCells[cell_x][cell_y].setWall(2);
                mazeCells[cell_x + 1][cell_y].setWall(1);
            }

            break;
        /// Place eastern wall on the cell and western wall on the cell on the left
        case 3:

            if (cell_y != 0)
            {
                mazeCells[cell_x][cell_y].setWall(3);
                mazeCells[cell_x][cell_y - 1].setWall(4);
            }

            break;
        /// Place western wall on the cell and eastern wall on the cell on the right
        case 4:

            if (cell_y != CELL_COUNT - 1)
            {
                mazeCells[cell_x][cell_y].setWall(4);
                mazeCells[cell_x][cell_y + 1].setWall(3);
            }

            break;
    }

}

int Maze::getFloodVal(int x, int y)
{
    mazeCells[x][y].getFloodVal();
}

void Maze::setFloodVal(int val,int x, int y)
{
    mazeCells[x][y].setFloodVal(val);
}

void Maze::setVisited(int val, int x, int y)
{
    mazeCells[x][y].setVisited(val);
}

void Maze::printMazeFloodVal()
{
    for(int i = 0; i <= CELL_COUNT; i++)
    {
        for(int j = 0; i <= CELL_COUNT; i++)
        {
            std::cout << " " << mazeCells[i][j].getFloodVal() << " " << "\t";
        }
        std::cout << std::endl;
    }
}