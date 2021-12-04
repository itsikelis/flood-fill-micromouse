#pragma once

#include <iostream>
#include <math.h>
#include "Param.hpp"
#include "Maze.hpp"
#include "Queue.hpp"

class Algorithm
{
private:
    
    ///  The absolute path to the maze's solution.
    std::string path;

    ///  A queue to store the cells that still need to be processed.
    Queue processQueue;

public:

    Algorithm();
    ~Algorithm();

    void printTest(Maze *maze);
    void printTest2(Maze *maze);

    void reflood(Maze *maze, int curr_x, int curr_y);

    int checkNeighbour(Maze *maze, Coordinate coord, int orientation);

    ///  Returns the absolute path to the maze's center
    std::string getPath();
};

Algorithm::Algorithm()
{

}

Algorithm::~Algorithm()
{

}

void Algorithm::printTest(Maze *maze)
{
    // maze->printMazeFloodVal();
    printTest2(maze);
}

void Algorithm::printTest2(Maze *maze)
{
    maze->printMazeFloodVal();
}

/**
 * @brief Refloods the maze.
 * 
 * REVIEW  curr_x and curr_y might not be needed for reflood and only needed for findPath
 * 
 * @param maze Pointer to maze.
 * @param curr_x Current x coordinate.
 * @param curr_y Current y coordinate.
 */
void Algorithm::reflood(Maze *maze, int curr_x, int curr_y)
{
    ///  Set all cells on maze as unvisited.
    for (int i = 0; i <= CELL_COUNT; i++)
    {
        for (int j = 0; i <= CELL_COUNT; i++)
        {
            maze->setVisited(0, i, j);
        }
    }

    ///  Zero the floodval of the goal cells.
    maze->setFloodVal(0, (CELL_COUNT / 2) - 1, (CELL_COUNT / 2) - 1);       ///  Cell(7,7).floodVal = 0.
    maze->setFloodVal(0, CELL_COUNT / 2, (CELL_COUNT / 2) - 1);             ///  Cell(8,7).floodVal = 0.
    maze->setFloodVal(0, (CELL_COUNT / 2) - 1, CELL_COUNT / 2);             ///  Cell(7,8).floodVal = 0.
    maze->setFloodVal(0, CELL_COUNT / 2, CELL_COUNT / 2);                   ///  Cell(8,8).floodVal = 0.

    ///  Set goal cells as visited.
    maze->setVisited(1, (CELL_COUNT / 2) - 1, (CELL_COUNT / 2) - 1);        ///  Cell(7,7).visited = 1.
    maze->setVisited(1, CELL_COUNT / 2, (CELL_COUNT / 2) - 1);              ///  Cell(8,7).visited = 1.
    maze->setVisited(1, (CELL_COUNT / 2) - 1, CELL_COUNT / 2);              ///  Cell(7,8).visited = 1.
    maze->setVisited(1, CELL_COUNT / 2, CELL_COUNT / 2);                    ///  Cell(8,8).visited = 1.

    ///  Push goal cells' coordinates to queue.
    processQueue.qPush((CELL_COUNT / 2) - 1, (CELL_COUNT / 2) - 1);         ///  Cell(7,7) pushed.
    processQueue.qPush(CELL_COUNT / 2, (CELL_COUNT / 2) - 1);               ///  Cell(8,7) pushed.
    processQueue.qPush((CELL_COUNT / 2) - 1, CELL_COUNT / 2);               ///  Cell(7,8) pushed.
    processQueue.qPush(CELL_COUNT / 2, CELL_COUNT / 2);                     ///  Cell(8,8) pushed.

    while (!processQueue.qIsEmpty())
    {   
        ///  Get the next cell to be processed and remove it from the queue.
        Coordinate currentCell = processQueue.qFront();
        processQueue.qPop();

        ///  Get current cell's floodVal.
        int val = maze->getFloodVal(currentCell.coordX, currentCell.coordY);

        ///  Check northern neighbour.
        if ( checkNeighbour(maze, currentCell, 1) )
        {
            /// Increment northern neighbour's floodval.
            maze->setVisited(1, currentCell.coordX - 1, currentCell.coordY);            ///  Set neighbour as visited.
            maze->setFloodVal(val + 1, currentCell.coordX - 1, currentCell.coordY);     ///  Increment neighbour.
            processQueue.qPush(currentCell.coordX - 1, currentCell.coordY);             ///  Push neighbour to queue.
        }
        ///  Check southern neighbour.
        if ( checkNeighbour(maze, currentCell, 2) )
        {
            /// Increment southern neighbour's floodval.
            maze->setFloodVal(val + 1, currentCell.coordX + 1, currentCell.coordY);     ///  Increment neighbour.
            maze->setVisited(1, currentCell.coordX + 1, currentCell.coordY);            ///  Set neighbour as visited.
            processQueue.qPush(currentCell.coordX + 1, currentCell.coordY);             ///  Push neighbour to queue.
        }
        ///  Check eastern neighbour.
        if (checkNeighbour(maze, currentCell, 3))
        {
            /// Increment eastern neighbour's floodval.
            maze->setVisited(1, currentCell.coordX, currentCell.coordY - 1);            ///  Set neighbour as visited.
            maze->setFloodVal(val + 1, currentCell.coordX, currentCell.coordY - 1);     ///  Increment neighbour.
            processQueue.qPush(currentCell.coordX, currentCell.coordY - 1);             ///  Push neighbour to queue.
        }
        ///  Check western neighbour.
        if (checkNeighbour(maze, currentCell, 4))
        {
            /// Increment eastern neighbour's floodval.
            maze->setVisited(1, currentCell.coordX, currentCell.coordY + 1);            ///  Set neighbour as visited.
            maze->setFloodVal(val + 1, currentCell.coordX, currentCell.coordY + 1);     ///  Increment neighbour.
            processQueue.qPush(currentCell.coordX - 1, currentCell.coordY + 1);         ///  Push neighbour to queue.
        }
        else 
        {
            std::cout << "Something went wrong with reflood." << std::endl;
        }
    }
}

/**
 * @brief Method to check whether the neighbouring cell can be accessed from the current cell (no wall between them and neighbour has not been visited before). 
 * 
 * @param maze Pointer to maze.
 * @param coord The current cell.
 * @param orientation 1 for North, 2 for South, 3 for East, 4 for West.
 * @return int 
 */
int Algorithm::checkNeighbour(Maze *maze, Coordinate coord, int orientation)
{
    switch (orientation)
    {
    ///  Check northern neighbour.
    case 1:

        if (coord.coordX == 0)
        {
            return 0;       ///  If cell is at northern border, return 0.
        }
        else if (!maze->hasWall(coord.coordX, coord.coordY, orientation) && !maze->isVisited(coord.coordX - 1, coord.coordY))
        {
            return 1;       ///  Neighbour has no wall on that direction and is not marked as visited.
        }
        else
        {
            return 0;       ///  Neighbour has wall on that direction or is marked as visited.
        }

    break;

    ///  Check southern neighbour.
    case 2:

        if (coord.coordX == CELL_COUNT - 1)
        {
            return 0;       ///  If cell is at southern border, return 0.
        }
        else if (!maze->hasWall(coord.coordX, coord.coordY, orientation) && !maze->isVisited(coord.coordX + 1, coord.coordY))
        {
            return 1;       ///  Neighbour has no wall on that direction and is not marked as visited.
        }
        else
        {
            return 0;       ///  Neighbour has wall on that direction or is marked as visited.
        }

    break;

    ///  Check eastern neighbour.
    case 3:

        if (coord.coordY == 0)
        {
            return 0;       ///  If cell is at eastern border, return 0.
        }
        else if (!maze->hasWall(coord.coordX, coord.coordY, orientation) && !maze->isVisited(coord.coordX, coord.coordY - 1))
        {
            return 1;       ///  Neighbour has no wall on that direction and is not marked as visited.
        }
        else
        {
            return 0;       ///  Neighbour has wall on that direction or is marked as visited.
        }

    break;

    /// Check western neighbour.
    case 4:

        if (coord.coordY == CELL_COUNT - 1)
        {
            return 0;       ///  If cell is at western border, return 0.
        }
        else if (!maze->hasWall(coord.coordX, coord.coordY, orientation) && !maze->isVisited(coord.coordX, coord.coordY + 1))
        {
            return 1;       ///  Neighbour has no wall on that direction and is not marked as visited.
        }
        else
        {
            return 0;       ///  Neighbour has wall on that direction or is marked as visited.
        }

        break;
    default:
        
        std::cout << "Something went wrong with checkNeighbour." << std::endl;

        break;
    }
    
}