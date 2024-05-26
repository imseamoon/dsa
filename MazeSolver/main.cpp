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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solution[i][j] = 0;
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

    if (searchLongestPath(maze, solution, 0, 0, maxLength, 1, n))
    {
        cout << "Longest Path Length: " << maxLength << endl;
    }
    else
    {
        cout << "No path exists." << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << solution[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
        delete[] solution[i];
    }
    delete[] maze;
    delete[] solution;

    return 0;
}
