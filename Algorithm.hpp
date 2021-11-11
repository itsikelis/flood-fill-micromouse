#pragma once

#include <iostream>
#include <math.h>
#include "Param.hpp"
#include "Maze.hpp"

class Algorithm
{
private:
    
    std::string path;

public:

    Algorithm();
    ~Algorithm();

    /// Refloods the maze.
    void reflood(Maze *maze);

    /// Returns the absolute path to the maze's center
    std::string getPath();
};

Algorithm::Algorithm()
{

}

Algorithm::~Algorithm()
{

}

