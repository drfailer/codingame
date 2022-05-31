#include <stdio.h>

int s(int n){
  int div=n;
  do{
    n+=div%10;
  }while(div/=10);
  return n;
}

int main() {
    long long r1,r2;
    scanf("%lld%lld", &r1,&r2);
    while(r1!=r2){
        if(r1<r2)  r1=s(r1); // r1 < r2
        else       r2=s(r2); // r2 < r1
    }
    printf("%lld\n",r1);
    return 0;
}
