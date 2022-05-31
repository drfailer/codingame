#include <stdio.h>

int main()
{
    int i,j;
    int count;
    int width;
    int height;
    char tab[256][256];
    //codingame input
    scanf("%d%d", &width, &height);
    for (i=0;i<height;i++){
        scanf("%s", tab[i]);
    }
    //Code
    for (i=0;i<height;i++){
        for(j=0;j<width;j++){
            count=0;
            if(tab[i][j]!='#'){
	            if(i>0 && tab[i-1][j]=='0'){
	                count++;
	            }
	            if(i<height && tab[i+1][j]=='0'){
	                count++;
                }
	            if(j>0 && tab[i][j-1]=='0'){
           	        count++;
           	    }
           	    if(j<width && tab[i][j+1]=='0'){
	                count++;
                }
        	    printf("%d",count);
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}
