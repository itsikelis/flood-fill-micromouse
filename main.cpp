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

    return 0;
}