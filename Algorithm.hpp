#pragma once

#include <iostream>
#include <math.h>
#include <queue>
#include "Param.hpp"
#include "Maze.hpp"

class Algorithm
{
private:
    
    std::string path;

    struct Coordinate
    {
        int coordX;
        int coordY;

        Coordinate(double paramx, double paramy) : coordX(paramx), coordY(paramy) {}
    };

    std::queue<Coordinate> processQueue;

public:

    Algorithm();
    ~Algorithm();

    /// Refloods the maze.
    void reflood(Maze *maze, int curr_x, int curr_y);

    /// Returns the absolute path to the maze's center
    std::string getPath();
};

Algorithm::Algorithm()
{

}

Algorithm::~Algorithm()
{

}

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

    ///  Set goal cells as visited and push to queue.
    maze->setVisited(1, (CELL_COUNT / 2) - 1, (CELL_COUNT / 2) - 1) ;                   ///  Cell(7,7).visited = 1.
    maze->setVisited(1, CELL_COUNT / 2, (CELL_COUNT / 2) - 1);                          ///  Cell(8,7).visited = 1.
    maze->setVisited(1, (CELL_COUNT / 2) - 1, CELL_COUNT / 2);                          ///  Cell(7,8).visited = 1.
    maze->setVisited(1, CELL_COUNT / 2, CELL_COUNT / 2);                                ///  Cell(8,8).visited = 1.

    processQueue.push(Coordinate((CELL_COUNT / 2) - 1, (CELL_COUNT / 2) - 1));          ///  Cell(7,7) pushed.
    processQueue.push(Coordinate(CELL_COUNT / 2, (CELL_COUNT / 2) - 1));                ///  Cell(8,7) pushed.
    processQueue.push(Coordinate((CELL_COUNT / 2) - 1, CELL_COUNT / 2));                ///  Cell(7,8) pushed.
    processQueue.push(Coordinate(CELL_COUNT / 2, CELL_COUNT / 2));                      ///  Cell(8,8) pushed.

    ///  Zero the floodval of the goal cells.
    maze->setFloodVal(0, (CELL_COUNT / 2) - 1, (CELL_COUNT / 2) - 1);                   ///  Cell(7,7).floodVal = 0.
    maze->setFloodVal(0, CELL_COUNT / 2, (CELL_COUNT / 2) - 1);                         ///  Cell(8,7).floodVal = 0.
    maze->setFloodVal(0, (CELL_COUNT / 2) - 1, CELL_COUNT / 2);                         ///  Cell(7,8).floodVal = 0.
    maze->setFloodVal(0, CELL_COUNT / 2, CELL_COUNT / 2);                               ///  Cell(8,8).floodVal = 0.

    while (!processQueue.empty())
    {   
        Coordinate cuurentCell = processQueue.front();
        processQueue.pop();
        

    }
}
