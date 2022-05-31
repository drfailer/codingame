#include<stdio.h>
#include<stdlib.h>

int folloWall(char **map,int orientation,int wall,int x,int y,int h,int w,int save[2],int count){
  if(orientation>4){
    orientation=1;
  }
  else if(orientation<1){
    orientation=4;
  }
  if(count<=4){
    if(orientation==1 && x<(w-1) && map[y][x+1]!='#'){
        count=0;
        x++;
    }
    else if(orientation==2 && y<(h-1) && map[y+1][x]!='#'){
	    count=0;
	    y++;
    }
    else if(orientation==3 && x>0 && map[y][x-1]!='#'){
        count=0;
        x--;
    }
    else if(orientation==4 && y>0 && map[y-1][x]!='#'){
        count=0;
        y--;
    }
    else{
        count++;
        orientation-=wall;
    }
    //Si count est nul, on vient de changer de case
    if(count==0){
      if(y!=save[0] || x!=save[1]){
	map[y][x]++;
	orientation+=wall;
      }
      else{
	map[y][x]='1';
	return 0;
      }
    }
    folloWall(map,orientation,wall,x,y,h,w,save,count);
  }
  else{
    map[y][x]='0';
  }
}

int main()
{
  int i,j;
  int h,w;
  int x,y;
  int save[2];
  int count=0;
  int orientation;
  char **map;
  char side[2];
  
  //input codingame
  scanf("%d%d",&w,&h);
  map=(char**) malloc(h*sizeof(char**));
  for(i=0;i<h;i++){
    map[i]=(char*) malloc(w*sizeof(char*));
    scanf("%s",map[i]);
  }
  scanf("%s",side);
  
  //find pickacha
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(map[i][j]!='#' && map[i][j]!='0'){
	y=i;
	x=j;
	switch(map[i][j]){
	case '>': orientation=1; break;
	case 'v': orientation=2; break;
	case '<': orientation=3; break;
	case '^': orientation=4; break;
	}
      }
    }
  }
    
  //code
  save[0]=y;
  save[1]=x;
  if(side[0]=='R'){
    folloWall(map,orientation+1,1,x,y,h,w,save,count);
  }
  else{
    folloWall(map,orientation-1,-1,x,y,h,w,save,count);
  }
  
  //Show final tab
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      printf("%c",map[i][j]);
    }
    printf("\n");
  }
  free(map);
  return 0;
}
