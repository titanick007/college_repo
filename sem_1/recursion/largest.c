#include <stdio.h>
#include <stdlib.h>
void max(int *a,int n, int big){
  if(n<0) printf("%d\n",big);
  if(big> *a) {
    big=*a;
    return max(++a,n-1,big);
  }
}
int main(){
  int n;
  printf("Enter no. of elements\n");scanf("%d",&n);
  int a[n];
  int *p=a;
  for(int i=0;i<n;++i){
    scanf("%d",&a[i]);
  }
  max(p,n,a[0]);
  return 0;
}