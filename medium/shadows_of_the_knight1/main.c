#include <stdio.h>

int main()
{
    int x,y;
    int row[2]={0};
    int col[2]={0};
    // width of the building.
    int W;
    // height of the building.
    int H;
    scanf("%d%d", &W, &H);
    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);
    //Start position
    scanf("%d%d", &x, &y);
    row[1]=H;
    col[1]=W;
    // game loop
    while (1){
        char bomb_dir[4];  
        scanf("%s", bomb_dir);

	    //Column
	    if(bomb_dir[1]=='R' || bomb_dir[0]=='R'){
	        col[0]=x;
	    }
	    else if(bomb_dir[1]=='L' || bomb_dir[0]=='L'){
	        col[1]=x;
	    }
        x=((col[0]+col[1])/2);

	    //Row
	    if(bomb_dir[0]=='U'){
	        row[1]=y;
	    }
	    else if(bomb_dir[0]=='D'){
	        row[0]=y;
	    }
        y=((row[0]+row[1])/2);

        // the location of the next window Batman should jump to.
        printf("%d %d\n",x,y);
    }
    return 0;
}
