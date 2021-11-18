#include <iostream>
#include "Cell.hpp"
#include "Maze.hpp"
#include "Algorithm.hpp"
int main()
{
    Maze thisMaze;

    // thisMaze.printMazeFloodVal();

    Algorithm thisAlgorithm;

    thisAlgorithm.printTest(&thisMaze);

    // thisMaze.placeWall(0,0,4);
    // thisMaze.placeWall(0,1,2);

    thisAlgorithm.reflood(&thisMaze, 0, 0);

    thisAlgorithm.printTest(&thisMaze);

    return 0;
}