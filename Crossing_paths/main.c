#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Coordinate;

unsigned long hashCoordinate(const Coordinate *c)
{
    return (unsigned long)(c->x * 1000000007 + c->y);
}

bool contains(Coordinate *visited, int size, Coordinate c)
{
    for (int i = 0; i < size; i++)
    {
        if (visited[i].x == c.x && visited[i].y == c.y)
        {
            return true;
        }
    }
    return false;
}

void add(Coordinate *visited, int *size, Coordinate c, int capacity)
{
    if (*size == capacity)
    {
        capacity *= 2;
        visited = realloc(visited, capacity * sizeof(Coordinate));
    }
    visited[*size] = c;
    (*size)++;
}

bool isPathCrossing(char *path)
{
    int x = 0, y = 0;

    int capacity = 10000;
    int size = 0;
    Coordinate *visited = malloc(capacity * sizeof(Coordinate));

    Coordinate start = {0, 0};
    add(visited, &size, start, capacity);

    for (int i = 0; path[i] != '\0'; i++)
    {
        switch (path[i])
        {
        case 'N':
            y += 1;
            break;
        case 'S':
            y -= 1;
            break;
        case 'E':
            x += 1;
            break;
        case 'W':
            x -= 1;
            break;
        }

        Coordinate current = {x, y};
        if (contains(visited, size, current))
        {
            free(visited);
            return true;
        }

        add(visited, &size, current, capacity);
    }

    free(visited);
    return false;
}

int main(int argc, char const *argv[])
{
    char *path = "NES";
    printf("%d\n", isPathCrossing(path)); // 0

    path = "NESWW";
    printf("%d\n", isPathCrossing(path)); // 1

    return 0;
}