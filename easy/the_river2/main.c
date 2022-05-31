#include <stdio.h>

int s(int n){
  int div=n;
  do{
    n+=div%10;
  }while(div/=10);
  return n;
}

int main()
{
  int i,r1,r2;
  scanf("%d", &r1);
  i=r1-1;
  do{
    r2=s(i);
  }while(i-- && r2!=r1 && r2>0.75*r1);
  (r2==r1)? printf("YES\n"):printf("NO\n");
  return 0;
}
