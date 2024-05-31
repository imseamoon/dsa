#ifndef MAZE_H
#define MAZE_H

bool isValid(int **maze, int **solution, int x, int y, int numsSize);
bool searchLongestPath(int **maze, int **solution, int x, int y, int &maxLength, int currentLength, int numsSize, int **bestSolution);
void runTests();

#endif // MAZE_H
