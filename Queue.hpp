#pragma once

#include <iostream>
#include <math.h>
#include "Cell.hpp"
#include "Param.hpp"

///  Class Queue
///  This is a static queue to be used by the Algorithm.
///  The queue is static to avoid calling malloc for when using the Algorithm on Embedded Systems.
///
///  The queue has a size big enough to accomodate every cell of the maze.
///  It is initialised in O(1) time.
///

#define QUEUE_SIZE CELL_COUNT * CELL_COUNT

class Queue
{
private:
    Coordinate array[QUEUE_SIZE];

    int frontIndex;                         ///  Points at the first object in the queue.
    int backIndex;                          ///  Points at the last object in the queue.

public:
    Queue();
    ~Queue();

    int qIsEmpty();                         ///  Returns 1 if queue is empty, 0 if ti is not.

    void qPush(int newX, int newY);         ///  Pushes an object on the queue's back.
    void qPop();                            ///  Increments the front pointer to point at the next item in the queue.

    Coordinate qFront();                    ///  Returns the first object in the queue.

};

Queue::Queue()
{
    frontIndex = 0;
    backIndex = 0;
}

Queue::~Queue()
{
}

void Queue::qPush(int newX, int newY)
{
    if( backIndex < QUEUE_SIZE)
    {
        array[backIndex].coordX = newX;
        array[backIndex].coordY = newY;
        backIndex++;
    }
    else 
    {
        std::cout << "Queue is full." << std::endl;
    }
}


void Queue::qPop()
{
    frontIndex++;
}

Coordinate Queue::qFront()
{
    return array[frontIndex];
}

int Queue::qIsEmpty()
{
    if (frontIndex > backIndex)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
