#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int higherIndex(int m[8])
{
    int i, max = m[0], imax = 0;
    for (i = 0; i < 8; ++i) {
        if (m[i] > max) {
            imax = i;
            max = m[i];
        }
    }
    return imax;
}

int main()
{
    int mountains[8];
    // game loop
    while (1) {
        for (int i = 0; i < 8; i++) {
            // represents the height of one mountain.
            int mountain_h;
            scanf("%d", &mountain_h);
            mountains[i] = mountain_h;
        }
        printf("%d\n", higherIndex(mountains)); // The index of the mountain to fire on.
    }

    return 0;
}
