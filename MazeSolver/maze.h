#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <cstring>

using namespace std;

bool isValid(int **maze, int **solution, int x, int y, int numsSize)
{
    return (
        x >= 0 &&
        x < numsSize &&
        y >= 0 &&
        y < numsSize &&
        maze[x][y] != 0 &&
        solution[x][y] == 0);
}

bool searchLongestPath(int **maze, int **solution, int x, int y, int &maxLength, int currentLength, int numsSize)
{
    if (!isValid(maze, solution, x, y, numsSize))
        return false;

    solution[x][y] = 1;

    if (x == numsSize - 1 && y == numsSize - 1)
    {
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
        return true;
    }

    bool pathFound = false;

    for (int jump = 1; jump <= maze[x][y]; jump++)
    {
        if (searchLongestPath(maze, solution, x, y + jump, maxLength, currentLength + 1, numsSize))
            pathFound = true;
        if (searchLongestPath(maze, solution, x, y - jump, maxLength, currentLength + 1, numsSize))
            pathFound = true;
        if (searchLongestPath(maze, solution, x + jump, y, maxLength, currentLength + 1, numsSize))
            pathFound = true;
        if (searchLongestPath(maze, solution, x - jump, y, maxLength, currentLength + 1, numsSize))
            pathFound = true;
    }

    if (!pathFound)
    {
        solution[x][y] = 0;
    }

    return pathFound;
}

#endif
