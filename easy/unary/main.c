#include <stdio.h>

int main()
{
    int i,j;
    int last=-1;
    char MESSAGE[101];
    fgets(MESSAGE, 101, stdin);
    for(i=0; (MESSAGE[i]!='\0' && MESSAGE[i]!='\n'); i++){
        for(j=6;j>=0;j--){
            if(last!=(MESSAGE[i]>>j)%2){
                if(last!=-1)
                    printf(" ");
                ((MESSAGE[i]>>j)%2)? printf("0 "):printf("00 ");
            }
            last=(MESSAGE[i]>>j)%2;
            printf("0");
        }
    }
    return 0;
}
