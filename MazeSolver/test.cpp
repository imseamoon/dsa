#include "maze.h"
#include <cassert>
#include <iostream>

using namespace std;

void printSolution(int **solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

void test1()
{
    int n = 4;
    int **maze = new int *[n];
    for (int i = 0; i < n; i++)
        maze[i] = new int[n]{};

    int **solution = new int *[n];
    for (int i = 0; i < n; i++)
        solution[i] = new int[n]{};

    int inputMaze[4][4] = {
        {2, 0, 1, 3},
        {3, 1, 0, 1},
        {1, 3, 1, 0},
        {0, 2, 1, 1}};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            maze[i][j] = inputMaze[i][j];

    int maxLength = 0;
    bool pathExists = searchLongestPath(maze, solution, 0, 0, maxLength, 1, n);

    cout << "Test 1: Path exists: " << pathExists << ", Max length: " << maxLength << endl;
    printSolution(solution, n);

    assert(pathExists);
    assert(maxLength == 7);

    int expectedSolution[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1}};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            assert(solution[i][j] == expectedSolution[i][j]);

    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
        delete[] solution[i];
    }
    delete[] maze;
    delete[] solution;
}

void test2()
{
    int n = 3;
    int **maze = new int *[n];
    for (int i = 0; i < n; i++)
        maze[i] = new int[n]{};

    int **solution = new int *[n];
    for (int i = 0; i < n; i++)
        solution[i] = new int[n]{};

    int inputMaze[3][3] = {
        {1, 2, 3},
        {0, 0, 2},
        {1, 1, 1}};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            maze[i][j] = inputMaze[i][j];

    int maxLength = 0;
    bool pathExists = searchLongestPath(maze, solution, 0, 0, maxLength, 1, n);

    cout << "Test 2: Path exists: " << pathExists << ", Max length: " << maxLength << endl;
    printSolution(solution, n);

    assert(!pathExists);
    assert(maxLength == 0);

    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
        delete[] solution[i];
    }
    delete[] maze;
    delete[] solution;
}

int main()
{
    test1();
    test2();

    cout << "All tests passed!" << endl;

    return 0;
}
