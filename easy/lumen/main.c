#include <stdlib.h>
#include <stdio.h>

void lightSet(char **map,int N,int x,int y,int L,int lumCase){
  int i;
  if(map[y][x]=='X'){
    map[y][x]='0';
  }
  for(i=1;i<L;i++){
    if((y-i)>=0 && map[y-i][x]=='X'){
      map[y-i][x]='0';
    }
    if((y+i)<N && map[y+i][x]=='X'){
      map[y+i][x]='0';
    }
    if(lumCase>1){
      if((x-2)>=0){
	    lightSet(map,N,x-2,y,L,lumCase-1);
      }
      if((x+2)<=(2*N-1)){
	    lightSet(map,N,x+2,y,L,lumCase-1);
      }
    }
  }
}

int main()
{
    int i,j;
    int count=0;
    int N,L;
    char **map;
    scanf("%d", &N);
    //----------------------------------------------
    map=(char**) malloc(N*sizeof(map));
    for(i=0;i<N;i++){
      map[i]=(char*) malloc((2*N)*sizeof(map[i]));
    }
    //----------------------------------------------
    scanf("%d", &L);
    fgetc(stdin);
    for (i=0;i<N;i++){
      fgets(map[i],501,stdin);
    }
    //----------------------------------------------
    for(i=0;i<N;i++){
      for(j=0;j<(2*N-1);j++){
	    if(map[i][j]=='C'){
	        lightSet(map,N,j,i,L,L);
	    }
      }
    }
    for(i=0;i<N;i++){
      for(j=0;j<(2*N-1);j++){
	    if(map[i][j]=='X'){
	        count++;
	    }
      }
    }
    printf("%d",count);
    for(i=0;i<N;i++){
      free(map[i]);
    }
    free(map);
    map=NULL;
    return 0;
}
