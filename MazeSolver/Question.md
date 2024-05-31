# Maze exploration using recursive function

A Maze is given as N\*N binary matrix of blocks where source block is the upper left most block
i.e., `maze[0][0]` and destination block is lower rightmost block i.e., `maze[N 1][N-1]`. A rat starts
from the source and has to reach the destination. The rat can move in four directions (i.e., left,
right, up or down).

In the maze matrix, 0 means the block is a dead end and non-zero means the block can be used in
the path from source to destination, where non-zero value indicates the number of maximum
jumps the rat can make from the cell `maze[i][j]`. Also, a weight is applied to each cell in the path
that is not dead-block, source or destination. The cell weight is set to be 1. Backtracking is an
algorithmic technique for solving problems recursively by trying to build a solution incrementally
in maze exploration.
