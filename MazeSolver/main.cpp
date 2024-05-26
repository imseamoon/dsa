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

int main()
{
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    int **maze = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
    }

    int **solution = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }

    int **bestSolution = new int *[n];
    for (int i = 0; i < n; i++)
    {
        bestSolution[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solution[i][j] = 0;
            bestSolution[i][j] = 0;
        }
    }

    cout << "Enter the maze values (row-wise): " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    int maxLength = 0;

    if (searchLongestPath(maze, solution, 0, 0, maxLength, 0, n, bestSolution))
    {
        cout << "Longest Path Length: " << maxLength << endl;
    }
    else
    {
        cout << "No path exists." << endl;
    }

    cout << "Solution Path:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << bestSolution[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
        delete[] solution[i];
        delete[] bestSolution[i];
    }
    delete[] maze;
    delete[] solution;
    delete[] bestSolution;

    return 0;
}
