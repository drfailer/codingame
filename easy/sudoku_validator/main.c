#include <stdio.h>

int main()
{
    int i, j, k, l;
    int x, y, xComp, yComp;
    int map[9][9];
    int result = 1;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    for(i = 0;i < 9 && result;i++) {
        for(j = 0; j < 9 && result; j++) {

            // Checking columns and rows:
            for (k = j+1; k < 9; k++) {
                if (map[i][j] == map[i][k] || map[j][i] == map[k][i])
                    result = 0;
            }

            // Checking subgrids:
            for (k = (i%3); k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    if (i%3 != k || j%3 != l) {
                        y = 3*(i/3) + (i%3);  yComp = 3*(i/3) + k;
                        x = 3*(j/3) + (j%3);  xComp = 3*(j/3) + l;
                        if (map[y][x] == map[yComp][xComp])
                            result = 0;
                    }   
                }
            }

        }
    }
    printf("%s\n", result? "true":"false");
    return 0;
}
