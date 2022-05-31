#include <stdlib.h>
#include <stdio.h>

int findRight(char ** map, int x, int y, int w)
{
    int found = -1;
    while (++x < w && found == -1) {
        if (map[y][x] == '0')
            found = x;
    }
    return found;
}

int findDown(char ** map, int x, int y, int h)
{
    int found = -1;
    while (++y < h && found == -1) {
        if (map[y][x] == '0')
            found = y;
    }
    return found;
}

void findNeighbors(char ** map, int neighbors[3][2], int x, int y, int h, int w)
{
    neighbors[0][0] = x; neighbors[0][1] = y;
    neighbors[1][1] = ((neighbors[1][0] = findRight(map, x, y, w)) == -1) ? -1 : y;
    neighbors[2][0] = ((neighbors[2][1] = findDown(map, x, y, h)) == -1) ? -1 : x;
}

void printNeighbors(int neighbors[3][2])
{
    int i;
    for (i = 0; i < 2; ++i)
        printf("%d %d ", neighbors[i][0], neighbors[i][1]);
    printf("%d %d\n", neighbors[2][0], neighbors[2][1]);
}

int main()
{
    int i, j;
    int neighbors[3][2];
    int width, height;
    char ** map = (char**) malloc(height*sizeof(char*));

    scanf("%d", &width);
    scanf("%d", &height); fgetc(stdin);
    if (map) {
        for (i = 0; i <  height; ++i) {
            map[i] = (char*) malloc(width*sizeof(char));
            if (map[i] == NULL)
                exit(1);
        }

        // get the map
        for (int i = 0; i < height; i++) {
            // width characters, each either 0 or .
            scanf("%[^\n]", map[i]); fgetc(stdin);
        }

        // find and display neighbors
        for (i = 0; i < height; ++i) {
            for (j = 0; j < width; ++j) {
                if (map[i][j] == '0') {
                    findNeighbors(map, neighbors, j, i, height, width);
                    printNeighbors(neighbors);
                }
            }
        }
    }

    return 0;
}
