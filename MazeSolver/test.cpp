#include <iostream>
#include <cstring>
#include <cassert>
#include "maze.h"

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

bool searchLongestPath(int **maze, int **solution, int x, int y, int &maxLength, int currentLength, int numsSize, int **bestSolution)
{
    if (!isValid(maze, solution, x, y, numsSize))
        return false;

    currentLength += maze[x][y];
    solution[x][y] = 1;

    if (x == numsSize - 1 && y == numsSize - 1)
    {
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            // Copy current solution to bestSolution
            for (int i = 0; i < numsSize; i++)
                for (int j = 0; j < numsSize; j++)
                    bestSolution[i][j] = solution[i][j];
        }
        solution[x][y] = 0;
        return true;
    }

    bool pathFound = false;
    int jump = maze[x][y];

    if (searchLongestPath(maze, solution, x, y + jump, maxLength, currentLength, numsSize, bestSolution))
        pathFound = true;
    if (searchLongestPath(maze, solution, x, y - jump, maxLength, currentLength, numsSize, bestSolution))
        pathFound = true;
    if (searchLongestPath(maze, solution, x + jump, y, maxLength, currentLength, numsSize, bestSolution))
        pathFound = true;
    if (searchLongestPath(maze, solution, x - jump, y, maxLength, currentLength, numsSize, bestSolution))
        pathFound = true;

    solution[x][y] = 0;

    return pathFound;
}

void runTests()
{
    // Test case 1
    int maze1[4][4] = {
        {3, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 1, 1}};
    int *mazePtr1[4] = {maze1[0], maze1[1], maze1[2], maze1[3]};
    int **mazeTest1 = mazePtr1;

    int solution1[4][4] = {};
    int *solutionPtr1[4] = {solution1[0], solution1[1], solution1[2], solution1[3]};
    int **solutionTest1 = solutionPtr1;

    int bestSolution1[4][4] = {};
    int *bestSolutionPtr1[4] = {bestSolution1[0], bestSolution1[1], bestSolution1[2], bestSolution1[3]};
    int **bestSolutionTest1 = bestSolutionPtr1;

    int maxLength1 = 0;
    assert(searchLongestPath(mazeTest1, solutionTest1, 0, 0, maxLength1, 0, 4, bestSolutionTest1) == true);
    assert(maxLength1 == 7);

    // Test case 2
    int maze2[4][4] = {
        {3, 0, 0, 0},
        {2, 0, 0, 1},
        {1, 0, 3, 1},
        {1, 1, 1, 1}};
    int *mazePtr2[4] = {maze2[0], maze2[1], maze2[2], maze2[3]};
    int **mazeTest2 = mazePtr2;

    int solution2[4][4] = {};
    int *solutionPtr2[4] = {solution2[0], solution2[1], solution2[2], solution2[3]};
    int **solutionTest2 = solutionPtr2;

    int bestSolution2[4][4] = {};
    int *bestSolutionPtr2[4] = {bestSolution2[0], bestSolution2[1], bestSolution2[2], bestSolution2[3]};
    int **bestSolutionTest2 = bestSolutionPtr2;

    int maxLength2 = 0;
    assert(searchLongestPath(mazeTest2, solutionTest2, 0, 0, maxLength2, 0, 4, bestSolutionTest2) == true);
    assert(maxLength2 == 10);

    // Test case 3: No possible path
    int maze3[4][4] = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 1}};
    int *mazePtr3[4] = {maze3[0], maze3[1], maze3[2], maze3[3]};
    int **mazeTest3 = mazePtr3;

    int solution3[4][4] = {};
    int *solutionPtr3[4] = {solution3[0], solution3[1], solution3[2], solution3[3]};
    int **solutionTest3 = solutionPtr3;

    int bestSolution3[4][4] = {};
    int *bestSolutionPtr3[4] = {bestSolution3[0], bestSolution3[1], bestSolution3[2], bestSolution3[3]};
    int **bestSolutionTest3 = bestSolutionPtr3;

    int maxLength3 = 0;
    assert(searchLongestPath(mazeTest3, solutionTest3, 0, 0, maxLength3, 0, 4, bestSolutionTest3) == false);
    assert(maxLength3 == 0);

    // Test case 4: Single cell maze
    int maze4[1][1] = {{1}};
    int *mazePtr4[1] = {maze4[0]};
    int **mazeTest4 = mazePtr4;

    int solution4[1][1] = {{0}};
    int *solutionPtr4[1] = {solution4[0]};
    int **solutionTest4 = solutionPtr4;

    int bestSolution4[1][1] = {{0}};
    int *bestSolutionPtr4[1] = {bestSolution4[0]};
    int **bestSolutionTest4 = bestSolutionPtr4;

    int maxLength4 = 0;
    assert(searchLongestPath(mazeTest4, solutionTest4, 0, 0, maxLength4, 0, 1, bestSolutionTest4) == true);
    assert(maxLength4 == 1);

    // Test case 5: Path through entire grid with jumps
    int maze5[4][4] = {
        {2, 0, 0, 0},
        {1, 2, 0, 0},
        {0, 1, 2, 0},
        {0, 0, 1, 1}};
    int *mazePtr5[4] = {maze5[0], maze5[1], maze5[2], maze5[3]};
    int **mazeTest5 = mazePtr5;

    int solution5[4][4] = {};
    int *solutionPtr5[4] = {solution5[0], solution5[1], solution5[2], solution5[3]};
    int **solutionTest5 = solutionPtr5;

    int bestSolution5[4][4] = {};
    int *bestSolutionPtr5[4] = {bestSolution5[0], bestSolution5[1], bestSolution5[2], bestSolution5[3]};
    int **bestSolutionTest5 = bestSolutionPtr5;

    int maxLength5 = 0;
    assert(searchLongestPath(mazeTest5, solutionTest5, 0, 0, maxLength5, 0, 4, bestSolutionTest5) == true);
    assert(maxLength5 == 7);

    // Add more test cases as needed

    cout << "All tests passed!" << endl;
}

int main()
{
    runTests();
    return 0;
}
